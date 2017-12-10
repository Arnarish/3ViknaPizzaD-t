#include "managementservice.h"

using namespace std;

void ManagementService::create_new_base(string name, int size, int price) {
    if (name == "" || name.size() > 127) {
        // Invalid name, throw an exception
        // throw InvalidNameException
        return;
    }
    if (size < 0 || size > 1572) {
        // https://www.eater.com/2012/5/9/6588321/the-worlds-largest-pizza-ever-weighed-26883-lbs
        // throw InvalidSizeException
        return;
    }
    if (price < 0) {
        // We're running a business here, so I won't put an upper bound on the price
        // throw InvalidPriceException
        return;
    }

    Base b(name, price, size);
    baseio.append_to_file(b);

    Base* bases = baseio.read_file();
    int n = baseio.number_of_entries();
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << bases[i] << endl;
    }
    return;
}


void ManagementService::create_new_topping(string name, int price) {
    if (name == "" || name.size() > 127) {
        // Invalid name, throw an exception
        // throw InvalidNameException
        return;
    }
    if (price < 0) {
        // We're running a business here, so I won't put an upper bound on the price
        // throw InvalidPriceException
        return;
    }
    Topping t(name, price);
    toppingio.append_to_file(t);

    Topping* toppings = toppingio.read_file();
    int n = toppingio.number_of_entries();
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << toppings[i] << endl;
    }

}

void ManagementService::create_new_menu_item() {
    Base b("Thin", 16, 1000);
    Pizza p("Good pizza", b);
    Topping t1("Pepperoni", 250);
    Topping t2("Ham", 200);
    Topping t3("Pepper cheese", 150);
    p.add_topping(t1);
    p.add_topping(t2);
    p.add_topping(t3);
    menuio.append_to_file(p);
    vector<Pizza> zas = menuio.read_file();
    cout << "'zas: " << zas.size() << endl;
    for (unsigned int i = 0; i < zas.size(); i++) {
        cout << zas[i] << endl;
    }
}

/*

void ManagementService::create_new_product(string name, int price) {

}
*/
