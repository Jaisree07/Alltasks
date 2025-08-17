#include<iostream>
using namespace std;


int count=0;

void attemptcheck(){
      
      char login;
      char authorization;
        cout << "Is the user logged in?(y/n)" << endl;
        cin >> login;
        if(tolower(login)=='y'){
            cout << "Is the user is authorized?(y/n)" << endl;
            cin >> authorization;
            if(tolower(authorization)=='y'){
                cout << "The user is authorized" << endl;
                cout << "Grant the access" << endl;
                return;
            }
            else{
                cout << "Unauthorized access account" << endl;
                if(count>=5){
                    cout << "Account locked due to 5 failed attempts" << endl;
                    cout << "Alert the user" << endl;
                }
                else{
                    cout << "Try again" << endl;
                    count++;
                    attemptcheck();
                }
            }
        }
        else{
            cout << "User not logged in" << endl;
        }
    }




int main(){
    attemptcheck();
}