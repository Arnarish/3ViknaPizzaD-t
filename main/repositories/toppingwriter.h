#ifndef TOPPINGWRITER_H
#define TOPPINGWRITER_H
#include <string>
#include <fstream>
#include "topping.h"

class toppingwriter
{
    public:
        RecordWriter();
        void append_to_file(Topping& topping);
        void write_entire_file(Topping* topping, int n);

    private:
        string file;
        ofstream fout;
};

#endif // TOPPINGWRITER_H
