#include<iostream>
using namespace std;

void door(){
    cout << "Do NOT open the door!" << endl;
    cout << "Seal all cracks using wet towels" << endl;
    cout << "Contact the fire department immediately" << endl;
    cout << "Wave at doors or windows to signal for help" << endl;
    cout << "Wait for rescue" << endl;
}

void evacuation(){
    char doorHot, seeSmoke, escape;
    cout << "Are the doors hot or is smoke seeping in?(y/n)" << endl;
    cin >> doorHot;
    if(tolower(doorHot) == 'y') {
        door();
    } else {
        cout << "Go downstairs and exit the building if possible" << endl;
        cout << "Have you escaped the building? (y/n)" << endl;
        cin >> escape;
        if(escape == 'y') return;
        else {
            while(true){
                cout << "Have you seen the fire? (y/n)" << endl;
                cin >> escape;
                if(escape == 'y'){
                    cout << "Go upstairs and head to the balcony" << endl;
                    cout << "Have you reached the balcony? (y/n)" << endl;
                    char isreached;
                    cin >> isreached;
                    if(isreached == 'y'){
                        cout << "Stay put and wait for rescue" << endl;
                        break;
                    }
                }
            }
        }
    }
}

void smoke(){
    int num;
    char fire;
    cout << "Choose an option" << endl;
    cout << "1. You or someone sees fire or smoke" << endl;;
    cout << "2. Smoke detector detects fire" << endl;;
    cout << "Enter your choice (1 or 2)" << endl;;
    cin >> num;
    if(num == 1){
        cout << "Is the fire inside the building?(y/n):" << endl;;
        cin >> fire;
        if(fire == 'n') 
            cout << "Contact the fire department immediately" << endl;
        break;
        else 
            cout << "Push the nearest fire alarm trigger" << endl;
    }
    else if(num == 2) 
        cout << "Smoke detector has triggered the alarm" << endl;
    else 
        cout << "Invalid option selected" << endl;
        cout << "Grab your phone, keys, and wallet before evacuating" << endl;
    evacuation();
}

int main(){
    smoke();
}
