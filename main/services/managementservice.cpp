#include "managementservice.h"

using namespace std;

void ManagementService::create_new_base(string name, int size, int price) {
    if (name == "" || name.size() > 127) {
        throw InvalidNameException();
    }
    if (size < 0 || size > 1572) {
        // https://www.eater.com/2012/5/9/6588321/the-worlds-largest-pizza-ever-weighed-26883-lbs
        throw InvalidSizeException();
    }
    if (price < 0) {
        // We're running a business here, so I won't put an upper bound on the price
        throw InvalidPriceException();
    }
    Base b(name, price, size);
    baseio.append_to_file(b);

    return;
}

vector<Base> ManagementService::get_all_bases() {
    Base* b = baseio.read_file();
    int n = baseio.number_of_entries();
    if (n == 0) {
        throw FileEmptyException();
    }
    // Constructing a vector of size n is faster than
    // creating an empty vector and resizing it, I think
    vector<Base> bases(n);
    for (int i = 0; i < n; i++) {
        bases[i] = b[i];
    }
    return bases;
}

vector<Topping> ManagementService::get_all_toppings() {
    Topping* t = toppingio.read_file();
    int n = toppingio.number_of_entries();
    if (n == 0) {
        throw FileEmptyException();
    }
    vector<Topping> toppings(n);
    for (int i = 0; i < n; i++) {
        toppings[i] = t[i];
    }
    return toppings;
}


void ManagementService::create_new_topping(string name, int price) {
    if (name == "" || name.size() > 127) {
        throw InvalidNameException();
    }
    if (price < 0) {
        // We're running a business here, so I won't put an upper bound on the price
        throw InvalidPriceException();
    }
    Topping t(name, price);
    toppingio.append_to_file(t);
}

void ManagementService::create_new_menu_item(string name, int b, vector<int> t) {
    Base* bases = baseio.read_file();
    Topping* toppings = toppingio.read_file();

    Pizza pizza(bases[b]);
    for (unsigned int i = 0; i < t.size(); i++) {
        pizza.add_topping(toppings[t[i]]);
    }
    delete[] bases;
    delete[] toppings;
    pizza.set_name(name);
    menuio.append_to_file(pizza);
}

void ManagementService::add_new_store_location(string new_location, int postcode) {
    location_service.create_new_location(new_location, postcode);
}

void ManagementService::create_new_product(string name, int price, int category) {
    if (name == "" || name.size() > 127) {
        // Invalid name, throw an exception
        throw InvalidNameException();
    }
    if (price < 0) {
        // We're running a business here, so I won't put an upper bound on the price
        throw InvalidPriceException();
    }
    if (category < 0 || category > 2)
    {
        // Invalid category, must be 0, 1 or 2
        throw InvalidCategoryException();
    }
    char c;
    switch (category) {
        case 0:
            c = 'd'; // Drinks category
            break;
        case 1:
            c = 's'; // Sides category
            break;
        case 2:
            c = 'o'; // Other category
            break;
    }
    Product p(name, c, price);
    productio.append_to_file(p);
}

