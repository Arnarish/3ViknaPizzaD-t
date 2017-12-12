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
#include "orderdetails.h"

using namespace std;

class Order {
    public:
        Order(OrderDetails&);
        int get_price();
        bool get_priority();
        bool get_paid();
        string get_location();

        vector<Pizza> get_pizzas();
        vector<Product> get_products();
        OrderDetails get_details();

        void add_pizza(Pizza& p);
        void add_product(Product& p);
        void add_comments(string comments);
        void set_paid();

    private:
        vector<Product> products;
        vector<Pizza> pizzas;
        OrderDetails details;

        // If the priority flag is set, it'll insert the order 
        // at the top of the order file rather than appending
        bool priority; 
        
        // If the paid flag is set, the pizza is paid for (duh)
        bool paid;

        friend ostream& operator << (ostream& out, Order& o);
};

#endif
