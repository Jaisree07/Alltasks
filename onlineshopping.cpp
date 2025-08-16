#include <iostream>
using namespace std;
 

void goods(){
    char goodscollected;
    char sellerconfirmed;
    cout << "Is goods collected?(y/n)" << endl;
    cin >> goodscollected;
    if(tolower(goodscollected)=='y'){
    cout << "Send warehouse goods to customer" << endl;
    cout << "Collect the goods" << endl;
    exit(0);
    }
    else{
        cout << "Seller will confirm the order receieved" << endl;
        exit(0);
    }
    
}
  
void warehouse(){
    
    cout << "Is the goods in warehouse?(y/n)" << endl;
    char ispresent;
    cin >> ispresent;
    if(tolower(ispresent)=='y'){
        cout << "Packed with other orders in warehouse" << endl;
    }
    else{
        while(true){
        char isselleravailable;
        cout << "Is the seller available?(y/n)" << endl;
        cin >> isselleravailable;
        if(tolower(isselleravailable)=='y'){
            cout << "Contact seller to ship the loded goods" << endl;
            cout << "Seller will send the goods to the customer" << endl;
            break;
        }
    }
    }
}
 
int main(){
    char isplaced;
    cout << "Is Order placed?(y/n)" << endl;
    cin >> isplaced;
    if(tolower(isplaced)=='y'){
        while(true){
        char isitem;
        cout << "Check if item is present?(y/n)" << endl;
        cin >> isitem;
        if(tolower(isitem)=='y'){
            goods();
        }
        else{
            warehouse();
        }
        }
    }
        else{
            cout << "No order placed" << endl;
        }    
    

}