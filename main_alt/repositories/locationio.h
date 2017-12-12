#ifndef LOCATIONIO_H
#define LOCATIONIO_H

#include "../models/location.h"

#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class locationio
{
    public:
        locationio();
        int number_of_entries();
        void append_to_file(const location& loc);
        location* read_file();

    private:
        string file;
        ofstream fout;
        ifstream fin;
        bool file_exists();
        location Location;

};

#endif // LOCATIONIO_H
