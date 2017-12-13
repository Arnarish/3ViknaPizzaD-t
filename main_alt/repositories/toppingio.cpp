#include "toppingio.h"

using namespace std;

ToppingIO::ToppingIO() {
    file = "../data/toppings.dat";
    ifstream fin;
    ofstream fout;
}

void ToppingIO::append_to_file(const Topping& topping) {
    fout.open(file, ios::binary | ios::app);
    if (fout.is_open()) {
        fout.write((char*)(&topping), sizeof(Topping));
        fout.close();
        return;
    }
    else {
        //if unable to read file.
        throw FileWriteException();
    }
}

Topping* ToppingIO::read_file() {
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        throw FileExistsException();
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int r = fin.tellg() / sizeof(Topping);
        fin.seekg(0, fin.beg);

        Topping* toppings = new Topping[r];
        fin.read((char*)toppings, sizeof(Topping) * r);
        fin.close();

        return toppings;
    }
    throw FileReadException();
}

int ToppingIO::number_of_entries() {
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        throw FileExistsException();
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int n = fin.tellg() / sizeof(Topping);
        fin.seekg(0, fin.beg);

        fin.close();
        return n;
    }
    throw FileReadException();
}

bool ToppingIO::file_exists() {
    //Check if the file exists
    ifstream infile(file);
    return infile.good();
}


