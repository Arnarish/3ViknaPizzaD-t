#include "orderservice.h"

using namespace std;

OrderDetails OrderService::create_details(string name, string phone, string address,
                                  string location, int zipcode) {

        if (name == "" || name.size() > 127) {
        // Invalid name, throw an exception
        // throw InvalidNameException();
        }

        if(phone == "" || (phone.length() > 8 || phone.length() < 6)) { // check if string is empty, or number has invalid length
           //throw CustomerPhoneException();
        }
        bool isNumber = true;
        for(unsigned int i=0; i < phone.length(); i++) { // check if phone has non numerals
            if(!isalnum(phone[i])) {
                isNumber = false;
                break;
            }
            if(isNumber == false) {
            //thow CustomerPhoneException)(;
            }
        }
        if(address == "" || address.size() > 127) {
            //throw CustomerAddressException();
        }
        if(location == "" || location.size() > 127) {
            //throw InvalidLocationException();
        }
        if(zipcode > 999 || zipcode < 99) {
            //throw CustomerZipcodeException();
        }
        // Try catch for validation
    //TODO: validate EVERYTHING and throw exceptions
    OrderDetails details(name, phone, address, location, zipcode);
    return details;
}

vector<Order> OrderService::all_orders() {
    vector<Order> all_orders = orderio.read_file();
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

int OrderService::Product_entries() {
    int p = productio.number_of_entries();
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
