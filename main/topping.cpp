#include <iostream>
#include <string>
#include <fstream>
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
void Topping::write(ofstream& fout) const {
    // Write a topping into a binary file
    int strlen = name.length() + 1;
    fout.write((char*)(&strlen), sizeof(int));
    fout.write(name.c_str(), strlen);
    fout.write((char*)(&price), sizeof(int));
}

void Topping::read(ifstream& fin) {
    // Read a topping from a binary file
    int strlen;
    fin.read((char*)(&strlen), sizeof(int));
    char *str = new char[strlen];
    fin.read(str, strlen);
    fin.read((char*)(&price), sizeof(int));
    name = str;
}

istream& operator >> (istream& in, Topping& t) {
    cout << "Topping name: ";
    getline(in, t.name);
    getline(in, t.name);
    cout << "Price: ";
    in >> t.price;
    return in;
}

ostream& operator << (ostream& out, const Topping& t) {
    out << t.name << " " << t.price << endl;
    return out;
}
