#ifndef Product_hpp
#define Product_hpp
//    kannski '_H' í stað fyrir 'Product_hpp'
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Product{
    
private:
    string _name;
    char _category;
    int _price;
    
    bool verbose = false;
    
public:
    
    Product();
    Product(string name, char category, int price);
    void set_verbose(bool tf);
    
    string get_name();
    char get_category();
    int get_price();
    
    friend istream& operator >> (istream& in, Product& product);
    friend ostream& operator << (ostream& out, Product& product);
    
};

#endif
