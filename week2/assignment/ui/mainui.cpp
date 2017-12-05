#include <iostream>
#include <string>
#include "mainui.h"

using namespace std;

MainUI::MainUI() {
    // TODO: add salary service object
    ui_text = " --- Very Important Business Inc. ---\n"
                     " 1. Add a salary record\n"
                     " 2. List salary records by SSN\n"
                     " 3. Total yearly salary by SSN\n"
                     " 4. Print the highest paid employee\n"
                     " 5. Exit.";
}

void MainUI::main_menu() {
    char c;
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        cin >> c;
        system("cls");
        m = c - 48;
        switch (m) {
            case 1:
                cout << "1" << endl;
                get_new_entry();
                break;
            case 2:
                cout << "2" << endl;
                break;
            case 3:
                cout << "3" << endl;
                break;
            case 4:
                cout << "4" << endl;
                break;
            case 5:
                cout << "So long, and thanks for all the fish.";
                exit(0);
            default:
                cout << "Invalid input!" << endl;
                break;
        }
    }
}


void MainUI::get_new_entry()
{
    cout << "Entering a new salary record" << endl;
    cout << "Employee name: ";
    cin >> name;
    cout << "Employee social security number: ";
    cin >> ssn;
    cout << "Employee's salary: ";
    cin >> salary;
    cout << "Month of payment: ";
    cin >> month;
    cout << "Year of payment: ";
    cin >> year;
    //SalaryService.add_entry(name, ssn, salary, month, year);
}
