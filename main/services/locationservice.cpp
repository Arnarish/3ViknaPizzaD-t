#include "locationservice.h"

LocationService::LocationService()
{
    //ctor
}

Location* LocationService::get_location_list() {
    Location* locations = locationio.read_file();
    return locations;
}

void LocationService::create_new_location(string new_location, int postcode) {
    if (new_location == "" || new_location.size() > 127) {
        throw InvalidLocationException();
    }
    if (postcode < 0 || postcode > 999) {
        throw InvalidPostcodeException();
    }
    Location l(new_location, postcode);
    locationio.append_to_file(l);
}
