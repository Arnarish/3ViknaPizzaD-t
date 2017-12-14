#include "locationio.h"

LocationIO::LocationIO() {
    file = "./data/locations.dat";
    ifstream fin;
    ofstream fout;
}

void LocationIO::append_to_file(const Location& loc) {
    // Append a single Base class to the bases.dat file
    fout.open(file, ios::binary | ios::app);
    if (fout.is_open()) {
        fout.write((char*)(&loc), sizeof(Location));
        fout.close();
        return;
    }
    throw FileWriteException();
}

Location* LocationIO::read_file() {
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        throw FileExistsException();
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int r = fin.tellg() / sizeof(Location);
        fin.seekg(0, fin.beg);
        Location* locations = new Location[r];
        fin.read((char*)(locations), sizeof(Location) * r);
        fin.close();
        return locations;
    }
    throw FileReadException();
}

int LocationIO::number_of_entries() {
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        throw FileExistsException();
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int n = fin.tellg() / sizeof(char[128]);
        fin.seekg(0, fin.beg);
        fin.close();
        return n;
    }
    throw FileReadException();
}

bool LocationIO::file_exists() {
    //Check if the file exists
    ifstream infile(file);
    return infile.good();
}
