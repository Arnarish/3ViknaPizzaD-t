#ifndef RECORDWRITER_H
#define RECORDWRITER_H

#include <string>
#include <fstream>
#include "../models/salary.h"
#include "../exceptions/FileWriteException.h"

using namespace std;

class RecordWriter {
    public:
        RecordWriter();
        void append_to_file(Salary& salary);
        void write_entire_file(Salary* salaries, int n);

    private:
        string file;
        ofstream fout;
};

#endif
