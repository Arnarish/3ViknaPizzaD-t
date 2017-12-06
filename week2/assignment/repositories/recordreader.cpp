#include "recordreader.h"

RecordReader::RecordReader() {
    file = "./data/records.dat";
    ifstream fin;
}

Salary* RecordReader::read_file() {
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int r = fin.tellg() / sizeof(Salary);
        fin.seekg(0, fin.beg);

        Salary* salaries = new Salary[r];
        fin.read((char*)salaries, sizeof(Salary) * r);
        fin.close();

        return salaries;
    }
    else {
        if(!fin.is_open())
        {
            throw FileReadException();
        }
    }
}

int RecordReader::entries() {
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int n = fin.tellg() / sizeof(Salary);
        fin.seekg(0, fin.beg);

        fin.close();
        return n;
    }
    else {
        if(!fin.is_open())
        {
            throw FileReadException();
        }
    }
    return -1; // temporary
}
