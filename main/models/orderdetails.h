#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// This class contains all the details about the customer and some
// other important things about the order, such as the delivery / pickup
// location, comments, and customer address if the customer wants a delivery

class OrderDetails {
    public:
        OrderDetails();
        OrderDetails(string name, string phone, string address, 
                     string location, int zipcode);
        void add_comments(string comments);
        string get_location();
        string get_address();
        int get_zipcode();
    private:
        char name[128];
        char phone[10];
        char address[128];
        char location[128];
        char comments[512]; // Picky customers can write many comments
        int zipcode;

        friend ostream& operator << (ostream& out, OrderDetails& d);
};

#endif
