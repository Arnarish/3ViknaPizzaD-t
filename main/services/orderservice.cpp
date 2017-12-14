#include "orderservice.h"

using namespace std;

OrderDetails OrderService::create_details(string name, string phone, string address,
                                          string location, int zipcode) {
    if (name == "" || name.size() > 127) {
        // Invalid name, throw an exception
        throw InvalidNameException();
    }
    if(phone == "" || (phone.length() > 8 || phone.length() < 6)) {
        // check if string is empty, or number has invalid length
        throw CustomerPhoneException();
    }
    bool isNumber = true;
    for(unsigned int i=0; i < phone.length(); i++) { // check if phone has non numerals
        if(!isalnum(phone[i])) {
            isNumber = false;
            break;
        }
        if(isNumber == false) {
            throw CustomerPhoneException();
        }
    }
    if(address == "" || address.size() > 127) {
        throw CustomerAddressException();
    }
    if(location == "" || location.size() > 127) {
        throw InvalidLocationException();
    }
    if(zipcode > 999 || zipcode < 99) {
        throw CustomerZipcodeException();
    }
    OrderDetails details(name, phone, address, location, zipcode);
    return details;
}

vector<Order> OrderService::get_ordered() {
    // Returns all the orders in the ordered.dat file
    orderio.set_ordered();
    return orderio.read_file();
}

vector<Order> OrderService::get_ready() {
    // Returns all the orders in the ready.dat file
    orderio.set_ready();
    vector<Order> orders = orderio.read_file();
    // I like to retun this back to the ordered file state
    // What file the IO class is set to won't be unpredictable then
    orderio.set_ordered();
    return orders;
}

vector<Order> OrderService::get_history() {
    // Returns all the orders in the history.dat file
    void set_history();
    vector<Order> orders = orderio.read_file();
    orderio.set_ordered();
    return orders;
}

Base* OrderService::read_base(){
    Base* bases = baseio.read_file();
    return bases;
}

int OrderService::base_entries() {
    int b = baseio.number_of_entries();
    return b;
}

int OrderService::topping_entries() {
    int t = toppingio.number_of_entries();
    return t;
}

int OrderService::product_entries() {
    return productio.number_of_entries();
}

Topping* OrderService::read_topping() {
    Topping* toppings = toppingio.read_file();
    return toppings;
}

vector<Pizza> OrderService::pizza_menu() {
    vector<Pizza> menu = menuio.read_file();
    return menu;
}

Product* OrderService::product_menu() {
    Product* menu = productio.read_file();
    return menu;
}

void OrderService::write_order(Order& order) {
    orderio.write_to_file(order);
}

vector<string> OrderService::products_drinks() { // filters the product menu to drinks only
    Product* menu = product_menu();
    int n = product_entries();
    vector<string> drinks;
    for(int i=0; i < n; i++) {
        if(menu[i].get_category() == 'd') {
            drinks.push_back(menu[i].get_name());
        }
    }
    return drinks;
}

vector<string> OrderService::products_sides() { // filters the product menu to sides only
    Product* menu = product_menu();
    int n = product_entries();
    vector<string> sides;
    for(int i=0; i < n; i++) {
        if(menu[i].get_category() == 's') {
            sides.push_back(menu[i].get_name());
        }
    }
    return sides;
}

vector<string> OrderService::products_other() { // filters the product menu to others
    Product* menu = product_menu();
    int n = product_entries();
    vector<string> other;
    for(int i=0; i < n; i++) {
        if(menu[i].get_category() == 'o') {
            other.push_back(menu[i].get_name());
        }
    }
    return other;
}
