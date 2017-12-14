#ifndef DELIVERY_H
#define DELIVERY_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32


#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "../models/location.h"
#include "../models/order.h"
#include "../models/orderdetails.h"
#include "../services/locationservice.h"
#include "../services/orderservice.h"
#include "../exceptions/UserInputException.h"
#include "../exceptions/FileReadException.h"
#include "../exceptions/FileWriteException.h"

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

        OrderService order_service;

        //Order* all_orders;
        //tímabundið order
      //  Orderio order;
};

#endif // DELIVERY_H
