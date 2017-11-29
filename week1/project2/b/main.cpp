#include <iostream>
#include <fstream>
#include "superhero.h"

using namespace std;

void read_from_file() {
    ifstream fin;
    fin.open("heroes.dat", ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
        int r = fin.tellg() / sizeof(Superhero);
        fin.seekg(0, fin.beg);

        Superhero* supers = new Superhero[r];
        fin.read((char*)supers, sizeof(Superhero) * r);
        fin.close();

        for (int i = 0; i < r; i++) {
            cout << supers[i] << endl;
        }
    }
    else {
        cout << "Unable to read from file!" << endl;
    }
}

void write_to_file(Superhero* supers, int n) {
    ofstream fout;
    fout.open("heroes.dat", ios::binary | ios::app);
    if (fout.is_open()) {
        fout.write((char*)supers, sizeof(Superhero) * n);
    }
    else {
        cout << "Unable to write to file!" << endl;
    }
    fout.close();
    cout << "Hello, write to file" << endl;
}

int main(void)
{
    char selection;
    while (true) {
        cout << "1. Insert heroes\n"
             << "2. Print the archives\n"
             << "3. Quit\n"
             << "Please make a selection: ";
        cin >> selection;
        if (selection == '1') {
            int n;
            cout << "How many heroes would you like to add? ";
            cin >> n;
            Superhero* supers = new Superhero[n];
            for (int i = 0; i < n; i++) {
                cin >> supers[i];
            }
            write_to_file(supers, n);
            delete[] supers;
        }

        else if (selection == '2') {
            read_from_file();
        }

        else if (selection == '3') {
            cout << "Bye!" << endl;
            break;
        }

        else {
            cout << "Invalid selection!\n" << endl;
        }
    }

    return 0;
}
