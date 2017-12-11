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
    int s;
    Base* bases = baseio.read_file();
    int b = baseio.number_of_entries();
    while (true) {
        cout << "Available pizza bases: " << endl;
        for (int i = 0; i < b; i++) {
            cout << i + 1 << ": " << bases[i];
        }
        cout << "Selection: ";
        cin >> s;
        if (s < 1 || s > (b + 1)) {
            cout << "Invalid selection!" << endl;
        }
        else {
            break;
        }
    }
    Pizza p(bases[s - 1]);
    delete[] bases;

    Topping* toppings = toppingio.read_file();
    int t = toppingio.number_of_entries();
    while (true) {
        for (int i = 0; i < t; i++) {
            cout << (i + 1) << ": " << toppings[i] << endl;
        }
        cout << "Add toppings or enter 0 to stop: ";
        cin >> s;
        if (s == 0) {
            break;
        }
        else if (s < 0 || s > (t + 1)) {
            cout << "Invalid selection" << endl;
        }
        else {
            p.add_topping(toppings[s - 1]);
        }
    }
    string name;

    cout << "Pizza price: " << p.get_price() << " kr" << endl;
    cout << "Name of pizza: ";
    cin >> name;
    p.set_name(name);
    menuio.append_to_file(p);

    vector<Pizza> zas = menuio.read_file();
    cout << "Number of pizzas on the menu: " << zas.size() << endl;
    for (unsigned int i = 0; i < zas.size(); i++) {
        cout << zas[i] << endl;
    }
}

/*

void ManagementService::create_new_product(string name, int price) {

}
*/