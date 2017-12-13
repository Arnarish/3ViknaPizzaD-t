#include "location.h"

Location::Location()
{
    strcpy(this->location, "");
    this->Postcode = 0;
}

Location::Location(string location, int postcode) {
    strcpy(this->location, location.c_str());
    this->Postcode = postcode;
}

string Location::get_location() {
    string current_location = location;
    return current_location;
}

int Location::get_postcode() {
    return Postcode;
}
