#include "deliveryservice.h"

Order DeliveryService::get_order_by_phone_number(vector<Order>& orders, string phone) {
    // First we validate
    if (phone.size() != 7) {
        throw CustomerPhoneException();
    }
    for (int i = 0; i < 7; i++) {
        if (!isalnum(phone[i])) {
            throw CustomerPhoneException();
        }
    }
    for (unsigned int i = 0; i < orders.size(); i++) {
        cout << orders[i].get_details().get_phone() << endl;
        if (orders[i].get_details().get_phone() == phone) {
            if (orders[i].get_details().get_address() == "Pick-up") {
                return orders[i];
            }
            else {
                throw UserInputException();
            }
        }
    }
    throw MissingOrderException();
}

void DeliveryService::process_order(Order& order) {
    bool found = false;
    orderio.set_ready(); // Change to the ready.dat file
    string orderphone = order.get_details().get_phone();
    string orderlocation = order.get_location();
    vector<Order> orders = orderio.read_file();
    orderio.truncate_file(); // TRUNCATE IT
    // Rewrite everything to the file
    for (unsigned int i = 0; i < orders.size(); i++) {
        if (orders[i].get_details().get_phone() == orderphone 
            && !found && orders[i].get_location() == orderlocation) {
                // In the (extremely) unlikely case that there are two (or more) orders
                // made on the same phone number at the same location at the
                // same time, we don't want to process ALL of them
                found = true;
                continue;
        }
        orderio.write_to_file(orders[i]);
    }

    orderio.set_history(); // Change to the history.dat file
    orderio.write_to_file(order);
    orderio.set_ordered(); // Always change back to the ordered file 
}

void DeliveryService::update_paid(Order& order, vector<Order> all_orders) {
    OrderDetails deets = order.get_details();
    for (unsigned int i = 0; i < all_orders.size(); i++) {
        OrderDetails d = all_orders[i].get_details();
        if (deets.get_location() == d.get_location()
            && deets.get_phone() == d.get_phone()) {

            all_orders[i].set_paid(true);
        }
    }
    // Rewrite everything to the ready file
    orderio.set_ready();
    orderio.truncate_file();
    for (unsigned int i = 0; i < all_orders.size(); i++) {
        orderio.write_to_file(all_orders[i]);
    }
    orderio.set_ordered();
}


vector<Order> DeliveryService::get_orders_by_location(
    Location location, vector<Order> orders) {
    vector<Order> v;
    for (unsigned int i = 0; i < orders.size(); i++) {
        if (location.get_location() == orders[i].get_location()) {
            v.push_back(orders[i]);
        }
    }
    return v;
}
