#ifndef MAINUI_H
#define MAINUI_H

#include <iostream>
#include <string>
#include "management.h"
#include "preparation.h"
#include "ordering.h"
#include "delivery.h"

#include "../exceptions/UserInputException.h"
#include "../exceptions/FileExistsException.h"
#include "../exceptions/FileReadException.h"
#include "../exceptions/FileWriteException.h"

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
        PreparationUI preparation;
        OrderUI ordering;
        DeliveryUI delivery;
};

#endif
