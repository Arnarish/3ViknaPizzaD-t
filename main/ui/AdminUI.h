#ifndef ADMINUI_H
#define ADMINUI_H
#include <iostream>
#include "../models/topping.h"
#include "../services/toppingService.h"
#include <string>

using namespace std;

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

class AdminUI
{
    public:
        AdminUI();
        void admin_menu();
        void manage_toppings_menu();
        void manage_menu_menu();
        Topping create_topping();
    private:
        string ui_text;
        string ui_manage_toppings_text;
        string ui_manage_menu_text;
        ToppingService newtoppingservice;
};

#endif // ADMINUI_H
