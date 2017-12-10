#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

#include "topping.h"
#include "base.h"

using namespace std;

class Pizza {
    public:
        Pizza(Base& base);
        Pizza(string name, Base& base);
        void add_topping(Topping& t);
        int get_price();
        vector<Topping> get_toppings();
        int number_of_toppings();
        string get_name();
        Base get_base();
    private:
        char name[128];
        Base base;
        vector<Topping> toppings;
        // The price of a pizza is the price of the base
        // + the price of all the toppings
        int price; 

        friend ostream& operator << (ostream& out, Pizza& p);
};

#endif
