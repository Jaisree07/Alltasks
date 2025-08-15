#include<iostream>
using namespace std;

void coffeeprocess( bool poweron){
    cout << "Choose : 1-Mocha ; 2-Latte ; 3-Espresso" << endl;
    int coffeselection;
    cin >> coffeselection;
    bool poweroff;
    
    switch(coffeselection){
    case 1:
    cout << "Add chocolate coffee" <<endl;
    case 2:
    cout << "Add frothed milk" <<endl;
    case 3:
    cout << "Add hot coffee" <<endl;
    break;
    default:
    cout << "Please choose a correct option" << endl;
    break;   
}
       
        cout << "Do you want to poweroff or continue" << endl;
        cin >> poweroff;
        if(poweroff) coffeeprocess(poweroff);
        cout << "Powered off" << endl;
}

int main(){
    bool poweron=true;
    //int coffeselection;
    coffeeprocess(poweron);
    // char powerbutton;
   
}