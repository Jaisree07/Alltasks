#include <iostream>
#include <string>
#include <limits>
#include <fstream>
using namespace std;
 
 
string getInput(const string& message) {
    cout << message;
   
    string input;
    getline(cin, input);
    return input;
}
 
bool choice(const string& message) {
    while (true) {
        cout << message << " (y/n): ";
        char response;
        if (!(cin >> response)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        response = tolower(response);
        if (response == 'y'){
            return true;
        }
        if (response == 'n'){
              return false;
        }
           
    }
 
}
void login(string &password) {
    string entered;
    bool success = false;
 
    do {
        cout << "Enter password: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        getline(cin, entered);
        string enter = entered;
       
        if (enter == password) {
            cout << "Login successful\n";
            success = true;
        } else {
            cout << "Incorrect password\n";
            if (choice("Forgot password?")) {
                password = getInput("Set new password: ");
                cout << "Password reset successful" << endl;
            }
        }
    } while (!success);
 
    cout << "Looking for desired vehicle\n";
    cout << "Making payment" << endl;
    cout << "Logout complete" << endl;
}
 
 
void saveUserToCSV(const string& name, const string& email, const string& password) {
    ofstream file("users.csv", ios::app);
    if (!file) {
        cerr << "Error" << endl;
        return;
    }
    file << name << "," << email << "," << password << "\n";
    file.close();
    cout << "User details saved in DB (users.csv)" << endl;
}
 
 
 
void newuser() {
    cout << "New User Registration" << endl;
    string name = getInput("Enter name: ");
    cin.ignore();
    string email = getInput("Enter email: ");
    cin.ignore();
    string pass  = getInput("Set password: ");
    cin.ignore();

    saveUserToCSV(name, email, pass);
 
    cout << "Registration Completed ";
 
    cout << "Proceed to login\n";
    login(pass);
}
 
void registeredusers() {
    if(choice("RegisteredUser")){
         string pass = getInput("password");
        login(pass);
    }
    else{
       newuser();
    }
}
 
 
void Chooseapplication() {
    bool loop = true;
 
    while (loop) {
        cout << "1. Update car library" << endl;
        cout << "2. Answer customer enquiries" << endl;
        cout << "3. Logout" << endl;
        cout << "Choose action: ";
        int ch;
        cin >> ch;
 
        switch (ch) {
            case 1:
                cout << "Car library updated successfully" << endl;
                break;
            case 2:
                cout << "Customer enquiries answered" << endl;
                break;
            case 3:
                cout << "Logging out" << endl;
                loop = false;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    
    }
}
 
 
void admin() {
    cout << " Admin Login" << endl;
    string password; 
    string correct = "908";
 
    bool loggedIn = false;
    do {
        cout << "Enter admin password" << endl;
        cin >> password;
        if (password == correct) {
            cout << "Login successful" << endl;
            loggedIn = true;
        } else {
            cout << "Login failed" << endl;
        }
    } while (!loggedIn);
 
    Chooseapplication();
}
 
 
 
int main() {
    cout << "Car Rental System" << endl;
    cout << "User(1=Admin, 2=Registered User): ";
    int choice;
    cin >> choice;
 
    switch (choice) {
        case 1:
         admin(); 
         break;          
        case 2: 
        registeredusers();
         break;
       default: cout << "Invalid choice" << endl;
    }
    return 0;
}