#include<iostream>
using namespace std;


void Discount(){
    bool discount;
    cout << "Is ticket discount available for you(0/1)" << endl;
    cin >> discount;
    if(discount)
    {
        cout << "Show valid documentation for the discount" << endl;
    }
        while(true){
        char destination;
        cout << "Is destination reached by the passenger(y/n)" << endl;
        cin >> destination;
        if(tolower(destination)=='y'){
           cout << "Leave the train" << endl;
           break;
        }
    }
    
}

void Reservation(){
    cout << "Is reservation is availabe(y/n)" << endl;
    char reserveavailable;
    cin >> reserveavailable;
    if(tolower(reserveavailable)=='y'){
        cout << "Look for the assigned seat for you" << endl;
    }
    else{
        cout << "Look for the unassigned seat for you" << endl;
    }
    cout << "Inspector will check for the train ticket" << endl;
    cout << " Show the ticket received by email or ticketmachine" << endl;
    Discount();
}

void Ticketcollection(){
    cout << "Collect the ticket via mail(m) or ticketmachine(t)" << endl;
    char collect;
    cin >> collect;
    if(tolower(collect)=='m'){
        cout << " Ticket will be received through mail" << endl;
        cout << "Check the letter box in 3 days" << endl;
    }
    else{
        cout << " Receive the ticket through ticket machine" << endl;
    }
    cout << "Board the train" << endl;
    Reservation();
}

void Buyticket(){
    cout << "Buy train ticket" << endl;
    cout << "Is seat reservation needed?(y/n)" << endl;
    char isreserve;
    cin >> isreserve;
    if(tolower(isreserve)=='y'){
        cout << "Select the seat" << endl;
    }
    else{
        cout << "Do you want reservation" << endl;
        cin >> isreserve;
        if(tolower(isreserve)=='y')
        {
             cout << "Select the seat" << endl;
        }
        else{
           cout << "No reservation available"
           exit(0);
        }
    }
      Ticketcollection();
}

int main(){
    Buyticket();
}