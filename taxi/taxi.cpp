#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct User {
    string username;
    string password;
};


vector<User> loadUsers(const string &filename) {
    vector<User> users;
    ifstream file(filename);
    string line, uname, pass;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, uname, ',');
        getline(ss, pass, ',');
        if (!uname.empty() && !pass.empty())
            users.push_back({uname, pass});
    }
    file.close();
    return users;
}


void updatePassword(const string &filename, const string &uname, const string &newpass) {
    vector<User> users = loadUsers(filename);
    ofstream file(filename, ios::trunc);
    for (auto &u : users) {
        if (u.username == uname) {
            u.password = newpass;
        }
        file << u.username << "," << u.password << "\n";
    }
    file.close();
}


bool login(vector<User> &users, string uname, string pass) {
    for (auto &u : users) {
        if (u.username == uname && u.password == pass) {
            return true;
        }
    }
    return false;
}

int main() {
    string dbFile = "userdataDB.csv";
    vector<User> users = loadUsers(dbFile);

    cout << "Login System\n";
    cout << "Are you Admin (A) or Registered User (R)? : ";
    char choice;
    cin >> choice;

    if (choice == 'A' || choice == 'a') {
        string uname, pass;
        cout << "Enter Admin username: ";
        cin >> uname;
        cout << "Enter Admin password: ";
        cin >> pass;

        if (login(users, uname, pass) && uname == "admin") {
            cout << "Admin login successful!\n";
            cout << "Admin can update all data here...\n";
        } else {
            cout << "Admin login failed.\n";
        }
    }
    else if (choice == 'R' || choice == 'r') {
        string uname, pass;
        cout << "Enter Username: ";
        cin >> uname;
        cout << "Enter Password: ";
        cin >> pass;

        if (login(users, uname, pass)) {
            cout << "User login successful!\n";
            cout << "Welcome, " << uname << "!\n";
        } else {
            cout << "Invalid credentials!\n";
            cout << "Forgot Password? (Y/N): ";
            char fp;
            cin >> fp;
            if (fp == 'Y' || fp == 'y') {
                string newpass;
                cout << "Enter new password: ";
                cin >> newpass;
                updatePassword(dbFile, uname, newpass);
                cout << "Password updated successfully!";
            } else {
                cout << "Returning to main menu\n";
            }
        }
    }
    else {
        cout << "Invalid choice!\n";
    }

    cout << "End";
    return 0;
}