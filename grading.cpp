#include<iostream>
using namespace std;


int main(){
    while(true)
    {
    int score;
    cout << "Get the score" << endl;
    cin >> score;
    if(score>=0 && score<=100){
        if(score>=80){
            cout << "Grade A" << endl;
             break;
        }
        else if(score>=60){
            cout << "Grade B" << endl;
             break;
        }
        else if(score>=50){
            cout << "Grade A" << endl;
             break;
        }
        else{
            cout << "Fail" << endl;
            break;
        }
    }
    cout << "Enter the valid number" << endl;

}
}