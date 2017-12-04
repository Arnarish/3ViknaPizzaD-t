#include "newempui.h"

newempui::newempui()
{
    //ctor
}

void newempui::addMenu()
{
    cout << "Add info to salary records." << endl;
    recservice.add_record(AddToRecord());
}

Records newempui::AddToRecord()
{
    cout << "Name of the Employee: ";
    cin.ignore();
    getline(cin, name); //nota getline ef nafn inniheldur bil
    cout << "The Employee's SSN: ";
    cin >> SSN;
    cout << "The salary for the given month: ";
    cin >> salary;
    cout << "and then the month and year of payment, seperated by a space: ";
    cin >> month >> year;
    return Records(name, SSN, salary, month, year);
}

