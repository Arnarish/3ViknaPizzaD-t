#include <iostream>
#include <fstream>
#include "superhero.h"

using namespace std;

void create_and_insert() {
    ofstream fout;
    fout.open("heroes.txt", ios::app);
    if (fout.is_open()) {
        string s;
        int    i;
        char   c;

        cin >> s >> i >> c;
        fout << s << " "
             << i << " "
             << c << endl;
        fout.close();
    }
    else {
        cout << "Unable to write to file!" << endl;
    }
}

void read_from_file() {
    string name;
    char power;
    int age;

    ifstream fin;
    fin.open("heroes.txt");
    if (fin.is_open()) {
        while (!fin.eof()) {
            fin >> name >> age >> power;
            Superhero sh(name, power, age);
            cout << sh << endl;
        }
        fin.close();
    }
    else {
        cout << "Unable to read from file!" << endl;
    }
    
}

int main(void)
{
    char selection;
    while (true) {
        cout << "1. Create a new hero\n"
             << "2. Insert a new hero into the archives\n"
             << "3. Print the archives\n"
             << "4. Quit\n"
             << "Please make a selection: ";
        cin >> selection;
        if (selection == '1') {
            Superhero super;
            cin >> super;
            cout << super << endl;
        }

        else if (selection == '2') {
            create_and_insert();
        }

        else if (selection == '3') {
            read_from_file();
        }

        else if (selection == '4') {
            cout << "Bye!" << endl;
            break;
        }

        else {
            cout << "Invalid selection!\n" << endl;
        }
    }

    return 0;
}
