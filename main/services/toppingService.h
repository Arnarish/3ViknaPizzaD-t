#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H
#include "topping.h"
#include "toppingwriter.h"

class ToppingService
{
    public:
        void add_topping(const Topping& topping);


    private:
        Topping t;

};

#endif // TOPPINGSERVICE_H
