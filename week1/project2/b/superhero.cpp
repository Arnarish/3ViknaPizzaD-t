#include <iostream>
#include <cstring>
#include "superhero.h"

using namespace std;

Superhero::Superhero() {
    strcpy(name, "");
    power = 'n';
    age = 0;
}

Superhero::Superhero(string _name, char _power, int _age) {
    strcpy(name, _name.c_str());
    power = _power;
    age = _age;
}

char Superhero::get_power() {
    return power;
}

string Superhero::get_name() {
    return name;
}

int Superhero::get_age() {
    return age;
}

ostream& operator << (ostream& out, const Superhero& sh) {
    out << sh.name << " " << "(" << sh.age << "):" << " ";
    switch (sh.power) {
        case 'f':
            out << "Flying";
            break;

        case 'g':
            out << "Giant";
            break;
            
        case 'h':
            out << "Hacker";
            break;
            
        case 'n':
            out << "None";
            break;
            
        default:
            out << "Weakling";
            break;
    }
    return out;
}

istream& operator >> (istream& in, Superhero& sh) {
    cout << "Please enter a name: ";
    cin >> sh.name;
    cout << "Please enter an age: ";
    in >> sh.age;
    cout << "Please enter a superpower: ";
    in >> sh.power;
    return in;
}
