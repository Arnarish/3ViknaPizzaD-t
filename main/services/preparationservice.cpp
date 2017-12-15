#include "preparationservice.h"

using namespace std;

void PreparationService::process_earliest_order(Order& order) {
    bool found = false;
    // This function reads the entire order file, pops out the first order
    // and then rewrite the entire file with the rest of the orders
    // there's no "efficient" way of doing this
    vector<Order> orders = orderio.read_file();
    cout << orders.size() << endl;
    orderio.truncate_file();

    OrderDetails deets = order.get_details();
    for (unsigned int i = 0; i < orders.size(); i++) {
        OrderDetails d = orders[i].get_details();
        if (d.get_location() != deets.get_location()
            && d.get_phone() != deets.get_phone()) {

            orderio.write_to_file(orders[i]);
        }
        else if (found) {
            orderio.write_to_file(orders[i]);
        }
        else {
            found = true;
        }
    }
    orderio.set_ready();
    orderio.write_to_file(order);
    orderio.set_ordered();
}

vector<Order> PreparationService::get_orders_by_location(
    Location location, vector<Order> orders) {
    vector<Order> v;
    for (unsigned int i = 0; i < orders.size(); i++) {
        if (location.get_location() == orders[i].get_location()) {
            v.push_back(orders[i]);
        }
    }
    return v;
}
