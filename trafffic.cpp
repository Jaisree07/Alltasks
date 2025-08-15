#include<iostream>
using namespace std;


int main(){
    char isfound;
    cout << "Found Footbridge?yes(y) or no(n)" << endl;
    cin >> isfound;
    if(isfound=='y' || isfound=='Y'){
        cout << "Use footbridge" << endl;
    }
    else{
        char istunnel;
        cout << "Found Tunnel?yes(y) or no(n)" << endl;
        cin >> istunnel;
        if(istunnel=='y' || istunnel='Y'){
            cout << "Use tunnel" << endl;
        }
        else{
            char iscrossing;
             cout << "Found Crossing?yes(y) or no(n)" << endl;
             cin >> iscrossing;
             if(iscrossing){
                Traffic();
             }
             else{
                cout << "Walk away" << endl;
             }
        }
    }
}