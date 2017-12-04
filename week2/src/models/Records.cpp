#include "Records.h"

Records::Records()
{
    this->_name = "";
    this->_SSN = 1234567890;
    this->_salary = 0.0;
    this->_month = 1;
    this->_year = 2000;
}

Records::Records(string name, long SSN, double salary, int month, int year)
{
    this->_name = name;
    this->_SSN = SSN;
    this->_salary = salary;
    this->_month = month;
    this->_year = year;
}


