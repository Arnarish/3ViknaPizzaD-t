#ifndef _H
#define _H

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Salary {
    public:
        Salary();
        Salary(string name, string ssn, double salary, int month, int year);
        void set_verbose(bool val);
        string get_name();
        string get_ssn();
        double get_salary();
        int get_month();
        int get_year();

    private:
        char name[128];
        char ssn[11];
        double salary;
        int month;
        int year;
        bool verbose;

        friend istream& operator >> (istream& in, Salary& s);
        friend ostream& operator << (ostream& out, const Salary& s);
};

#endif
