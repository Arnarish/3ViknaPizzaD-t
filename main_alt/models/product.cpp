#include "product.h"

Product::Product() {
    name[0] = '\0';
    category = 'x';
    price = 0;
}

Product::Product(string name, char category, int price) {
    strcpy(this->name, name.c_str());
    this->category = category;
    this->price = price;
}

string Product::get_name() {
    string string_name = name;
    return string_name;
}

char Product::get_category() {
    return category;
}

int Product::get_price() {
    return price;
}

ostream& operator << (ostream& out, const Product& product) {
    out << product.name << " " << product.category << " " << product.price << endl;
    return out;
}

