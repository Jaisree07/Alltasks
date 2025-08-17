#include<iostream>
using namespace std;


void flight(){
    cout << "Leave the flight and Immigration starts" << endl;
    char permit;
    cout << "Is permit available?(y/n)" << endl;
    cin >> permit;
    if(tolower(permit)=='y'){
        cout << "Claim the baggage" << endl;
    }
    else{
        cout << "Send it to the originate country" << endl;
    }
}


void immigration(){
     cout << "Board the flight" << endl;
     cout << "Flight departure starts" << endl;
     cout << "Flight lands" << endl;
     return;
}

void securityscreening(){
    cout << "Security screening process" << endl;
    char check;
    //m-metal and r-restricted access
    cout << "Checking(m/r/d)" << endl;
    cin >> check;
    if(check=='m'|| check=='M'){
        cout << "It is a metal" << endl;
        cout << "Hand search" << endl;
        //dangerous goods
        char isdangerous;
        cout << "Is any dangerous goods present(y/n)" << endl;
        cin >> isdangerous;
        if(tolower(isdangerous)=='y')
        {
            cout << "Give up the dangerous goods" << endl;
            
        }
        
    }
    else if(check=='r' || check=='R'){
        cout << "Is there is any restricted access?(y/n)" << endl;
        char access;
        cin >> access;
        if(tolower(access)=='y'){
           cout << "Give up articles above permitted limited" << endl;
          
        }
        
    }
    else {
        char isdangerous;
        cout << "Is any dangerous goods present(y/n)" << endl;
        cin >> isdangerous;
        if(tolower(isdangerous)=='y')
        {
            cout << "Give up the dangerous goods" << endl;
            
        }

    }
    immigration();
    string isconnected;
    cout << "Reached the airport for connecting flight?(yes/no)" << endl;
    cin >> isconnected;
    if(isconnected=="yes" || isconnected=="YES"){
        securityscreening();
    }
    else{
        flight();
        
    }
}


int main(){
    cout << "Checkin" << endl;
    cout << "Drop the baggage" << endl;
    securityscreening();

}