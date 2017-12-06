#include "recordwriter.h"


RecordWriter::RecordWriter() {
    #if _WIN32
    file = ".\\data\\records.dat";
    #else
    file = "./data/records.dat";
    #endif // _WIN32
    ofstream fout;
}

void RecordWriter::append_to_file(Salary& salary) {
    fout.open(file.c_str(), ios::binary | ios::app);
    if (fout.is_open()) {
        fout.write((char*)(&salary), sizeof(Salary));
    }
    else {
        if(!fout.is_open())
        {
            throw FileWriteException();
        }
    }
    fout.close();
}

void RecordWriter::write_entire_file(Salary* salaries, int n) {
    fout.open(file.c_str(), ios::binary | ios::trunc);
    if (fout.is_open()) {
        fout.write((char*)salaries, sizeof(Salary) * n);
    }
    else {
        if(!fout.is_open())
        {
            throw FileWriteException();
        }
    }
    fout.close();
}
