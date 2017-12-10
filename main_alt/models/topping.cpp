#include "topping.h"

using namespace std;

Topping::Topping() {
    name[0] = '\0';
    price = 0;
}

Topping::Topping(string name, int price) {
    strcpy(this->name, name.c_str());
    this->price = price;
}

string Topping::get_name() {
    return name;
}

int Topping::get_price() {
    return price;
}

ostream& operator << (ostream& out, const Topping& t) {
    out << t.name;
    return out;
}
