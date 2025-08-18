#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
 
string name, location;
 
void incomingOrder() {
    cout << "Customername: " << endl;
    cin >> name;
    cout << "Location: " << endl;
    cin >> location;
    string pick;
    do {
        cout << "Time to pickup would be 30 mins or less?(y/n): ";
        cin >> pick;
        if (pick == 'n') {
            cout << "Wait for the next customer" << endl;
        }
    } while (pick != "yes");
    fstream inc("userdata.csv", ios::out | ios::app);
    inc << name << "," << location << endl;
    inc.close();
    cout << "Order accepted" << endl;
}
 
pair<string, string> orderPlaced() {
    fstream taxi("taxiavail.csv", ios::in);
    ofstream temp("taxi.csv");
    string line, tname, ran;
    int km;
    bool taxiFound = false;
    pair<string, string> getTaxi = {"", ""};
    while (getline(taxi, line)) {
        stringstream ss(line);
        getline(ss, tname, ',');
        getline(ss, ran);
        km = stoi(ran);
        if (!taxiFound && km <= 10) {
            cout << "Taxi " << tname << " is within " << ran << " km range" << endl;
            taxiFound = true;
            getTaxi = {tname, ran};
            continue;
        }
        temp << tname << "," << ran << endl;
    }
    taxi.close();
    temp.close();
    remove("taxiavail.csv");
    rename("taxi.csv", "taxiavail.csv");
    if (!taxiFound) {
        cout << "No taxi found, kindly wait" << endl;
    }
    return getTaxi;
}
 
void taxiRide(string taxiName, string range) {
    if (taxiName == "") {
        cout << "Ride cannot be assigned" << endl;
        cout << "No taxi available" << endl;
        return;
    }
    cout << "Passenger " << name << " is assigned to taxi: " << taxiName << endl;
    fstream order("history.csv", ios::out | ios::app);
    order << name << "," << taxiName << endl;
    order.close();
    cout << "Taxi ride completed" << endl;
    cout << "History updated" << endl;
}
 
int main() {
    incomingOrder();
    pair<string, string> getTaxi = orderPlaced();
    taxiRide(getTaxi.first, getTaxi.second);
    return 0;
}
 
 