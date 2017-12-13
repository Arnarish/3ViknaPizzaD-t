#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "../models/base.h"
#include "../models/topping.h"
#include "../models/pizza.h"
#include "../models/order.h"
#include "../models/orderdetails.h"
#include "../repositories/baseio.h"
#include "../repositories/toppingio.h"
#include "../repositories/menuio.h"
#include "../repositories/orderio.h"

using namespace std;

class OrderService {
    public:
        void create_order(string name, string phone, string address, 
                          string location, int zipcode);
        OrderDetails create_details(string name, string phone, string address,
                                    string location, int zipcode);
        Pizza create_pizza();
        vector<Order> get_ordered();
        vector<Order> get_ready();
        vector<Order> get_history();
    private:
        BaseIO baseio;
        ToppingIO toppingio;
        MenuIO menuio;
        OrderIO orderio;
};

#endif
