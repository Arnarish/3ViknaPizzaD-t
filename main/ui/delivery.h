#ifndef DELIVERY_H
#define DELIVERY_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "../models/location.h"
#include "../models/order.h"

#include "../services/deliveryservice.h"
#include "../services/locationservice.h"
#include "../services/orderservice.h"

#include "../exceptions/UserInputException.h"
#include "../exceptions/FileReadException.h"
#include "../exceptions/FileWriteException.h"
#include "../exceptions/InvalidLocationException.h"

using namespace std;

class DeliveryUI {
    public:
        DeliveryUI();
        void main_menu();
        void get_place();

    private:
        string ui_text;
        vector<Order> orders;
        vector<Order> all_orders;
        Location store_location;
        LocationService locationservice;
        DeliveryService deliveryservice;
        OrderService orderservice;

        void ask_place();
        void list_orders();
};

#endif // DELIVERY_H
