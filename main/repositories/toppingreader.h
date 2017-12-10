#ifndef TOPPINGREADER_CPP_H
#define TOPPINGREADER_CPP_H

#include <string>
#include <fstream>
#include "../models/topping.h"
//include exceptions


class toppingreader
{
    public:
        toppingreader();
        Topping* read_file();
        int entries();

    private:
        string file;
        ifstream fin;
        bool file_exists();
};

#endif // TOPPINGREADER_CPP_H
