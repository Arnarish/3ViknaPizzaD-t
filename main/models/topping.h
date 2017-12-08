#ifndef TOPPING_H
#define TOPPING_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Topping {
    public:
        Topping();
        Topping(string name, int price);
        string get_name();
        int get_price();
        void set_name(string name);
        void set_price(int price);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

    private:
        string name;
        int price;

        friend istream& operator >> (istream& in, Topping& t);
        friend ostream& operator << (ostream& out, const Topping& t);
};

#endif
