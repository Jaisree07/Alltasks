#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

bool verifyPayment(bool cardValid, bool fundsAvailable) {
    cout << "Payment verification initiated by card network" << endl;

    if (!cardValid) {
        cout << "Card is not valid : Payment failed." << endl;
        return false;
    }
    if (!fundsAvailable) {
        cout << "Insufficient funds : Payment failed." << endl;
        return false;
    }

    cout << "Payment successfully verified by bank" << endl;
    return true;
}

void processTransaction(string id, string name, bool accountValid, bool cardValid, bool fundsAvailable) {
    cout << endl << "Order placed by client: " << name << " (ID: " << id << ")" << endl;

    if (accountValid) {
        cout << "Account status: Valid" << endl;

        if (verifyPayment(cardValid, fundsAvailable)) {
            cout << "Transaction completed successfully" << endl;
            cout << "Cardholder will receive statement at the end of billing cycle" << endl;
        }
    } else {
        cout << "Account status: Invalid : Transaction failed" << endl;
    }
}

int main() {
    ifstream file("datacustomerDB.csv");
    if (!file.is_open()) {
        cout << "Error: Unable to open 'datacustomerDB.csv'" << endl;
        return 1;
    }

    string line;
    getline(file, line); 

    string customerID;
    cout << "Enter Customer ID to process transaction: ";
    cin >> customerID;

    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, acc, card, funds;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, acc, ',');
        getline(ss, card, ',');
        getline(ss, funds, ',');

        // Remove spaces and carriage returns inline
        acc.erase(remove(acc.begin(), acc.end(), ' '), acc.end());
        acc.erase(remove(acc.begin(), acc.end(), '\r'), acc.end());
        card.erase(remove(card.begin(), card.end(), ' '), card.end());
        card.erase(remove(card.begin(), card.end(), '\r'), card.end());
        funds.erase(remove(funds.begin(), funds.end(), ' '), funds.end());
        funds.erase(remove(funds.begin(), funds.end(), '\r'), funds.end());

        if (id == customerID) {
            found = true;
            bool accountValid = (acc == "1");
            bool cardValid = (card == "1");
            bool fundsAvailable = (funds == "1");

            processTransaction(id, name, accountValid, cardValid, fundsAvailable);
            break;
        }
    }

    if (!found) {
        cout << "Customer ID not found in database" << endl;
    }

    file.close();
    cout << endl << "End of transaction process" << endl;
    return 0;
}
