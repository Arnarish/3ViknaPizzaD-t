#include <map>
#include "salaryservice.h"
#include "../models/salary.h"
#include "../repositories/recordreader.h"
#include "../repositories/recordwriter.h"
#include "../exceptions/EmployeeNameException.h"
#include "../exceptions/EmployeeSSNException.h"
#include "../exceptions/EmployeeSalaryException.h"
#include "../exceptions/EmployeeMonthException.h"
#include "../exceptions/EmployeeYearException.h"

using namespace std;

/*
SalaryService::SalaryService() {
    RecordReader reader;
    RecordWriter writer;
}
*/

void SalaryService::add_entry(string name, string ssn, double salary, int month, int year) {
    if (is_valid_entry(name, ssn, salary, month, year)) {
        // If it's valid, create a new Salary object
        Salary sal(name, ssn, salary, month, year);
        if (!check_if_exists(ssn, month)) {
            // Append to the file
        }
        else {
            // Replace the entry with the current one
        }
    }
}

bool SalaryService::is_valid_entry(string name, string ssn, double salary, int month, int year) {
    // Check if the name is valid
    for (unsigned int i = 0; i < name.size(); i++) {
        if (!isalpha(name[i]) && name[i] != ' ') { 
            // Invalid character, so we throw an exception
            throw EmployeeNameException();
        }
    }
    for (unsigned int i = 0; i < ssn.size(); i++) {
        if (!isdigit(ssn[i])) {
            throw EmployeeSSNException();
        }
    }
    if (salary < 0) {
        throw EmployeeSalaryException();
    }
    if (month < 1 || month > 12) { 
        throw EmployeeMonthException();
    }
    if (year != 2017) {
        throw EmployeeYearException();
    }
    return true;
}

bool SalaryService::check_if_exists(string ssn, int month) {
    Salary* records = reader.read_file();
    int number_of_records = reader.entries();
    for (int i = 0; i < number_of_records; i++) {
        if (records[i].get_ssn() == ssn && records[i].get_month() == month) {
            delete[] records;
            return true;
        }
    }
    delete[] records;
    return false;
}

vector<Salary> SalaryService::get_entry(string ssn) {
    vector<Salary> employee_records;
    Salary* records = reader.read_file();
    int size = reader.entries();
    for (int i = 0; i < size; i++) {
        if (records[i].get_ssn() == ssn) {
            employee_records.push_back(records[i]);
        }
    }
    delete[] records;
    return employee_records;
}

double SalaryService::total_wages(string ssn, int year) {
    double d = 0;

    Salary* records = reader.read_file();
    int size = reader.entries();
    for (int i = 0; i < size; i++) {
        if (records[i].get_ssn() == ssn && records[i].get_year() == year) {
            d += records[i].get_salary();
        }
    }
    delete[] records;
    return d;
}

string SalaryService::get_top_employee(int year) {
    map<string, double> wages;
    Salary* records = reader.read_file();
    int size = reader.entries();
    for (int i = 0; i < size; i++) {
        if (records[i].get_year() == year) {
            wages[records[i].get_name()] += records[i].get_salary();
        }
    }
    delete[] records;
    double maxwage = 0;
    string name = "";
    // Iterate through the map
    for (map<string, double>::iterator it = wages.begin(); it != wages.end(); it++) {
        if (it->second > maxwage) {
            maxwage = it->second;
            name = it->first;
        }
    }
    return name;
}

