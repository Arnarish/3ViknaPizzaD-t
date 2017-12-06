#include "salary.h"


Salary::Salary() {
    name[0] = '\0';
    ssn[0] = '\0';
    salary = 0;
    month = 0;
    year = 0;
    verbose = true;
}
Salary::Salary(string name, string ssn, double salary, int month, int year) {
    strcpy(this->name, name.c_str());
    strcpy(this->ssn, ssn.c_str());
    this->salary = salary;
    this->month = month;
    this->year = year;
}
void Salary::set_verbose(bool val) {
    verbose = val;
}

string Salary::get_name() {
    return name;
}

string Salary::get_ssn() {
    return ssn;
}

double Salary::get_salary() {
    return salary;
}

int Salary::get_month() {
    return month;
}

int Salary::get_year() {
    return year;
}

ostream& operator << (ostream& out, const Salary& s) {
    if (s.verbose)
        out << "Name: ";
    out << s.name << "\n";
    if (s.verbose)
        out << "SSN: ";
    out << s.ssn << "\n";
    if (s.verbose)
        out << "Salary: ";
    out << s.salary << "\n";
    if (s.verbose)
        out << "Month: ";
    out << s.month << "\n";
    if (s.verbose)
        out << "Year: ";
    out << s.year << "\n";
    return out;
}
