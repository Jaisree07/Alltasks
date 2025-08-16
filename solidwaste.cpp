#include<iostream>
using namespace std;


void reusableandrecycle(){
    char reuse;
    char recycle;
    cout << "Is this waste is reusabl?(y/n)" << endl;
    cin >> reuse;
    if(reuse=='y' || reuse=='Y'){
        cout << "Reuse for other applications" << endl;
    }
    else{
        cout << "Is this waste is recyclable?(y/n)" << endl;
        cin >> recycle;
        if(recycle=='y' || recycle=='Y'){
             cout << "Reuse for other applications" << endl;
         }
         else{
            cout << "Use it for landfill" << endl;
         }
    }
   
}


void organicwaste(){
     cout << "Is it is a organic waste?(yes/no)" << endl;
     string isorganic;
     cin >> isorganic;
     if(isorganic=="yes")
     {
       cout << "Is organic waste has high energy?((y/n))" << endl;
       char ishighenergy;
       cin >> ishighenergy;
       if(ishighenergy=='y' || ishighenergy=='Y'){
        cout << "It is used as a Bio-fuel" << endl;
       }
       else{
        cout << "It is used as a organic fertilizer" << endl;
       }

     }
     reusableandrecycle();


}

int main(){
    cout << "Get waste" << endl;
    organicwaste();
}