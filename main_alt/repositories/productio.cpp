#include "productio.h"

ProductIO::ProductIO() {
    file = "./data/product.dat";
    ifstream fin;
    ofstream fout;
}

void ProductIO::append_to_file(const Product& product) {
    // Append a single Base class to the bases.dat file
    fout.open(file, ios::binary | ios::app);
    if (fout.is_open()) {
        fout.write((char*)(&product), sizeof(Product));
        fout.close();
        return;
    }
    else {
        cout << "could not open" << endl;
    }
    // TODO: throw FileWriteException();
}

int ProductIO::number_of_entries() {
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        return -1;
        //throw FileExistsException();
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int n = fin.tellg() / sizeof(Product);
        fin.seekg(0, fin.beg);

        fin.close();
        return n;
    }
    return -1;
    //throw FileReadException();
}

Product* ProductIO::read_file() {
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        // throw FileExistsException();
        cout << "file exist error";
        return (Product*)0xDEADBEEF;
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int r = fin.tellg() / sizeof(Product);
        fin.seekg(0, fin.beg);

        Product* products = new Product[r];
        fin.read((char*)products, sizeof(Product) * r);
        fin.close();

        return products;
    }
    cout << "dunno what happened here";
    return (Product*)0xDEADBEEF;
    //throw FileReadException();
}

bool ProductIO::file_exists() {
    //Check if the file exists
    ifstream infile(file);
    return infile.good();
}
