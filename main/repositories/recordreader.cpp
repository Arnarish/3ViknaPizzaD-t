#include "recordreader.h"

RecordReader::RecordReader() {
    file = "./data/orders.dat";
    ifstream fin;
}

Salary* RecordReader::read_file() {
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        throw FileExistsException();
    }
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
    throw FileReadException();
}

int RecordReader::entries() {
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        throw FileExistsException();
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int n = fin.tellg() / sizeof(Salary);
        fin.seekg(0, fin.beg);

        fin.close();
        return n;
    }
    throw FileReadException();
}

bool RecordReader::file_exists() {
    //Check if the file exists
    ifstream infile(file);
    return infile.good();
}
