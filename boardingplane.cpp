#include<iostream>
#include<thread>
#include<chrono>
using namespace std;


void aboard(){
    cout << "Is all passengers aboard?(y/n)" << endl;
    char aboard;
    cin >> aboard;
    if(aboard=='y' || aboard=='Y'){
        cout << "Close the gate" << endl;
    }
    else{
        cout << "Announcement for gate closure" << endl;
        int gateclosure;
        cout << "Informing gate closure timing" << endl;
        cin >> gateclosure;
        cout << "Gate closure in " << gateclosure << " minutes" << endl;
        //setting duration
        this_thread::sleep_for(chrono::minutes(gateclosure));
        cout << "Close the gate" << endl;
    }
}

void Boarding(){
    char chooseclass;
    char choosehalfclass;
    cout << "Priority boarding is started" << endl;
    cout << "Choose the first class(y/n)" << endl;
    cin >> chooseclass;y
    if(chooseclass=='y' || chooseclass=='Y'){
         cout << "Board Plane" << endl;
         //this_thread::sleep_for(chrono::seconds(snoozedur));
    }
    else{
        cout << "Choose the half class(y/n)" << endl;
        cin >> choosehalfclass;
        if(choosehalfclass=='y' || choosehalfclass=='Y'){
            cout << "Requesting all passengers to board the plane" << endl;
        }
        else{
            Boarding();
        }
    }
    cout << "Leave 5 minutes before the gate closes" << endl;
    aboard();

}


int main(){
    bool isopen;
    cout << "Is plane arrived the gate?(0/1)" << endl;
    cin >> isopen;
    if(isopen){
        Boarding();
    }
    else{
        cout << "Not arrived" << endl;
    }
}