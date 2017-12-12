#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H
#include "../models/topping.h"
#include "../repositories/toppingio.h"

class ToppingService
{
    public:
        void add_topping(const Topping& topping);


    private:
        Topping topping;

};

#endif // TOPPINGSERVICE_H
