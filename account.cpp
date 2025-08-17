#include<iostream>
using namespace std;



void bankprocess(){
     
} 



void transaction(){
 int duration;
 cout << "Enter days duration" << endl;
 cin >> duration;
 if(duration==7)
    cout<<"Money transferred to receiver's account"<<endl;
else{
while(true){
    char reviewsent;
    cout<<"hWhether the user sent the review?(y/n)"<<endl;
    cin >> reviewsent;
    if(reviewsent=='y' || reviewsent=='Y') 
    break;
    }
    cout<<"Is the sender authorized?(y/n)"<<endl;
    char reviewsent;
    cin >> reviewsent;
    if(reviewsent=='n' || reviewsent=='N') 
    {
        cout << "Invalid transaction" << endl;
    }
    else 
    {
        cout << "Transaction completed" << endl;
    }
}
}
 
int main(){
    char carddetails;
    long long int accnumber;
    cout << "Do you have card?" << endl;
    cin >> carddetails;
    if(tolower(carddetails)=='y'){
        while(true){
        cout << "Insert bank card" << endl;
        cout << "Have you inserted the card properly?" <<endl;
        cin >> carddetails;
        if(carddetails=='y') {
            break;
        }
    }
}
    else{
        while(true){
        int count=0;
        cout << "Enter the bank account number" << endl;
        cin >> accnumber;
        if(accnumber==0) 
        count=1;
        else{
           if(accnumber<0)accnumber=-accnumber;
            while(accnumber!=0){
            accnumber/=10;
            count++;
        }
        }
        if(count>14)
        cout << "Invalid transaction" << endl;
        else break;
        }
    }
   bankprocess();
}