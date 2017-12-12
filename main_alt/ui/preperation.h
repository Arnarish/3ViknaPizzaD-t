#ifndef PREPERATION_H
#define PREPERATION_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32
#include "../repositories/locationio.h"
#include "../models/location.h"
#include "../services/Locationservice.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class PreperationUI
{
    public:
        PreperationUI();
        void main_menu();
        void ask_place();


    private:
        string ui_text, store_location;
        locationio locio;
        Locationservice LocServ;
};

#endif // PREPERATION_H
