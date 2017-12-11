#include "locationio.h"

locationio::locationio() {
    file = "./data/locations.dat";
    ifstream fin;
    ofstream fout;
}

void locationio::append_to_file(string location) {
    char loc[128];
    strcpy(loc, location.c_str());
    // Append a single Base class to the bases.dat file
    fout.open(file, ios::binary | ios::app);
    if (fout.is_open()) {
        fout.write((char*)(&loc), sizeof(char[128]));
        fout.close();
        return;
    }
    else {
        cout << "could not open" << endl;
    }
    // TODO: throw FileWriteException();
}

int locationio::number_of_entries() {
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        return -1;
        //throw FileExistsException();
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int n = fin.tellg() / sizeof(char[128]);
        fin.seekg(0, fin.beg);

        fin.close();
        return n;
    }
    return -1;
}

bool locationio::file_exists() {
    //Check if the file exists
    ifstream infile(file);
    return infile.good();
}