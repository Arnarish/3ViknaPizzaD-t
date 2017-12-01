#include "Product.hpp"
#include <iostream>
#include <string>

using namespace std;


//    constructors
Product::Product() {
    _name = " ";
    _category = 'n';
    _price = 0;
}
Product::Product(string name, char category, int price) {
    _name = name;
    _category = category;
    _price = price;
}
void Product::set_verbose(bool tf) {
    verbose = tf;
}

//    get föll
string Product::get_name() {
    return _name;
}
char Product::get_category() {
    return _category;
}
int Product::get_price() {
    return _price;
}

//    friend föll
istream& operator >> (istream& in, Product& product) {
    if (product.verbose == false) {
        in >> product._name >> product._category >> product._price;
    }
    else {
        cout << "Enter product name: ";
        in >> product._name;
        cout << "Enter product category: ";
        in >> product._category;
        cout << "Enter product price: ";
        in >> product._price;
    }
    return in;
}
ostream& operator << (ostream& out, Product& product) {
    if (product.verbose == false) {
        out << product._name << endl << product._category << endl << product._price << endl << endl;
    }
    else {
        string cate_name;
        
        cout << "Name:  ";
        out << product._name << endl;
        cout << "Category: ";
        //            category-in með shortcut stöfum
        if (product._category == 'b' || product._category == 'B') {
            cout << "Breadsticks" << endl;
        }
        else if (product._category == 's' || product._category == 'S') {
            cout << "Soda" << endl;
        }
        cout << "Price: ";
        out << product._price << endl;
    }
    
    return out;
}


