#include "orderdetails.h"

using namespace std;

OrderDetails::OrderDetails() {
    name[0] = '\0';
    phone[0] = '\0';
    address[0] = '\0';
    location[0] = '\0';
    zipcode = 0;
}

OrderDetails::OrderDetails(string name, string phone, string address,
                           string location, int zipcode) {
    strcpy(this->name, name.c_str());
    strcpy(this->phone, phone.c_str());
    strcpy(this->address, address.c_str());
    strcpy(this->location, location.c_str());
    this->zipcode = zipcode;
}
void OrderDetails::add_comments(string comments) {
    strcpy(this->comments, comments.c_str());
}

string OrderDetails::get_location() {
    string s = location;
    return s;
}

string OrderDetails::get_address() {
    string s = address;
    return s;
}

int OrderDetails::get_zipcode() {
    return zipcode;
}

string OrderDetails::get_phone() {
    return phone;
}

ostream& operator << (ostream& out, OrderDetails& d) {
    out << "Customer name      : " << d.name << "\n"
        << "Phone number       : " << d.phone << "\n"
        << "Address            : " << d.address << "\n"
        << "Store location     : " << d.location << "\n"
        << "Zip code           : " << d.zipcode << "\n"
        << "Additional comments: " << d.comments;
    return out;
}
