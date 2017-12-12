#ifndef DELIVERY_H
#define DELIVERY_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

#include <iostream>
#include <string>
using namespace std;

class DeliveryUI
{
    public:
        DeliveryUI();
        void main_menu();
        void ask_place();

    private:
        string ui_text;
        //Order* all_orders;
        //tímabundið order
      //  Orderio order;
};

#endif // DELIVERY_H
