#include "order.h"

using namespace std;

Order::Order() { 
    paid = false;
}

Order::Order(OrderDetails& details) {
    this->details = details;
    paid = false;
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

ostream& operator << (ostream& out, Order& o) {
    out << o.details << "\n";
    for (unsigned int i = 0; i < o.pizzas.size(); i++) {
        cout << o.pizzas[i] << "\n";
    }
    if (o.products.size() > 0) {
        for (unsigned int i = 0; i < o.products.size(); i++) {
            cout << " - " << o.products[i];
        }
    }
    out << "\nORDER TOTAL: " << o.get_price() << " kr\n"
        << "------------------------------------------------------";
    return out;
}
