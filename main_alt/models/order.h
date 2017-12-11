#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

#include "topping.h"
#include "base.h"
#include "pizza.h"
#include "product.h"

using namespace std;

class Order {
    public:
        Order(string customer_address, string customer_name, string phone_no, string location);
        int get_price();
        string get_location();
        int get_priority();
        void add_pizza(Pizza& p);
        void add_product(Product& p);
        void add_comments(string comments);

        // These functions set the status flag
        void set_in_progress();
        void set_ready();
        void set_delivered();
    private:
        vector<Product> products;
        vector<Pizza> pizzas;

        char customer_address[128];
        char customer_name[128];
        char location[128];
        char phone_no[7];
        char comments[512]; // Picky customers can write many comments
        // Status handles where the order is in the system
        // D = delivered 
        // P = in progress
        // R = ready

        char status; 
        int priority; 
        // If the priority flag is set, it'll insert the order 
        // at the top of the order file rather than appending
        // Is this a good idea?

        friend ostream& operator << (ostream& out, Order& o);
};

#endif
