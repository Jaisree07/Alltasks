#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

void logErrorToCSV(const string &errorType, const string &description) {
    ofstream file("error.csv", ios::app);
    if (!file) {
        cerr << "Error opening error-database.csv" << endl;
        return;
    }

    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back(); 

    file << errorType << "," << description << "," << dt << endl;
    file.close();
}

void answerQuestion() {
    cout << "Customer enquiry has been successfully addressed" << endl;
}

void redirectToSalesSupport() {
    cout << "Redirecting customer to sales support team" << endl;
    cout << "Sales support report has been completed" << endl;
}

bool contactTechnicalTeam() {
    cout << "Technical support team has been contacted" << endl;
    return true; 
}

bool testIssue() {
    cout << "Testing reported issue" << endl;
    return false; 
}

void contactCustomerForInfo() {
    cout << "Requesting additional information from the customer" << endl;
}

void confirmIssueFixed() {
    cout << "Customer has confirmed that the issue has been resolved" << endl;
}

void getFeedback() {
    cout << "Customer feedback has been recorded" << endl;
}

void survey() {
    cout << "Customer satisfaction survey completed" << endl;
}

void errorReport() {
    cout << "An error report has been generated" << endl;
    logErrorToCSV("Technical Error", "Unresolved issue encountered during testing");
}

void errorAnalysis() {
    cout << "Technical error analysis has been completed" << endl;
}

bool solveIssue() {
    cout << "Attempting to resolve the issue" << endl;
    return true;
}

int main() {
    cout << "Customer Service System" << endl;
    cout << "Customer has reported an issue" << endl;
    cout << "Customer contacted customer service department" << endl;

    int issueType;
    cout << "Enter issue type (1-Enquiry, 2-Sales, 3-Technical, 4-New Issue): ";
    cin >> issueType;
    cout << endl;

    switch(issueType) {
        case 1: 
            answerQuestion();
            getFeedback();
            survey();
            break;

        case 2: 
            redirectToSalesSupport();
            getFeedback();
            survey();
            break;

        case 3: 
            if (contactTechnicalTeam()) {
                confirmIssueFixed();
                getFeedback();
                survey();
            }
            break;

        case 4: {
            bool resolved = false;
            do {
                if (testIssue()) {
                    confirmIssueFixed();
                    getFeedback();
                    survey();
                    resolved = true;
                } else {
                    contactCustomerForInfo();
                    errorReport();
                    errorAnalysis();
                    if (solveIssue()) {
                        confirmIssueFixed();
                        getFeedback();
                        survey();
                        resolved = true;
                    } else {
                        cout << "Issue could not be resolved. Retrying" << endl;
                    }
                }
            } while (!resolved);
            break;
        }

        default:
            cout << "Invalid input. Please enter a number between 1 and 4" << endl;
    }

    cout << "Customer Service Process Completed" << endl;
    return 0;
}
v

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
                cout << "Simullate the issue(y/n)" << endl;
                cin >> simulation
            }
            
        }

    }
}

int main(){
    cout << "Customer Service System" << endl;
    cout << "Customer has reported an issue" << endl;
    cout << "Customer contacted customer service department" << endl;
    serviceissues();

}