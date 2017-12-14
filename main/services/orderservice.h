#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "../models/base.h"
#include "../models/topping.h"
#include "../models/pizza.h"
#include "../models/order.h"
#include "../models/orderdetails.h"
#include "../models/product.h"
#include "../repositories/baseio.h"
#include "../repositories/toppingio.h"
#include "../repositories/menuio.h"
#include "../repositories/orderio.h"
#include "../repositories/productio.h"
#include "../exceptions/InvalidNameException.h"
#include "../exceptions/CustomerPhoneException.h"
#include "../exceptions/CustomerAddressException.h"
#include "../exceptions/InvalidLocationException.h"
#include "../exceptions/CustomerZipcodeException.h"

using namespace std;

class OrderService {
    public:
        void create_order(string name, string phone, string address,
                          string location, int zipcode);
        OrderDetails create_details(string name, string phone, string address,
                                    string location, int zipcode);
        vector<Pizza> pizza_menu();
        Product* product_menu();
        Base* read_base();
        int base_entries();
        int topping_entries();
        int product_entries();
        Topping* read_topping();
        void write_order(Order& order);

        vector<Order> get_ordered();
        vector<Order> get_ready();
        vector<Order> get_history();

        vector<string> products_drinks();
        vector<string> products_sides();
        vector<string> products_other();

    private:
        BaseIO baseio;
        ToppingIO toppingio;
        MenuIO menuio;
        OrderIO orderio;
        ProductIO productio;
};

#endif
