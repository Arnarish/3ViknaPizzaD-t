#ifndef ADMINUI_H
#define ADMINUI_H
#include <iostream>

using namespace std;


class AdminUI
{
    public:
        AdminUI();
        void admin_menu();
        void manage_toppings_menu();
        void manage_menu_menu();
    private:
        string ui_text;
        string ui_manage_toppings_text;
        string ui_manage_menu_text;
};

#endif // ADMINUI_H
