#ifndef TOPPINGWRITER_H
#define TOPPINGWRITER_H
#include <string>
#include <fstream>
#include "topping.h"

class Toppingwriter
{
    public:
        RecordWriter();
        void append_to_file(const Topping& topping);
        void write_entire_file(Topping* topping, int n);

    private:
        string file;
        ofstream fout;
};

#endif // TOPPINGWRITER_H
