#ifndef LOCATIONSERVICE_H
#define LOCATIONSERVICE_H

#include "../models/location.h"
#include "../repositories/locationio.h"
#include <vector>

class Locationservice
{
    public:
        Locationservice();
        location* get_location_list();
        void create_new_location(string location, int postcode);

    private:
        locationio LocIO;

};

#endif // LOCATIONSERVICE_H
