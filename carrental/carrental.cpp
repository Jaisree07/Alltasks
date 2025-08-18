// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include <vector>
// using namespace std;

// struct User {
//     string username;
//     string password;
// };

// vector<User> loadUsers(const string &filename) {
//     vector<User> users;
//     ifstream file(filename);

//     if (!file.is_open()) {
//         cerr << "Error: Could not open " << filename << endl;
//         return users;
//     }

//     string line, username, pass;
//     while (getline(file, line)) {
//         stringstream ss(line);
//         getline(ss, username, ',');
//         getline(ss, pass, ',');
//         if (!username.empty() && !pass.empty()) {
//             users.push_back({username, pass});
//         }
//     }
//     file.close();
//     return users;
// }

// // Function to update password in CSV
// void updatePassword(const string &filename, const string &username, const string &newpass) {
//     vector<User> users = loadUsers(filename);
//     ofstream file(filename, ios::trunc);

//     if (!file.is_open()) {
//         cerr << "Error: Could not write to " << filename << endl;
//         return;
//     }

//     for (auto &u : users) {
//         if (u.username == username) {
//             u.password = newpass;
//         }
//         file << u.username << "," << u.password << endl;
//     }
//     file.close();
// }

// bool login(const vector<User> &users, const string &username, const string &pass) {
//     for (const auto &u : users) {
//         if (u.username == username && u.password == pass) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     string dbFile = "users.csv";
//     vector<User> users = loadUsers(dbFile);

//     cout << "Login System" << endl;
//     cout << "Are you Admin (A) or Registered User (R)? : " << endl;
//     char choice;
//     cin >> choice;

//     if (choice == 'A' || choice == 'a') {
//         string username, pass;
//         cout << "Enter Admin username: ";
//         cin >> username;
//         cout << "Enter Admin password: ";
//         cin >> pass;

//         if (login(users, username, pass) && username == "admin") {
//             cout << "Admin login successful" << endl;
//             cout << "Admin can update all data here" << endl;
//         } else {
//             cout << "Admin login failed" << endl;
//         }
//     }
//     else if (choice == 'R' || choice == 'r') {
//         string username, pass;
//         cout << "Enter Username: ";
//         cin >> username;
//         cout << "Enter Password: ";
//         cin >> pass;

//         if (login(users, username, pass)) {
//             cout << "User login successful" << endl;
//             cout << "Welcome " << username << endl;
//         } else {
//             cout << "Invalid credentials!" << endl;
//             cout << "Forgot Password? (Y/N): ";
//             char fp;
//             cin >> fp;
//             if (fp == 'Y' || fp == 'y') {
//                 string newpass;
//                 cout << "Enter new password: ";
//                 cin >> newpass;
//                 updatePassword(dbFile, username, newpass);
//                 cout << "Password updated successfully" << endl;
//             } else {
//                 cout << "Returning to main menu" << endl;
//             }
//         }
//     }
//     else {
//         cout << "Invalid choice" << endl;
//     }

//     cout << "End" << endl;
//     return 0;
// }

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