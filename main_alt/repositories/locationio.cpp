#include "locationio.h"

locationio::locationio() {
    file = "./data/locations.dat";
    ifstream fin;
    ofstream fout;
}

void locationio::append_to_file(const location& loc) {
    // Append a single Base class to the bases.dat file
    fout.open(file, ios::binary | ios::app);
    if (fout.is_open()) {
        fout.write((char*)(&loc), sizeof(location));
        fout.close();
        return;
    }
    else {
        cout << "could not open" << endl;
    }
    // TODO: throw FileWriteException();
}

location* locationio::read_file() {
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        // throw FileExistsException();
        cout << "file exist error";
        return (location*)0xDEADBEEF;
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int r = fin.tellg() / sizeof(location);
        fin.seekg(0, fin.beg);
        location* locations = new location[r];
        fin.read((char*)(locations), sizeof(location) * r);
        fin.close();

        /*for(int i=0; i< r; i++) {
            cout << locations[i].get_location() << endl;
        }*/
        cout << "test 5" << endl;
        return locations;
    }
    cout << "dunno what happened here";
    return (location*)0xDEADBEEF;
    //throw FileReadException();
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
