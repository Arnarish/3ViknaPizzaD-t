#include "Locationservice.h"

LocationService::LocationService()
{
    //ctor
}

Location* LocationService::get_location_list() {
    Location* locations = LocIO.read_file();
    return locations;
}

void LocationService::create_new_location(string new_location, int postcode) {
    if(new_location == "" || new_location.size() > 127) {
        throw InvalidLocationException();
    }
    if(postcode > 0 || postcode > 999)
    {
        throw InvalidPostcodeException();
    }
        LocationIO locio;
    Location l(new_location, postcode);
    locio.append_to_file(l);
}
