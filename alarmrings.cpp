#include<iostream>
#include<thread>
#include<chrono>
using namespace std;


void wakeup(){
    bool alarmactive=true;
    char isreadytowake;
    char islate;
    
    while(alarmactive){
       cout << "Ready to wake : yes(y) or No(n)" << endl;
       cin >> isreadytowake;
       if(isreadytowake=='y' || isreadytowake=='Y'){
        cout << "Leave Bed" << endl;
        // alarmactive=false;
        break;
    }
    // alarmactive=false;
    else {
        cout << "Is late: yes(y) or No(n)" << endl;
        cin >> islate;
        if(islate=='y'){
            cout << "Leave Bed" << endl;
            break;

        }
        else{
            int snoozedur;
            cout << "Enter snooze duration in minutes" << endl;
            cin >> snoozedur;
            cout << "Snooze for " << snoozedur << " minutes" << endl;
            this_thread::sleep_for(chrono::seconds(snoozedur));
            cout << "Alarm ringing" << endl;
            //wakeup();

        }
       
        
    }
}

}

int main(){
    bool alarmrings;
    cout << "If alarm rings enter 1 or 0" << endl;
    cin >> alarmrings;
    if(alarmrings){
        wakeup();
    }
    cout << "Alarm turned off" << endl;
}