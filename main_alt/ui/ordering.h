#ifndef ORDERING_H
#define ORDERING_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32
#include <limits>
#include <iostream>
#include <string>
#include "../services/orderservice.h"
#include "../repositories/locationio.h"
#include "../models/location.h"
#include "../services/Locationservice.h"

using namespace std;

class OrderUI {
    public:
        OrderUI();
        void main_menu();

    private:
        string ui_text;
        OrderService order_service;

        void create_order(string name, string phone, string address, string location);
        locationio locio;
        Locationservice LocServ;
        location* locat;
};

#endif
