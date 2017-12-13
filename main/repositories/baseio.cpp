#include "baseio.h"

using namespace std;

BaseIO::BaseIO() {
    file = "./data/bases.dat";
    ifstream fin;
    ofstream fout;
}

void BaseIO::append_to_file(const Base& base) {
    // Append a single Base class to the bases.dat file
    fout.open(file, ios::binary | ios::app);
    if (fout.is_open()) {
        fout.write((char*)(&base), sizeof(Base));
        fout.close();
        return;
    }
    else {
        throw FileWriteException();
    }
}

Base* BaseIO::read_file() {
    if (!file_exists()) {
        throw FileExistsException();
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int r = fin.tellg() / sizeof(Base);
        fin.seekg(0, fin.beg);

        Base* bases = new Base[r];
        fin.read((char*)bases, sizeof(Base) * r);
        fin.close();

        return bases;
    }
    throw FileReadException();
}

int BaseIO::number_of_entries() {
    if (!file_exists()) {
        throw FileExistsException();
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int n = fin.tellg() / sizeof(Base);
        fin.seekg(0, fin.beg);

        fin.close();
        return n;
    }
    throw FileReadException();
}

bool BaseIO::file_exists() {
    //Check if the file exists
    ifstream infile(file);
    return infile.good();
}

