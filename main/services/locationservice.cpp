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
    if (postcode < 100 || postcode > 999) {
        throw InvalidPostcodeException();
    }
    Location l(new_location, postcode);
    locationio.append_to_file(l);
}

int LocationService::number_of_entries() {
    int n = locationio.number_of_entries();
    return n;
}
// finds nearest storefront based on zipcode
string LocationService::find_nearest_store(int postcode) {
    int n = locationio.number_of_entries();
    Location* locations = locationio.read_file();
    int* postcodes = new int [n];
    string nearest_store = locations[0].get_location();
    for(int i=0; i < n ; i++) {
        postcodes[i] = locations[i].get_postcode();
    }
    int diff = abs(postcode - postcodes[0]);
    int index = 0;
    for(int i=0; i < n; i++) {
        if(diff > abs(postcode - postcodes[i])) {
            diff = abs(postcode - postcodes[i]);
            index = i;
        }
    }
    nearest_store = locations[index].get_location();
    delete [] locations;
    delete [] postcodes;
    return nearest_store;
}
