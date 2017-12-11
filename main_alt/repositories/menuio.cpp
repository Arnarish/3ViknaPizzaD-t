#include "menuio.h"

using namespace std;

MenuIO::MenuIO() {
    file = "./data/menu.dat";
    ifstream fin;
    ofstream fout;
}

void MenuIO::append_to_file(Pizza& pizza) {
    // Append a single Pizza class to the menu.dat file
    fout.open(file, ios::binary | ios::app);
    if (fout.is_open()) {
        // The pizza class isn't a POD, so we have to dismantle it
        char name[128];
        vector<Topping> toppings = pizza.get_toppings();
        int topping_count = toppings.size();
        Base base = pizza.get_base();
        string s = pizza.get_name();
        strcpy(name, s.c_str());

        // Write the name of the pizza
        fout.write((char*)(&name), sizeof(name));
        // Next we write the base
        fout.write((char*)(&base), sizeof(Base));

        // Since has a dynamically allocated vector of toppings, 
        // we need to write how many toppings the reader is going
        // to expect eventually when we need to read from the file
        fout.write((char*)(&topping_count), sizeof(int)); 
        // Write the contents of the toppings vector inside pizza
        fout.write((char*)(&toppings[0]), sizeof(Topping) * topping_count);

        // The file now contains enough information to recreate the Pizza class
        // once we eventually read it again
        fout.close();
        return;
    }
    else {
        cout << "could not open" << endl;
    }
    // TODO: throw FileWriteException();
}

vector<Pizza> MenuIO::read_file() {
    vector<Pizza> v;
    if (!file_exists()) {
        // If the file doesn't exist, throw an exception
        // throw FileExistsException();
        cout << "file exist error";
        return v;
    }
    fin.open(file.c_str(), ios::binary);
    if (fin.is_open()) {
        fin.clear(); // Clear any flags that fin may have set last run
        fin.seekg(0, fin.end);
        int end_position = fin.tellg();
        fin.seekg(0); // Go to the beginning of the file
        int current_position = fin.tellg();
        cout << current_position << endl;
        while (current_position != end_position) {
            char name[128];
            int topping_count;
            vector<Topping> toppings;
            Topping t;
            Base base;

            fin.read((char*)(&name), sizeof(name)); // Read the name of the pizza
            fin.read((char*)(&base), sizeof(Base)); // Read what base the pizza has

            string s = name;
            Pizza p(s, base);

            fin.read((char*)&topping_count, sizeof(int)); // Read how many toppings to expect
            // TODO: do this in one IO operation
            for (int i = 0; i < topping_count; i++) {
                fin.read((char*)(&t), sizeof(Topping));
                p.add_topping(t);
            }
            v.push_back(p);
            current_position = fin.tellg();
        }
        fout.close();
        return v;
    }
    cout << "file read error?";
    return v;
    //throw FileReadException();
}

bool MenuIO::file_exists() {
    //Check if the file exists
    ifstream infile(file);
    return infile.good();
}

