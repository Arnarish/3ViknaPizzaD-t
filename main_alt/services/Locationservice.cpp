#include "Locationservice.h"

Locationservice::Locationservice()
{
    //ctor
}

location* Locationservice::get_location_list() {
    location* locations = LocIO.read_file();
    return locations;
}

void Locationservice::create_new_location(string new_location, int postcode) {
    if(new_location == "" || new_location.size() > 127) {
        // invalid location
        //throw InvalidLocationException
    }
    if(postcode > 0 || postcode > 999)
    {
        // invalid postcode
        //throw InvalidPostcodeException
    }
        locationio locio;
    location l(new_location, postcode);
    locio.append_to_file(l);
}
