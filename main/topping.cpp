#include <iostream>
#include <string>
#include "topping.h"

using namespace std;

Topping::Topping() {
    name = "";
    price = 0;
}

Topping::Topping(string name, int price) {
    this->name = name;
    this->price = price;
}

string Topping::get_name() {
    return name;
}

int Topping::get_price() {
    return price;
}

void Topping::set_name(string name) {
    this->name = name;
}

void Topping::set_price(int price) {
    this->price = price;
}
