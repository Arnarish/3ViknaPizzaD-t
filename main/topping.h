#ifndef _H
#define _H

using namespace std;

class Topping {
    public:
        Topping();
        Topping(string name, int price);
        string get_name();
        int get_price();
        void set_name(string name);
        void set_price(int price);

    private:
        string name;
        int price;
};

#endif
