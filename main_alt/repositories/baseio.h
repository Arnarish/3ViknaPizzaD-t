#ifndef BASEIO_H
#define BASEIO_H

#include <string>
#include <fstream>
#include "../models/base.h"

// A class for reading and writing pizza base classes

using namespace std;

class BaseIO {
    public:
        BaseIO();
        void append_to_file(const Base& base);
        Base* read_file();
        int number_of_entries();

    private:
        string file;
        ofstream fout;
        ifstream fin;
        bool file_exists();
};

#endif
