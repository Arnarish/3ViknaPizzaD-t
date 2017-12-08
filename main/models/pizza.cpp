#include "pizza.h"

pizza::pizza() {
    pizza_base = "";
    pizza_size = "";
    pizza_topping[0] = "";
    comments = '\0';
}

pizza::pizza(string pbase, string psize, vector topping, char notes[128]) {
    this->pizza_base = pbase;
    this->pizza_size = psize;
    for(int i=0; i < topping.size(); i++)    {
        pizza_topping.push_back (topping[i]);
    }
}
