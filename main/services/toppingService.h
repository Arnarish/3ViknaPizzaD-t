#ifndef TOPPINGSERVICE_H
#define TOPPINGSERVICE_H
#include "topping.h"
#include "Toppingwriter.h"

class ToppingService
{
    public:
        void add_topping(const Topping& topping);


    private:
        Toppingwriter tw;

};

#endif // TOPPINGSERVICE_H
