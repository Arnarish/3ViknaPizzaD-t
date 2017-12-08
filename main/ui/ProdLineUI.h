#ifndef PRODLINEUI_H
#define PRODLINEUI_H

#include <iostream>

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

using namespace std;

class ProdLineUI
{
    public:
        ProdLineUI();
        void prod_menu();
        void select_store();
        void bake_pizza();
    private:
        string ui_text;
};

#endif // PRODLINEUI_H
