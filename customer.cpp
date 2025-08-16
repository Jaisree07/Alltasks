#include<iostream>
using namespace std;


int main(){
    while(true){
    bool ison;
    cout << "Is computer is on?(0/1)" << endl;
    cin >> ison;
    if(ison){
        char iserrorfound;
        cout << "Is there is any error found on the computer?(y/n)" << endl;
        cin >> iserrorfound;
        if(iserrorfound=='y' || iserrorfound=='Y'){
            cout << "Perform diagnosis" << endl;
        }
        else{
            cout << "Computer is in good condition" << endl;
            break;
        }
    }
    else{
        bool power;
        cout << "Is the powerlight on or not?(0/1)" << endl;
        cin >> power;
        if(power){
            cout << "Find a computer specialist" << endl;
            break;
        }
        else{
            char isplugged;
            cout << "Is power plugged to the wall?(y/n)" << endl;
            cin >> isplugged;
            if(tolower(isplugged)=='y'){
                cout << "Find a computer specialist" << endl;
                break;
            }
            else{
                cout << "Plug power to the wall" << endl;
            }
        }
    }
}

}