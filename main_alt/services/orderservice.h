#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "../models/base.h"
#include "../models/topping.h"
#include "../models/pizza.h"
#include "../models/order.h"
#include "../repositories/baseio.h"
#include "../repositories/toppingio.h"
#include "../repositories/menuio.h"

using namespace std;

class OrderService {
    public:
        void create_order(string name, string phone, string address, string location);
        Pizza create_pizza();
    private:
        BaseIO baseio;
        ToppingIO toppingio;
        MenuIO menuio;
};

#endif
