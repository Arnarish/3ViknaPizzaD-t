#ifndef DELIVERYSERVICE_H
#define DELIVERYSERVICE_H

#include "../models/order.h"
#include "../models/location.h"
#include "../repositories/orderio.h"
#include "../exceptions/MissingOrderException.h"
#include "../exceptions/CustomerPhoneException.h"
#include "../exceptions/UserInputException.h"

using namespace std;

class DeliveryService {
    public:
        Order get_order_by_phone_number(vector<Order>& orders, string phone);
        vector<Order> get_orders_by_location(Location location, vector<Order> orders);
        void update_paid(Order& order, vector<Order> all_orders);
        void write_all_orders(vector<Order>& orders);
        void process_order(Order& order);
    private:
        OrderIO orderio;
};

#endif
