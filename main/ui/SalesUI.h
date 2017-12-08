#ifndef SALESUI_H
#define SALESUI_H

#include <iostream>

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

using namespace std;

class SalesUI
{
    public:
        SalesUI();
        void sales_menu();
        void new_pizza();

    private:
        string ui_text;
};

#endif // SALESUI_H
