#ifndef MAINUI_H
#define MAINUI_H

#include <iostream>
#include <string>
#include "management.h"
#include "preperation.h"
#include "ordering.h"
#include "delivery.h"

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

using namespace std;

class MainUI {
    public:
        MainUI();
        void main_menu();

    private:
        string ui_text;
        // Other UI classes
        ManagementUI management;
        PreperationUI preperation;
        OrderUI ordering;
        DeliveryUI delivery;
};

#endif
