#include "pizza.h"

using namespace std;

Pizza::Pizza(Base& base) {
    strcpy(this->name, "Generic");
    this->base = base;
}

Pizza::Pizza(string name, Base& base) {
    strcpy(this->name, name.c_str());
    this->base = base;
}

void Pizza::add_topping(Topping& t) {
    toppings.push_back(t);
}

int Pizza::get_price() {
    int n = base.get_price();
    for (unsigned int i = 0; i < toppings.size(); i++) {
        n += toppings[i].get_price();
    }
    return n;
}

vector<Topping> Pizza::get_toppings() {
    return toppings;
}

int Pizza::number_of_toppings() {
    return (int)toppings.size();
}

string Pizza::get_name() {
    string s = name;
    return s;
}

Base Pizza::get_base() {
    return base;
}

ostream& operator << (ostream& out, Pizza& p) {
    out << p.base << "Toppings: ";
    for (unsigned int i = 0; i < p.toppings.size(); i++) {
        out << p.toppings[i] << ", ";
    }
    out << "\n" << p.get_price() << " kr." << endl;
    return out;
}
