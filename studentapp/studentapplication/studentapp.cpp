#include <iostream>
#include <fstream>
using namespace std;

/
string database = "student.csv";
fstream fout;
int age;
string name, location, gender;

void registration();
void verification();
void database();
void visa();
void tuitionfees();
void accommodation();
void assignTutor();
void finalize();


void registration() {
    cout << "Registeration" << endl;
    
    cout << "Enter Name: ";
    cin >> name; << endl;

    cout << "Enter Age: " << endl;;
    cin >> age;

    cout << "Enter location: " << endl;;
    cin >> location;

    cout << "Enter Gender: " << endl;;
    cin >> gender;

    verification();
}


void verification() {
    cout << "Verification" << endl;
    cout << "Verify it by the admission committee\n";
    string verify;
    cout << "Did you verify the data? (yes/no): ";
    cin >> verify;

    if (verify == "yes") {
        cout << "Data verified successfully.\n";
        database();
    } else {
        cout << "Please re-enter the data.\n";
        registration();
    }
}


void database() {
    cout << "Storing data in the database";
    cout << "Sending the data to respective departments" << endl

    fout.open(database, ios::out | ios::app);
    if (!fout) {
        cerr << "Error opening database file" << endl;
        return;
    }
    fout << name << "," << age << "," << location << "," << gender << "\n";
    fout.close();

    cout << "Data saved successfully" << endl
    visa();
}


void visa() {
    cout << "Visa";

    cout << "Visa process started" << endl;
    string required, applied;

    cout << "Do you required a visa? (yes/no): ";
    cin >> required;

    if (required == "yes") {
        cout << "Inform student about visa requirements" << endl;
        while (true) {
            cout << "Have you applied for the visa? (yes/no): " << endl;
            cin >> applied;
            if (applied == "yes") {
                cout << "Visa application is in process" << endl;
                tuitionfees();
                break;
            } else {
                cout << "Please apply for the visa" << endl;
            }
        }
    } else {
        tuitionfees();
    }
}

void tuitionfees() {
    cout << "Tutition fees";

    cout << "Pay the tuition fees" << endl
    while (true) {
        string fees;
        cout << "Have you paid the tuition fees? (yes/no): ";
        cin >> fees;

        if (fees == "yes") {
            cout << "Tuition fees paid successfully.\n";
            accommodation();
            break;
        } else {
            cout << "Please pay the tuition fees.\n";
        }
    }
}



void accommodation() {
    cout << "Accomodation";

    string required;
    cout << "Do you required accommodation? (yes/no): ";
    cin >> required;

    if (required == "yes") {
        cout << "Assign the accommodation.\n";
    } else {
        cout << "No accommodation requireded.\n";
    }

    assignTutor();
}

// Assign Tutor
void assignTutor() {
    cout << "\n-----------------------\n";
    cout << "ASSIGN TUTOR PROCESS\n";

    cout << "Assign a personal tutor for the student.\n";
    cout << "Meet the tutor and discuss the course details.\n";

    string credit;
    cout << "Does the student have extra credits? (yes/no): ";
    cin >> credit;

    if (credit == "yes") {
        cout << "Choose the extra credit courses.\n";
    } else {
        cout << "No extra credits assigned.\n";
    }

    finalize();
}

// Finalize Process
void finalize() {
    cout << "\n-----------------------\n";
    cout << "FINALIZE PROCESS\n";

    cout << "Finalizing the student admission process.\n";
    cout << "Thank you for completing the registration.\n";
}
