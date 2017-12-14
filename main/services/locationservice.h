#ifndef LOCATIONSERVICE_H
#define LOCATIONSERVICE_H

#include <vector>
#include <cmath>
#include "../models/location.h"
#include "../repositories/locationio.h"
#include "../exceptions/InvalidLocationException.h"
#include "../exceptions/InvalidPostcodeException.h"

class LocationService
{
    public:
        LocationService();
        Location* get_location_list();
        void create_new_location(string location, int postcode);
        int number_of_entries();
        string find_nearest_store(int postcode);

    private:
        LocationIO locationio;
};

#endif // LOCATIONSERVICE_H
