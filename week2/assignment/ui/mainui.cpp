#include "mainui.h"
#include "../services/salaryservice.h"


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
        //system("cls");
        m = c - 48;
        switch (m) {
            case 1:
                //add new salary record
                get_new_entry();
                break;
            case 2:
                //list by ssn
                list_by_ssn();
                break;
            case 3:
                //total yearly by ssn
                list_total_wages();
                break;
            case 4:
                //print highest paid employee
                top_employee();
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
    service.add_entry(name, ssn, salary, month, year);
}

void MainUI::list_by_ssn()
{
    string ssn;
    cout << "Please enter the ssn: ";
    cin >> ssn;
    vector<Salary> sals = service.get_entry(ssn);
    for (unsigned int i = 0; i < sals.size(); i++) {
        cout << sals[i] << endl;
    }
}

void MainUI::list_total_wages()
{
    string ssn;
    int year;
    cout << "Please enter the ssn: ";
    cin >> ssn;
    cout << "Please enter the year: ";
    cin >> year;
    cout << "Total wages: " << service.total_wages(ssn, year) << endl;
}

void MainUI::top_employee()
{
    int year;
    cout << "Please enter the year: ";
    cin >> year;
    cout << "Top dog: " << service.get_top_employee(year) << endl;
}
