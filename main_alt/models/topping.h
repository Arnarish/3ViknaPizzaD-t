#ifndef TOPPING_H
#define TOPPING_H

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

class Topping {
    public:
        Topping();
        Topping(string name, int price);
        string get_name();
        int get_price();

    private:
        char name[128];
        int price;
        friend ostream& operator << (ostream& out, const Topping& t);
};

#endif
