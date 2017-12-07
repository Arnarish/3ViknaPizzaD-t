#ifndef MAINUI_H
#define MAINUI_H

#include "salesui.h"
#include "prodlineui.h"
#include "storeui.h"
#include "adminui.h"

#if _WIN32
#include <stdlib.h>
#endif // _WIN32


class MainUI {
    public:
        MainUI();
        void main_menu();

    private:
        string ui_text;
        AdminUI adminui;
        SalesUI salesui;
        ProdLineUI produi;
        StoreUI storeui;
};

#endif
