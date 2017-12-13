#ifndef DELIVERY_H
#define DELIVERY_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

#include "../repositories/locationio.h"
#include "../models/location.h"
#include "../services/locationservice.h"
#include "../exceptions/UserInputException.h"
#include "../exceptions/FileReadException.h"
#include "../exceptions/FileWriteException.h"
#include <limits>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class DeliveryUI {
    public:
        DeliveryUI();
        void main_menu();
        void ask_place();

    private:
        string ui_text;
        string store_location;
        LocationService location_service;
        LocationIO locationio;

        //Order* all_orders;
        //tímabundið order
      //  Orderio order;
};

#endif // DELIVERY_H
