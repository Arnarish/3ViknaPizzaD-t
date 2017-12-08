#ifndef STOREUI_H
#define STOREUI_H

#include <iostream>

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

using namespace std;

class StoreUI
{
    public:
        StoreUI();
        void store_menu();
        void new_pizza(); // is it better to include this function from salesui?
    private:
        string ui_text;
};

#endif // STOREUI_H
