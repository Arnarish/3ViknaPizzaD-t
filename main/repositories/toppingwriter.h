#ifndef TOPPINGWRITER_H
#define TOPPINGWRITER_H
#include <string>
#include "../models/topping.h"

class Toppingwriter
{
    public:
        Toppingwriter();
        void append_to_file(const Topping& topping);
        void write_entire_file(Topping* topping, int n);

    private:
        string file;
        ofstream fout;
};

#endif // TOPPINGWRITER_H
