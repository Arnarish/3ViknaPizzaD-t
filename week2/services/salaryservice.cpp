#include <map>
#include "salaryservice.h"

using namespace std;

void SalaryService::add_entry(string name, string ssn, double salary, int month, int year) {
    if (is_valid_entry(name, ssn, salary, month, year)) {
        // If it's valid, create a new Salary object
        Salary sal(name, ssn, salary, month, year);
        try {
            if (!check_if_exists(ssn, month)) {
                // Append to the file
                writer.append_to_file(sal);
            }
            else {
                // Replace the entry with the current one
                Salary* records = reader.read_file();
                int size = reader.entries();
                for (int i = 0; i < size; i++) {
                    if (records[i].get_ssn() == ssn
                        && records[i].get_month() == month
                        && records[i].get_year() == year) {
                        //Overwrite the entry
                        records[i] = sal;
                        writer.write_entire_file(records, size);
                        break;
                    }
                }
            }
        }
        catch (FileExistsException) {
            writer.append_to_file(sal);
        }
    }
}

bool SalaryService::is_valid_name(string name) {
    // Check if the name is valid
    for (unsigned int i = 0; i < name.size(); i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            // Invalid character, so we return false
            return false;
        }
    }
    return true;
}

bool SalaryService::is_valid_ssn(string ssn) {
    // Check if the ssn is valid
    for (unsigned int i = 0; i < ssn.size(); i++) {
        if (!isdigit(ssn[i])) {
            return false;
        }
    }
    if (ssn.size() != 10) {
        return false;
    }
    return true;
}

bool SalaryService::is_valid_entry(string name, string ssn, double salary, int month, int year) {
    if (!is_valid_name(name)) {
        throw EmployeeNameException();
    } 
    if (!is_valid_ssn(ssn)) {
        throw EmployeeSSNException();
    }
    if (salary < 0) {
        throw EmployeeSalaryException();
    }
    if (month < 1 || month > 12) {
        throw EmployeeMonthException();
    }
    if (year > 2017 || year < 1900) {
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
    if (!is_valid_ssn(ssn)) {
        throw EmployeeSSNException();
    }
    return employee_records;
}

double SalaryService::total_wages(string ssn, int year) {
    double d = 0;
    if (year > 2017 || year < 1900) {
        throw EmployeeYearException();
    }
    if (!is_valid_ssn(ssn)) {
        throw EmployeeSSNException();
    }
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
    string name = "";
    double maxwage = 0;
    if (year > 2017 || year < 1900) {
        throw EmployeeYearException();
    }
    map<string, double> wages;
    try {
        Salary* records = reader.read_file();
        int size = reader.entries();
        for (int i = 0; i < size; i++) {
            if (records[i].get_year() == year) {
                wages[records[i].get_name()] += records[i].get_salary();
            }
        }
        delete[] records;
        // Iterate through the map
        for (map<string, double>::iterator it = wages.begin(); it != wages.end(); it++) {
            if (it->second > maxwage) {
                maxwage = it->second;
                name = it->first;
            }
        }
        return name;
    }
    catch (FileExistsException) {
        return name;
    }
}

