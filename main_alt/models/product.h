#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Product
{
    public:
        Product();
        Product(string name, char category, int price);
        string get_name();
        char get_category();
        int get_price();

    private:
        char name[128];
        char category;
        int price;
        friend ostream& operator << (ostream& out, const Product& product);
};

#endif // PRODUCT_H
