#include "mainui.h"

MainUI::MainUI() {
    ui_text = " --- Very Important Business Inc. ---\n"
              " 1. Add a salary record\n"
              " 2. List salary records by SSN\n"
              " 3. Total yearly salary by SSN\n"
              " 4. Print the highest paid employee\n"
              " 5. Exit.";
}
//Main menu, 5 operations as per project description
void MainUI::main_menu() {
    char c;
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        cin >> c;
        m = c - 48;
        switch (m) {
            case 1:
                // Add new salary record
                get_new_entry();
                break;
            case 2:
                // List by ssn
                list_by_ssn();
                break;
            case 3:
                // Total yearly by ssn
                list_total_wages();
                break;
            case 4:
                // Print highest paid employee
                top_employee();
                break;
            case 5:
                cout << endl << "So long, and thanks for all the fish.";
                // Quit the program with a nice status
                exit(0);
            default:
                cout << "Invalid input!" << endl;
                break;
        }
    }
}

//Enter a new entry, adds it to the .dat file via servies. catch errors if thrown.
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
    try {
        service.add_entry(name, ssn, salary, month, year);
    }
    catch (EmployeeMonthException) {
        cout << "Invalid month." << endl;
    }
    catch (EmployeeNameException) {
        cout << "Invalid name." << endl;
    }
    catch (EmployeeSalaryException) {
        cout << "Invalid salary." << endl;
    }
    catch (EmployeeSSNException) {
        cout << "Invalid social security number." << endl;
    }
    catch (EmployeeYearException) {
        cout << "Invalid year." << endl;
    }
}
//Lists by ssn, lists each entry via for loop. catches error if illegal/invalid SSN.
void MainUI::list_by_ssn()
{
    string ssn;
    cout << "Please enter the ssn: ";
    cin >> ssn;
    try {
        vector<Salary> sals = service.get_entry(ssn);
        for (unsigned int i = 0; i < sals.size(); i++) {
            cout << sals[i] << endl;
        }
    }
    catch (EmployeeSSNException) {
        cout << "Invalid social security number." << endl;
    }

}
//Lists total wages over a year, for a given year. catch error if thrown.
void MainUI::list_total_wages()
{
    string ssn;
    int year;
    cout << "Please enter the ssn: ";
    cin >> ssn;
    cout << "Please enter the year: ";
    cin >> year;
    try {
        cout << "Total wages: " << service.total_wages(ssn, year) << endl;
    }
    catch (EmployeeMonthException) {
        cout << "Invalid month." << endl;
    }
    catch (EmployeeSSNException) {
        cout << "Invalid social security number." << endl;
    }
}
//Prints the highest total salary employee over a given year. catches error if thrown
void MainUI::top_employee()
{
    int year;
    cout << "Please enter the year: ";
    cin >> year;
    try {
        cout << "Top dog: " << service.get_top_employee(year) << endl;
    }
    catch (EmployeeYearException) {
        cout << "Invalid year." << endl;
    }
}
