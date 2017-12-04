#ifndef RECORDS_H
#define RECORDS_H

#include <string>

using namespace std;

class Records
{
    public:
        Records();
        Records(string name, long SSN, double salary, int month, int year);

    private:
        string _name;
        long _SSN;
        double _salary;
        int _month;
        int _year;

};

#endif // RECORDS_H
