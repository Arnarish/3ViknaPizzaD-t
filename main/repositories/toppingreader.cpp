#include "toppingreader.h"

toppingreader::toppingreader()
{
    file = "toppings.dat";
    ifstream fin;
}

Topping* toppingreader::read_file()
{
    fin.open(file, ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int r = fin.tellg() / sizeof(Topping);
        fin.seekg(0, fin.beg);


        Topping* toppings = new Topping[r];
        fin.read((char*)toppings, sizeof(Topping) * r);
        fin.close();

        return toppings;
    }
    // vantar throw exception
}

int toppingreader::entries()
{
    fin.open(file, ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int n = fin.tellg() / sizeof(Topping);
        fin.seekg(0, fin.beg);

        fin.close();
        return n;
    }
    return -1; // throw exception
}

bool toppingreader::file_exists()
{
    //Check if the file exists
    ifstream infile(file);
    return infile.good();
}
