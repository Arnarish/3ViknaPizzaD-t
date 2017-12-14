#ifndef PREPERATION_H
#define PREPERATION_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "../repositories/locationio.h"
#include "../repositories/orderio.h"
#include "../models/location.h"
#include "../services/locationservice.h"
#include "../exceptions/UserInputException.h"
#include "../exceptions/FileReadException.h"
#include "../exceptions/FileWriteException.h"

using namespace std;

class PreperationUI {
    public:
        PreperationUI();
        void main_menu();
        void ask_place();

    private:
        string ui_text, store_location;
        LocationIO locio;
        LocationService LocServ;
        OrderIO orderio;
};

#endif // PREPERATION_H
