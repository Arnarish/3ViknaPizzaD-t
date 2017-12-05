#ifndef SALARYSERVICE_H
#define SALARYSERVICE_H

#include <vector>
#include <string>
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
#include "../models/salary.h"
#include "../repositories/recordreader.h"
#include "../repositories/recordwriter.h"

using namespace std;

class SalaryService {
    public:
        void add_entry(string name, string ssn, double salary, int month, int year);
        vector<Salary> get_entry(string ssn);
        double total_wages(string ssn, int year);
        string get_top_employee(int year);
    private:
        bool is_valid_entry(string name, string ssn, double salary, int month, int year);
        bool check_if_exists(string ssn, int month);
        RecordReader reader;
        RecordWriter writer;
};

#endif
