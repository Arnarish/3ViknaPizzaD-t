#ifndef ORDERIO_H
#define ORDERIO_H

#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include "../models/pizza.h"
#include "../models/base.h"
#include "../models/topping.h"
#include "../models/order.h"
#include "../exceptions/FileExistsException.h"
#include "../exceptions/FileWriteException.h"
#include "../exceptions/FileReadException.h"
// A class for reading and writing orders

using namespace std;

class OrderIO {
    public:
        OrderIO();
        vector<Pizza> read_pizzas();
        vector<Order> read_file();

        void write_to_file(Order& order);
        void write_pizza(Pizza& pizza);
        void set_ordered();
        void set_ready();
        void set_delivered();

        void read_a_pizza();
    private:
        string file;
        ofstream fout;
        ifstream fin;
        bool file_exists();
        void insert(Order& order);
        void append(Order& order);
};

#endif
