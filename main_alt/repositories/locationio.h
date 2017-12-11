#ifndef LOCATIONIO_H
#define LOCATIONIO_H

#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

class locationio
{
    public:
        locationio();
        int number_of_entries();
        void append_to_file(const string location);
        char read_file();

    private:
        string file;
        ofstream fout;
        ifstream fin;
        bool file_exists();
};

#endif // LOCATIONIO_H
