#include "Toppingwriter.h"

Toppingwriter::RecordWriter() {
    file = "toppings.dat";
    ofstream fout;
    return 0;
}

void Toppingwriter::append_to_file(const Topping& topping) {
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

void Toppingwriter::write_entire_file(Topping* topping, int n) {
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
