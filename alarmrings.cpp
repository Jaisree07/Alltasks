#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void wakeup(){
    bool alarmactive=true;
    char isreadytowake;
    cout << "Ready to wake : yes(y) or No(n)" << endl;
    cin >> isreadytowake;
    while(alarmactive){
if(isreadytowake=='y' || isreadytowake=='Y'){
        cout << "Leave Bed" << endl;
        alarmactive=false;
       // break;
    }
    else{
        char islate;
        cout << "Is late: yes(y) or No(n)" << endl;
        cin >> islate;

 if(islate=='N' || islate=='n'){
             cout << "Snooze" << endl;
            int snoozedur;
            cout << "Enter snooze duration in minutes" << endl;
            cin >> snoozedur;
            cout << "Snooze for " << snoozedur << " minutes" << endl;
            this_thread::sleep_for(chrono::seconds(snoozedur));
            cout << "Alarm ringing" << endl;
            wakeup();
        }
        else{
            cout << "Leave Bed" << endl;
            alarmactive = false;
        }
    }
           

}
}

int main(){
    bool alarmrings;
    cout << "If alarm rings enter 1 else 0" << endl;
    cin >> alarmrings;
    if(alarmrings){
        wakeup();
    }
        cout << "Turnoff the alarm" << endl;
    
}