#include <iostream>
#include <fstream>
using namespace std;


string database = "student.csv";
fstream fout;
int age;
string name, location, gender;

void registration();
void verification();
void data();
void visa();
void tuitionfees();
void accommodation();
void assignTutor();
void thend();

void registration() {
    cout << "Registeration" << endl;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: " << endl;;
    cin >> age;
    cout << "Enter location: " << endl;;
    cin >> location;
    cout << "Enter Gender: " << endl;;
    cin >> gender;
    verification();
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



void data() {
    cout << "Storing data in the database";
    cout << "Sending the data to respective departments" << endl;

    fout.open(database, ios::out | ios::app);
    if (!fout) {
        cerr << "Error opening database file" << endl;
        return;
    }
    fout << name << "," << age << "," << location << "," << gender << "\n";
    fout.close();

    cout << "Data saved successfully" << endl;
    visa();
}


void verification() {
    cout << "Verification" << endl;
    cout << "Verify it by the admission committee" << endl;
    string verify;
    cout << "Did you verify the data? (yes/no): " << endl;
    cin >> verify;

    if (verify == "yes") {
        cout << "Data verified successfully" << endl;
        data();
    } else {
        cout << "Please re-enter the data" << endl;
        registration();
    }
}



void tuitionfees() {
    cout << "Tutition fees";

    cout << "Pay the tuition fees" << endl;
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
        cout << "Assign the accommodation" << endl;
    } else {
        cout << "No accommodation requireded" << endl;
    }

    assignTutor();
}


void assignTutor() {
    cout << "Assiging tutor";

    cout << "Assign a personal tutor for the student" << endl;
    cout << "Meet the tutor and discuss the course details" << endl;

    string credit;
    cout << "Does the student have extra credits? (yes/no): " << endl;
    cin >> credit;

    if (credit == "yes") {
        cout << "Choose the extra credit courses" << endl;
    } else {
        cout << "No extra credits assigned" << endl;
    }

    thend();
}


void thend() {
    cout << "Finalizing";

    cout << "Finalizing the student admission process" << endl;
    cout << "Thank you for completing the registration" << endl;
}


int main() {
    registration();
    return 0;
}