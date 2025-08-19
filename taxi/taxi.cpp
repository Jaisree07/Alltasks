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
    char pick;
    do {
        cout << "Time to pickup would be 30 mins or less?(y/n): ";
        cin >> pick;
        if (pick == 'n') {
            cout << "Wait for the next customer" << endl;
        }
    } while (pick != 'y');
    fstream inc("userdata.csv", ios::out | ios::app);
    inc << name << "," << location << endl;
    inc.close();
    cout << "Order accepted" << endl;
    
}
 
pair<string, string> orderPlaced() {
    fstream taxi("taxiavail.csv", ios::in);
    ofstream temp("taxi.csv");
    string line, tname, ran;
    bool istaxifound = false;
    int distance;
    pair<string, string> ride = {"", ""};
    while (getline(taxi, line)) {
        stringstream ss(line);
        getline(ss, tname, ',');
        getline(ss, ran);
        distance = stoi(ran);
        if (!istaxifound && distance <= 20) {
            cout << "Taxi " << tname << " is within " << ran << " km range" << endl;
            istaxifound = true;
            ride = {tname, ran};
            continue;
        }
        temp << tname << "," << ran << endl;
    }
    taxi.close();
    temp.close();
    remove("taxiavail.csv");
    rename("taxi.csv", "taxiavail.csv");
    if (!istaxifound) {
        cout << "No taxi found, kindly wait" << endl;
    }
    return ride;
}
 
void taxiforride(string taxiName, string range) {
    if (taxiName.empty()) {
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
    pair<string, string> ride = orderPlaced();
    taxiforride(ride.first, ride.second);
    return 0;
}
 
 