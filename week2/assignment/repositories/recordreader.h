#ifndef RECORDREADER_H
#define RECORDREADER_H

#include <string>
#include <fstream>
#include "../models/salary.h"

using namespace std;

class RecordReader {
    public:
        RecordReader();
        ~RecordReader();
        Salary* read_file();
        int entries();

    private:
        string file;
        ifstream fin;
};

#endif
