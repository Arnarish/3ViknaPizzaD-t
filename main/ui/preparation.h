#ifndef PREPERATION_H
#define PREPERATION_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "../models/location.h"

#include "../services/preparationservice.h"
#include "../services/locationservice.h"
#include "../services/orderservice.h"

#include "../exceptions/UserInputException.h"
#include "../exceptions/FileReadException.h"
#include "../exceptions/FileWriteException.h"

using namespace std;

class PreperationUI {
    public:
        PreperationUI();
        void main_menu();

    private:
        string ui_text;
        vector<Order> orders;
        Location store_location;
        PreparationService preparationservice;
        LocationService locationservice;
        OrderService orderservice;

        void ask_place();
};

#endif // PREPERATION_H
