#ifndef _H
#define _H

using namespace std;

class Superhero {
    public:
        Superhero();
        Superhero(string _name, char _power, int _age);
        string get_name();
        char get_power();
        int get_age();

    private:
        string name;
        char power;
        int age;

        friend ostream& operator << (ostream& out, const Superhero& sh);
        friend istream& operator >> (istream& in, Superhero& sh);
};

#endif
