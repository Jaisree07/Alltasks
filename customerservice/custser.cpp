#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;


void feedback(){
     cout << "feedback(0/1)" <, endl;
     bool feedback;
     cin >> feedback;
     if(feedback){
        cout << "Take survey" << endl;
     }

    return;
}

void errorReport(){
    while(true){
   cout << "Error analysis" << endl;
   char iserror;
   cin >> iserror;
   if(tolower(iserror)=='y'){
    cout << "Solve the issue(y/n)" << endl;
    char isfixed;
    cin >> isfixed;
    if(tolower(isfixed)=='y'){
        return;
    }
    else{
        errorReport();
    }
   }
}
}

void serviceissues(){
    cout << "Enquiry(y/n)" << endl;
    char enq;
    cin >> enq;
    if(tolower(enq)=='y'){
        cout << "Answer the question" << endl;
    }
    else{
        char issuesales;
        cout << "Is there is any issue in sales?(y/n)" << endl;
        cin >> issuesales;
        if(tolower(issuesales)=='y'){
            cout << "Redirect to sales support" << endl;
            cout << "Fixed the issue" << endl;
        }
        else{
            cout << "Is there is any technical issue?(y/n)" << endl;
            char istechissue;
            cin >> istechissue;
            if(tolower(istechissue)=='y'){
               cout << "Contact technical team" << endl;
               cout << "Fixed the issue" << endl;
            }
            else{
                cout << "Is there is any new issue(y/n)" << endl;
                char isnew;
                cin >> isnew;
                if(tolower(isnew)=='y'){
                    cout << "Test the issue" << endl;
                }
                else{
                    cout << "Resolve the issue" << endl;
                }
                char simulation;
                cout << "Simulate the issue(y/n)" << endl;
                cin >> simulation;
                if(tolower(simulation)=='y'){
                    errorReport();
                }
                else{
                    cout << "Contact customer for information" << endl;
                }
            }
            
        }

    }
}

int main(){
    cout << "Customer Service System" << endl;
    cout << "Customer has reported an issue" << endl;
    cout << "Customer contacted customer service department" << endl;
    serviceissues();
    cout << "Confirm issue fixed with customer" << endl;
    feedback();

}