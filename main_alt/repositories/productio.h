#ifndef PRODUCTIO_H
#define PRODUCTIO_H

#include <string>
#include <fstream>
#include "../models/product.h"


class productio
{
    public:
        productio();
        void append_to_file(const Product& product);
        Product* read_file();
        int number_of_entries();

    private:
        string file;
        ofstream fout;
        ifstream fin;
        bool file_exists();

};

#endif // PRODUCTIO_H
