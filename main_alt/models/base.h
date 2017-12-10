#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Base {
    public:
        Base();
        Base(string name, int size, int price);
        string get_name();
        int get_size();
        int get_price();

    private:
        char name[128]; //127 characters should suffice for any name
        int size;
        int price;
        friend ostream& operator << (ostream& out, const Base& b);
};

#endif
