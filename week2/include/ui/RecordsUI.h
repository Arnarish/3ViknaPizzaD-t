#ifndef RECORDSUI_H
#define RECORDSUI_H
#include <iostream>
#include "newempui.h"

using namespace std;

class RecordsUI
{
    public:
        RecordsUI();
        void menu();

    private:
        bool validateinput(char input);
};

#endif // RECORDSUI_H
