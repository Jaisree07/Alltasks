#include<iostream>
using namespace std;

 
void transaction(){
   int days;
   char review;
   cout<<"Enter days"<<endl;
   cin >> days;
   if(days==7)
      cout << "Money transferred to receiver" << endl;
   else{
       while(true){
           cout << "have you sent the review y/n?" << endl;
           cin >> review;
                if(review=='y') break;
            }
        cout << "Is it authorized y/n?" << endl;
        cin >> review;
        if(review=='n'){ 
             cout << "Invalid transaction" << endl;
        }
        else{
             cout << "Transaction completed" << endl;
        }
}
}


void bankdetailprocess(){
   long long int receiveracc, senderacc;
   int amount;
   cout << "Enter receiver bank account" << endl;
   cin >> receiveracc;
   cout << "enter value" << endl;
   cin >> amount;
   cout << "Enter sender bank account" << endl;
   cin >> senderacc;
   transaction();
}
 
int main(){
    char cardcheck;
    long long int accnumcheck;
    cout << "Do you have card?(y/n)" << endl;
    cin >> cardcheck;
    if(cardcheck=='y'){
        while(true){
        cout <<"Insert bank card" << endl;
        cout <<"Have you inserted properly?(y/n)" << endl;
        cin >> cardcheck;
        if(cardcheck=='y') 
        break;
    }
}
    else{
        while(true){
            int count=0;
            cout << "Enter bank account number" << endl;
            cin >> accnumcheck;
        if(accnumcheck==0){
            count=1;
        }
        else{
           if(accnumcheck<0)accnumcheck=-accnumcheck;
            while(accnumcheck!=0){
            accnumcheck/=10;
            count++;
        }
        }
        if(count>14) cout<<"Invalid number"<<endl;
        else {
            break;
        }
        }
    }
    bankdetailprocess();
    
}
 