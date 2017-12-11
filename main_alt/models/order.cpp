#include "order.h"

using namespace std;

Order::Order(string customer_address, string customer_name, string phone_no, string location) {
    strcpy(this->customer_address, customer_address.c_str());
    strcpy(this->customer_name, customer_name.c_str());
    strcpy(this->phone_no, phone_no.c_str());
    strcpy(this->location, location.c_str());
}

int Order::get_price() {
    return 1;
}

string Order::get_location() {
    return "ye";
}

int Order::get_priority() {
    return priority;
}

void Order::add_pizza(Pizza& p) {
    pizzas.push_back(p);
}

void Order::add_product(Product& p) {
    products.push_back(p);
}

void Order::set_in_progress() {
    status = 'P';
}

void Order::set_ready() {
    status = 'R';
}

void Order::set_delivered() {
    status = 'D';
}

ostream& operator << (ostream& out, Order& o) {
    return out;
}
