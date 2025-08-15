#include<iostream>
using namespace std;


void findumbrella(){
    bool searchumbrella;
    int count=0;
    int randomval=10;
    cout << "Do you wnat to search umbrella" << endl;
    if(searchumbrella){
        cout << "Found Umbrella" << endl;
        cout << "Bring Umbrella" << endl;
    }
    else{
        while(true)
        {
            cout << "Enter umbrella count" << endl;
            cin >> count;

            if(count>randomval){
                cout << "Buy umbrella" << endl;
                break;
            }
            else{
                cout << "Searched for "<< count <<" times,No Umbrella found" << endl;
            }
        }
    }

}

int main(){
    bool israining;
    cout << "Is it raining? raining-1 ;Not raining-0" << endl;
    cin >> israining ;
    if(israining)
    {
        findumbrella();
    }
    else
    {
        cout << "Don't bring umbrella" << endl;
    }
return 0;
}