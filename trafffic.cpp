#include<iostream>
using namespace std;

void color(){
    string choose;
    cout << "Choose the color" << endl;
    cin >> choose;
    if(choose=="red"){
        return;
    }
     color(); 
}
void traffic(){
         char iftraffic;
         cout << "Traffic light present?yes(y) or no(n)" << endl;
         cin >> iftraffic;
         if(iftraffic){
            color();
         }
         else{
            cout << "Wait" << endl;
         }

}

int main(){
    char isfound;
    while(true){
            cout << "Found Footbridge?yes(y) or no(n)" << endl;
    cin >> isfound;
    if(isfound=='y' || isfound=='Y'){
        cout << "Use footbridge" << endl;
        break;
    }
    else{
        char istunnel;
        cout << "Found Tunnel?yes(y) or no(n)" << endl;
        cin >> istunnel;
        if(istunnel=='y' || istunnel=='Y'){
            cout << "Use tunnel" << endl;
            break;
        }
        else{
            char iscrossing;
             cout << "Found Crossing?yes(y) or no(n)" << endl;
             cin >> iscrossing;
             if(iscrossing=='y'){
                break;
             }
             else{
                cout << "Walk away" << endl;
             }
            }
        }
    }
    traffic();
    while(true){
        cout << "Look left" << endl;
        bool iscarapproach;
        cout << "Is car approaching?(0/1)" << endl;
        cin >> iscarapproach;
        if(iscarapproach==false){
            cout << "Cross the traffic" << endl;
            break;
        }
    }

}