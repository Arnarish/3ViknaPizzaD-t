#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Location
{
    public:
        Location();
        Location(string location, int postcode);
        string get_location();
        int get_postcode();

    private:
        char location[128];
        int Postcode;
};

#endif // LOCATION_H
