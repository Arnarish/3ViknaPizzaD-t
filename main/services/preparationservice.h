#ifndef PREPARATIONSERVICE_H
#define PREPARATIONSERVICE_H

#include "../models/order.h"
#include "../models/location.h"
#include "../repositories/orderio.h"

using namespace std;

class PreparationService {
    public:
        void process_earliest_order(Order& order);
        vector<Order> get_orders_by_location(Location location, vector<Order> orders);
    private:
        OrderIO orderio;
};

#endif
