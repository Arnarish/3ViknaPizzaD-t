#include "base.h"

using namespace std;

Base::Base() {
    this->name[0] = '\0';
    this->size = 0;
    this->price = 0;
}

Base::Base(string name, int size, int price) {
    // Assuming validation has been handled somewhere else
    // I don't want to handle input validation in a class constructor
    strcpy(this->name, name.c_str());
    this->size = size;
    this->price = price;
}

string Base::get_name() {
    // Return the name as a std::string
    // I really wanna avoid using c-strings as much as possible
    string str_name = name;
    return str_name;
}

int Base::get_size() {
    return size;
}

int Base::get_price() {
    return price;
}

ostream& operator << (ostream& out, const Base& b) {
    // Write the name in the following format: 16" thin crust
    // Handy for the receipt later on
    out << b.size << "\" " << b.name << endl;
    return out;
}
