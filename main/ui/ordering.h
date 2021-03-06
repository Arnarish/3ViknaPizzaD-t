#ifndef ORDERING_H
#define ORDERING_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

#include <limits>
#include <iostream>
#include <string>
#include <vector>
#include "../models/base.h"
#include "../models/topping.h"
#include "../models/pizza.h"
#include "../models/order.h"
#include "../models/orderdetails.h"
#include "../models/location.h"
#include "../models/product.h"
#include "../services/orderservice.h"
#include "../repositories/locationio.h"
#include "../services/locationservice.h"
#include "../exceptions/UserInputException.h"
#include "../exceptions/InvalidNameException.h"
#include "../exceptions/CustomerPhoneException.h"
#include "../exceptions/CustomerAddressException.h"
#include "../exceptions/InvalidLocationException.h"
#include "../exceptions/CustomerZipcodeException.h"
#include "../exceptions/NoBaseException.h"


using namespace std;

class OrderUI {
    public:
        OrderUI();
        void main_menu();
        void create_order(string name, string phone, string address, string location, int zipcode);
        Pizza create_pizza();
    private:
        string ui_text;
        OrderService order_service;

        void create_order(string name, string phone, string address, string location);
        LocationIO locationio;
        LocationService location_service;

        BaseIO baseio;
        ToppingIO toppingio;
        MenuIO menuio;
        OrderIO orderio;
};

#endif
