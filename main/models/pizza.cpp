#include "pizza.h"

pizza::pizza() {
    pizza_base = "";
    pizza_size = "";
    pizza_topping[0] = "";
    comments = '\0';
}

pizza::pizza(string pbase, string psize, vector<Topping> topping, char notes[128]) { //
    this->pizza_base = pbase;
    this->pizza_size = psize;
    for(int i=0; i < topping.size(); i++)    {
        pizza_topping.push_back (topping[i]);
    }
}

string pizza::get_base() {
    return pizza_base;
}

string pizza::get_size() {
    return pizza_size;
}

void pizza::set_base(string pbase) {
    this->pizza_base = pbase;
}

void pizza::set_size(string psize) {
    this->pizza_size = psize;
}
