#include <iostream>
#include "superhero.h"

using namespace std;

Superhero::Superhero() {
    name = "";
    power = 'n';
    age = 0;
}

Superhero::Superhero(string _name, char _power, int _age) {
    name = _name;
    power = _power;
    age = _age;
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
    in >> sh.name;
    cout << "Please enter an age: ";
    in >> sh.age;
    cout << "Please enter a superpower: ";
    in >> sh.power;
    return in;
}
