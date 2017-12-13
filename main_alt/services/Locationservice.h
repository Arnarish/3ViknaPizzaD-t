#ifndef LOCATIONSERVICE_H
#define LOCATIONSERVICE_H

#include "../models/location.h"
#include "../repositories/locationio.h"
#include <vector>
#include "../exceptions/InvalidLocationException.h"
#include "../exceptions/InvalidPostcodeException.h"

class LocationService
{
    public:
        LocationService();
        Location* get_location_list();
        void create_new_location(string location, int postcode);

    private:
        LocationIO LocIO;

};

#endif // LOCATIONSERVICE_H
