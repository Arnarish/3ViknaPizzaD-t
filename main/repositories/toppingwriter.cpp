#include "toppingwriter.h"

toppingwriter::RecordWriter() {
    file = "./data/toppings.dat";
    ofstream fout;
}

void toppingwriter::append_to_file(Topping& topping) {
    fout.open(file.c_str(), ios::binary | ios::app);
    if (fout.is_open()) {
        fout.write((char*)(&topping), sizeof(Topping));
        fout.close();
        return;
    }
    else {
        cout << "could not open" << endl;
    }
    //eftir að gera exception
    //throw FileWriteException();
}

void toppingwriter::write_entire_file(Topping* topping, int n) {
    fout.open(file.c_str(), ios::binary | ios::trunc);
    if (fout.is_open()) {
        fout.write((char*)topping, sizeof(Topping) * n);
        fout.close();
        return;
    }
    else {
        cout << "elska smjör" << endl;
    }
    //eftir að gera exception
    //throw FileWriteException();
}
