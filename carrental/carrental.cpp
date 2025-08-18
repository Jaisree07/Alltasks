#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void forgotPassword();
void registeredUserlogin();
void adminlogin();

string database = "carrental.csv";
void forgotPassword() {
    cout << "Enter username: " << endl;
    string username;
    cin >> username;

    ifstream fin(database);
    ofstream temp("temp.csv");
    string line;
    bool found = false;

    while (getline(fin, line)) {
        size_t pos = line.find(",");
        string dbUser = line.substr(0, pos);
        string dbPass = line.substr(pos + 1);

        if (dbUser == username) {
            found = true;
            string newPass;
            cout << "User found" << endl;
            do {
                cout << "Enter new password (6 characters only):" << endl;
                cin >> newPass;
                if (newPass.length() != 6) {
                    cout << "Password must be exactly 6 characters" << endl;
                }
            } while (newPass.length() != 6);
            temp << dbUser << "," << newPass << endl;
        } else {
            temp << line << endl;
        }
    }

    fin.close();
    temp.close();
    remove(database.c_str());
    rename("new.csv", database.c_str());

    if (found)
        cout << "Password reset successful" << endl;
    else
        cout << "Username not found" << endl;
}


void registeredUserlogin() {
    cout << "Are you a registered user? (y/n): " << endl;
    char choice;
    cin >> choice;

    if (choice == 'y') {
        string username, password;
        int attempts = 3;
        bool success = false;

        while (attempts--) {
            cout << "Username: " << endl;
            cin >> username;
            cout << "Password: " << endl;
            cin >> password;

            ifstream fin(database);
            string line;
            bool found = false;

            while (getline(fin, line)) {
                size_t pos = line.find(",");
                string dbUser = line.substr(0, pos);
                string dbPass = line.substr(pos + 1);
                if (dbUser == username && dbPass == password) {
                    found = true;
                    break;
                }
            }

            fin.close();

            if (found) {
                cout << "Login successful" << endl;
                cout << "Look for desired vehicle" << endl;
                cout << "Make payment" << endl;
                success = true;
                break;
            } else {
                cout << "Invalid credentials: " << attempts << endl;
            }
        }

        if (!success) {
            cout << "Too many failed attempts." << endl;
            cout << "Forgot password? (y/n): " << endl;
            char fp;
            cin >> fp;
            if (fp == 'y') {
                forgotPassword();
            }
        }

    } else {
        string username, password;
        cout << "Enter new username: " << endl;
        cin >> username;

        do {
            cout << "Enter new password (6 characters only): " << endl;
            cin >> password;
            if (password.length() != 6) {
                cout << "Password must be exactly 6 characters" << endl;
            }
        } while (password.length() != 6);

        ofstream fout(database, ios::app);
        fout << username << "," << password << "\n";
        fout.close();
        cout << "Registration successful!" << endl;
    }
}


void adminlogin() {
    cout << "Admin Login" << endl;
    cout << "Are you admin? (y/n): " << endl;
    char choice;
    cin >> choice;
    int ch;

    if (choice == 'y') {
        int attempts = 3;
        while (attempts--) {
            string user, pass;
            cout << "Username: ";
            cin >> user;
            cout << "Password: ";
            cin >> pass;

            if (user == "xyz" && pass == "789") {
                cout << "Admin login successful" << endl;

                while (true) {
                    cout << "1. Update car library" << endl;
                    cout << "2. Answer customer queries" << endl;
                    cout << "3. Logout" << endl;
                    cout << "Enter your choice: ";
                    cin >> ch;

                    if (ch == 1) {
                        cout << "Car library has been updated" << endl;
                    } else if (ch == 2) {
                        cout << "Customer queries have been answered" << endl;
                    } else if (ch == 3) {
                        cout << "Logged out from admin panel" << endl;
                        break;
                    } else {
                        cout << "Invalid choice so try again" << endl;
                    }
                }
                return;
            } else {
                cout << "Invalid admin credentials : " << attempts << endl;
            }
        }
        cout << "Too many failed login attempts" << endl;
    } else {
        registeredUserlogin();
    }
}

int main() {
    cout << "Car Rental System" << endl;
    adminlogin();
    return 0;
}
