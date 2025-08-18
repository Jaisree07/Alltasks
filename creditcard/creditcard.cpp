#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string username, cardNumber;


void creditCardValidation(){
    cout << "Payment verification by creditcard" << endl;
    cout << "Is this credit card valid? (y/n): " << endl;
    char cardValid;
    cin >> cardValid;
    if (cardValid == 'y' || cardValid == 'Y') {
        cout << "Card is valid : Transaction success" << endl;
        char fundsAvailable;
        cout << "Is any fund available? (y/n): " << endl;
        cin >> fundsAvailable;
        if (fundsAvailable == 'y' || fundsAvailable == 'Y') {
            cout << "Payment verified by the bank" << endl;
            char accountValid;
            cout << "Is account available? (y/n): ";
            cin >> accountValid;
            if (accountValid == 'y' || accountValid == 'Y') {
            cout << "Account is available" << endl; 
            return;
    }
    }
    }   
    creditCardValidation();

}

void getdetails(string& name, string& cardnum){
    fstream customerfile("customer.csv", ios::in | ios::out  | ios::app);
    customerfile << name << " , " << cardnum;

}

int main(){

    cout << "Transaction Processing System" << endl;
    cout << "Enter your username: " << endl;
    cin >> username;
    cout << "Enter your card number: " << endl;
    cin >> cardNumber;

    char orderPlaced;
    cout << "Is order placed by client? (y/n):";
    cin >> orderPlaced;

    if (orderPlaced != 'y' && orderPlaced != 'Y') {
        cout << "Order notplaced : Process terminated" << endl;
        return 0;
    }
    else{
        creditCardValidation();
        cout << "Transction completed" << endl;
        getdetails(username,cardNumber);
    }
}