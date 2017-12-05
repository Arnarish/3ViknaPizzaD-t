#include "recordreader.h"


RecordReader::RecordReader() {
    file = "records.dat";
    ifstream fin;
}
RecordReader::~RecordReader() {

}

Salary* RecordReader::read_file() {
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int r = fin.tellg() / sizeof(Salary);
        fin.seekg(0, fin.beg);

        Salary* salaries = new Salary[r]; //TODO: delete this somehow?
        fin.read((char*)salaries, sizeof(Salary) * r);
        fin.close();

        return salaries;
    }
    else {
        // TODO: throw exception
    }
    return (Salary*)0xDEADBEEF; // temporary!!
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
        // TODO: throw exception
    }
    return -1; // temporary
}
