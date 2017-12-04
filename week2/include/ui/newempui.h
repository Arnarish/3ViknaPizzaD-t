#ifndef NEWEMPUI_H
#define NEWEMPUI_H

#include <iostream>
#include <string>

#include "RecService.h"
#include "Records.h"

using namespace std;

class newempui
{
    public:
        newempui();
        void addMenu();
        Records AddToRecord();
    private:
        string name;
        long SSN;
        double salary;
        int month;
        int year;
        RecService recservice;
};

#endif // NEWEMPUI_H
