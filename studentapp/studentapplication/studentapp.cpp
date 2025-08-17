#include <iostream>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

struct Student {
    string name;
    string accommodation;
    string tutor;
    bool hasExtraCredits = false;
    string extraCourse;
    string program;
    bool verified = false;
    bool needsVisa = false;
    bool visaApplied = false;
    bool feePaid = false;
    bool wantsAccommodation = false;
    
};

void clearLine() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool askYesNo(const string& prompt) {
    while (true) {
        cout << prompt << " (y/n): ";
        char c;
        if (!(cin >> c)) { clearLine(); continue; }
        c = tolower(c);
        if (c == 'y') return true;
        if (c == 'n') return false;
        cout << "Please enter(y/n)" << endl;
    }
}

string askLine(const string& prompt) {
    cout << prompt;
    string s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);
    return s;
}

void Registration(Student& s) {
    cout << "\n=== Registration Form ===\n";
    if (s.name.empty())     s.name    = askLine("Enter student name: ");
    if (s.program.empty())  s.program = askLine("Enter department: ");

    cout << "Registration process initiated" << endl;
    cout << "Form sent to corresponding departments" << endl;
    cout << "Saved to Student Information DB" << endl;
}

void AdmissionOffice(Student& s) {
    cout << "\n=== Admission Office Verification ===\n";
    cout << "Received form for " << s.name << " (" << s.program << ")\n";
    do {
        cout << "Checking details...\n";
        s.verified = askYesNo("Are the details verified?");
        if (!s.verified) {
            cout << "Return form for correction. Please correct the details.\n";
            if (askYesNo("Edit name?"))     s.name    = askLine("New name: ");
            if (askYesNo("Edit program?"))  s.program = askLine("New program: ");
        }
    } while (!s.verified);
    cout << "Verified successfully" << endl;;
}

void Visa(Student& s) {
    cout << "\n=== Visa Section ===\n";
    s.needsVisa = askYesNo("Does the student need a visa?");
    if (s.needsVisa) {
        cout << "Informing student to apply for visa" << endl;
        do {
            s.visaApplied = askYesNo("Has the visa been applied?");
            if (!s.visaApplied) cout << "Waiting for visa application" << endl;
        } while (!s.visaApplied);
        cout << "Visa application acknowledged" << endl;
    } else {
        cout << "No visa required" << endl;
    }
}

void TuitionFee(Student& s) {
    cout << "\n=== Tuition Fee Section ===\n";
    cout << "Student proceeds with fee payment" << endl;;
    do {
        s.feePaid = askYesNo("Has the fee been paid?");
        if (!s.feePaid) cout << "Waiting for payment" << endl;;
    } while (!s.feePaid);
    cout << "Payment confirmed" << endl;;
}

void Accommodation(Student& s) {
    cout << "\n=== Accommodation Section ===\n";
    s.wantsAccommodation = askYesNo("Does the student want accommodation?");
    if (s.wantsAccommodation) {
        s.accommodation = askLine("Assign accommodation (room/hostel): ");
        cout << "Accommodation assigned: " << s.accommodation << "\n";
    } else {
        cout << "No accommodation requested" << endl;
    }
}

void PersonalTutor(Student& s) {
    cout << "\n=== Personal Tutor Assignment ===\n";
    if (s.tutor.empty())
        s.tutor = askLine("Assign tutor (enter tutor name): ");
    cout << "Student meets Personal Tutor: " << s.tutor << ".\n";
}

void ExtraCourse(Student& s) {
    cout << "\n=== Extra Course Selection ===\n";
    s.hasExtraCredits = askYesNo("Does the student have extra credits?");
    if (s.hasExtraCredits) {
        s.extraCourse = askLine("Enter name of additional course: ");
        cout << "Additional course chosen: " << s.extraCourse << "\n";
    } else {
        cout << "No extra course selected" << endl;
    }
}

void FullyRegistered(const Student& s) {
    cout << "\n=== Fully Registered Summary ===\n";
    cout << "Completed Registration for " << s.name << " (" << s.program << ")\n";
    cout << "Summary:\n";
    cout << " Verified: " << (s.verified ? "Yes" : "No") << "\n";
    cout << " Visa: " << (s.needsVisa ? (s.visaApplied ? "Applied" : "Required (not applied)") : "Not required") << "\n";
    cout << " Fee Paid: " << (s.feePaid ? "Yes" : "No") << "\n";
    cout << " Accommodation: " << (s.wantsAccommodation ? s.accommodation : "Not requested") << "\n";
    cout << " Tutor: " << (!s.tutor.empty() ? s.tutor : "Not assigned") << "\n";
    cout << " Extra Course: " << (s.hasExtraCredits ? s.extraCourse : "None") << "\n";
    cout << "Registration process completed.\n";
}

void DB(const Student& s) {
    bool writeHeader = false;

    // Check if file exists or is empty
    ifstream check("students.csv");
    if (!check.good() || check.peek() == ifstream::traits_type::eof()) {
        writeHeader = true;
    }
    check.close();

    ofstream db("students.csv", ios::app);
    if (!db) {
        cerr << "Error opening database file!" << endl;
        return;
    }

    if (writeHeader) {
        db << "Name,Department,Verified,Visa,FeePaid,Accommodation,Tutor,ExtraCourse" << endl;
    }

    db << s.name << ","
       << s.program << ","
       << (s.verified ? "Yes" : "No") << ","
       << (s.needsVisa ? (s.visaApplied ? "Applied" : "Required") : "Not required") << ","
       << (s.feePaid ? "Yes" : "No") << ","
       << (s.wantsAccommodation ? s.accommodation : "Not requested") << ","
       << (!s.tutor.empty() ? s.tutor : "Not assigned") << ","
       << (s.hasExtraCredits ? s.extraCourse : "None") << "\n";

    db.close();
    cout << "Student data saved to DB (students.csv)" << endl;
}

int main() {
    Student s;

    Registration(s);
    AdmissionOffice(s);
    Visa(s);
    TuitionFee(s);
    Accommodation(s);
    PersonalTutor(s);
    ExtraCourse(s);
    FullyRegistered(s);
    DB(s);

    return 0;
}
