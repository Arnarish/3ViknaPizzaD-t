#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

#include <iostream>
#include <string>
#include "../services/managementservice.h"


using namespace std;

class ManagementUI {
    public:
        ManagementUI();
        void main_menu();

    private:
        string ui_text;
        ManagementService management_service;
};

#endif
