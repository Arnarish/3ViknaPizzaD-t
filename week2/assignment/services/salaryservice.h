#ifndef SALARYSERVICE_H
#define SALARYSERVICE_H

#include "../models/salary.h"

using namespace std;

class SalaryService {
    public:
        void add_entry(string name, string ssn, double salary, int month, int year);
        Salary* get_entry(string ssn);
        double total_wages(string ssn);
        string get_top_employee(int year);
    private:
        bool is_valid_entry(string name, string ssn, double salary, int month, int year);
        bool check_if_exists(string ssn, int month);
};

#endif
