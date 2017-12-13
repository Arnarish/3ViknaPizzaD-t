#ifndef LOCATIONIO_H
#define LOCATIONIO_H

#include "../models/location.h"
#include "../exceptions/FileExistsException.h"
#include "../exceptions/FileReadException.h"
#include "../exceptions/FileWriteException.h"

#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class LocationIO
{
    public:
        LocationIO();
        int number_of_entries();
        void append_to_file(const Location& loc);
        Location* read_file();

    private:
        string file;
        ofstream fout;
        ifstream fin;
        bool file_exists();
        Location location;

};

#endif // LOCATIONIO_H
