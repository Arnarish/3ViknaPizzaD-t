#ifndef PREPERATION_H
#define PREPERATION_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32
#include "../repositories/locationio.h"
#include "../repositories/orderio.h"
#include "../models/location.h"
#include "../services/Locationservice.h"
#include "../exceptions/UserInputException.h"
#include "../exceptions/FileReadException.h"
#include "../exceptions/FileWriteException.h"
#include <limits>
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
        LocationIO locio;
        LocationService LocServ;
        OrderIO orders;
};

#endif // PREPERATION_H
