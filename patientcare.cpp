#include<iostream>
using namespace std;

void doctoravailability();
void Patientreg();
void Medication();


void Patientreg(){
    char isreg;
    cout << "If regeistered press y else n" << endl;
    cin >> isreg;
    if(isreg=='y'){
        bool isnurse;
        cout << "If nurse available press 1 else 0" << endl;
        cin >> isnurse;
        if(isnurse){
            cout << "Record health" << endl;
            doctoravailability();
        }
        else{
            cout << "Wait for nurse" << endl;
        }
           // doctoravailability();
        
    }
    else{
        cout << "Register patient details" << endl;
        Patientreg();
    }
}

void Medication(){
    bool needmed;
    cout << "If medication needed press 1 else press 0" << endl;
    cin >> needmed;
    if(needmed){
        cout << "Prescribe to the patient" << endl;
       
    }
    cout << "Patient leaves" << endl;


}

void doctoravailability(){
    char doctavailable;
    cout << "If doctor is available press y else n" << endl;
    cin >> doctavailable;
    if(doctavailable=='y'){
        cout << "Assign patient to doctor" << endl;
        char followup;
        cout << "If followup press y else no" << endl;
        cin >> followup;
        if(followup=='y'){
            cout << "Arrange the appointment" << endl;
            
        }
      Medication();
    }
    else{
            cout << "Wait for doctor" << endl;
            doctoravailability();
        }
}



int main(){
    bool patientarrival;
    bool emg;
    cout << "If Emergency press 1 else press 0" << endl;
    cin >> emg;
    if(emg){
        doctoravailability();
    }
    else{
        Patientreg();
    }

}