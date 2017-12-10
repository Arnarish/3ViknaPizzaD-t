#ifndef TOPPINGIO_H
#define TOPPINGIO_H
#include <string>
#include <fstream>
#include "../models/topping.h"

using namespace std;

class ToppingIO {
    public:
        ToppingIO();
        void append_to_file(const Topping& topping);
        Topping* read_file();
        int number_of_entries();
        bool file_exists();

    private:
        string file;
        ifstream fin;
        ofstream fout;
};

#endif // TOPPINGWRITER_H
