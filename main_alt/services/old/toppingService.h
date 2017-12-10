#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H
#include "../models/topping.h"
#include "../repositories/toppingwriter.h"

class ToppingService
{
    public:
        void add_topping(const Topping& topping);


    private:
        Toppingwriter tw;

};

#endif // TOPPINGSERVICE_H
