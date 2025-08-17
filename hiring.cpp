#include <iostream>
using namespace std;

void job() {
    cout << "Define job description" << endl;
    cout << "Send crew request to HR team" << endl;
    cout << "Determine Classification" << endl;

    char hiring;
    cout << "Regular hiring process? (y/n): ";
    cin >> hiring;

    if (hiring == 'y') {
        cout << "Post job internally" << endl;
    } else if (hiring == 'n') {
        cout << "Special hiring process" << endl;
    } else {
        cout << "Invalid input! Assuming special hiring process" << endl;
    }
}

void yes() {
    cout << "Arrange candidate meeting" << endl;
    cout << "Conduct pre-interview" << endl;
    cout << "Setup interview questions" << endl;
    cout << "Conduct interview" << endl;

    char ref;
    cout << "Good reference? (y/n): ";
    cin >> ref;

    if (ref == 'y') {
        cout << "Select candidate" << endl;
        cout << "Evaluate the pay rate" << endl;
        cout << "Send employment offer" << endl;

        char offer;
        cout << "Candidate confirms offer? (y/n): ";
        cin >> offer;

        if (offer == 'y') {
            cout << "Hire candidate" << endl;
        } else if (offer == 'n') {
            cout << "Candidate declined the offer\nTry next candidate" << endl;
        } else {
            cout << "Invalid input for offer confirmation\nOffer withdrawn" << endl;
        }

    } else if (ref == 'n') {
        cout << "Reference not good\nCannot proceed with this candidate" << endl;
    } else {
        cout << "Invalid input for reference\nCandidate disqualified" << endl;
    }
}

void no() {
    cout << "Develop recruitment plan" << endl;
    cout << "Place advertisement" << endl;
    cout << "Collect applications" << endl;

    char resume;
    cout << "Is it a qualified resume? (y/n): ";
    cin >> resume;

    if (resume == 'y') {
        yes();
    } else if (resume == 'n') {
        cout << "Resume not qualified and Rejecting candidate" << endl;
    } else {
        cout << "Invalid input for resume check\nApplication discarded" << endl;
    }
}

int main() {
    job();

    char ch;
    cout << "Is the person a suitable candidate? (y/n): ";
    cin >> ch;

    if (ch == 'y') {
        yes();
    } else if (ch == 'n') {
        no();
    } else {
        cout << "Invalid input and Treating candidate as not suitable" << endl;
        no();
    }

    cout << "Candidate not hired" << endl;
    return 0;
}
