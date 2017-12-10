#ifndef MENUIO_H
#define MENUIO_H

#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include "../models/pizza.h"
#include "../models/base.h"
#include "../models/topping.h"

// A class for reading and writing pizzas into a menu

using namespace std;

class MenuIO {
    public:
        MenuIO();
        void append_to_file(Pizza& pizza);
        vector<Pizza> read_file();

    private:
        string file;
        ofstream fout;
        ifstream fin;
        bool file_exists();
};

#endif
