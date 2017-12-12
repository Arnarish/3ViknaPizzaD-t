#include "location.h"

location::location()
{
    strcpy(this->Location, "");
    this->Postcode = 0;
}

location::location(string location, int postcode) {
    strcpy(this->Location, location.c_str());
    this->Postcode = postcode;
}

string location::get_location() {
    string current_location = Location;
    return current_location;
}

int location::get_postcode() {
    return Postcode;
}
