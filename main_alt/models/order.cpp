#include "order.h"

using namespace std;

Order::Order(OrderDetails& details) {
    this->details = details;
}

int Order::get_price() {
    int n = 0;
    for (unsigned int i = 0; i < pizzas.size(); i++) {
        n += pizzas[i].get_price();
    }
    for (unsigned int i = 0; i < products.size(); i++) {
        n += products[i].get_price();
    }
    return n;
}

string Order::get_location() {
    return details.get_location();
}

bool Order::get_priority() {
    return priority;
}

bool Order::get_paid() {
    return paid;
}

void Order::add_pizza(Pizza& p) {
    pizzas.push_back(p);
}

void Order::add_product(Product& p) {
    products.push_back(p);
}

void Order::add_comments(string comments) {
    details.add_comments(comments);
}

vector<Pizza> Order::get_pizzas() {
    return pizzas;
}

vector<Product> Order::get_products() {
    return products;
}

OrderDetails Order::get_details() {
    return details;
}

void Order::set_paid(bool p) {
    paid = p;
}

void Order::set_priority(bool p) {
    priority = p;
}

ostream& operator << (ostream& out, Order& o) {
    out << o.details << "\n"
        << "Pizzas in order: " << o.pizzas.size() << "\n"
        << "Total: " << o.get_price() << " kr";
    return out;
}
