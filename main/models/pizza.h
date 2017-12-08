#ifndef PIZZA_H
#define PIZZA_H
#include <vector>

#include "topping.h"


class pizza
{
    public:
        pizza();
        pizza(string pbase, string psize, Topping& topping, char notes[128]);// þetta er eitthvað skakkt
        string get_base();
        string get_size();
        void set_base();
        void set_size();

    private:
        string pizza_base;
        string pizza_size;
        vector <Topping> pizza_topping(string topping);
        char comments[128]; // aditional comment possible, don't cut etc..
        //option to split pizzas? needs to be implemented higher up

};

#endif // PIZZA_H
