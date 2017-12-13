#include "orderservice.h"

using namespace std;

void OrderService::create_order(string name, string phone,
                                string address, string location, int zipcode) {
    char c;
    int m;
    bool done = false;
    OrderDetails details(name, phone, address, location, zipcode);
    Order order(details);
    //Order order(OrderDetails(name, phone, address, location, zipcode));
    while (true) {
        // Add pizzas and orders
        if (done) {
            break;
        }
        cout << "1. Add a pizza\n"
             << "2. Add other products\n" //Soda, breadsticks, etc.
             << "3. Finish order" << endl;
        cout << "Selection: ";
        cin >> c;
        m = c - 48;
        switch (m) {
            case 1: {
                // From menu or create your own
                char sel;
                vector<Pizza> pizza_menu = menuio.read_file();
                int menu_size = pizza_menu.size();
                while (true) {
                    cout << "1. Menu\n"
                         << "2. Create\n"
                         << "3. Go back" << endl;
                    cout << "Selection: ";
                    cin >> sel;
                    if (sel == '1') {
                        int n;
                        for (int i = 0; i < menu_size; i++) {
                            cout << "Pizza #" << (i + 1) << ": ";
                            cout << pizza_menu[i] << endl;
                        }
                        cout << "Selection: ";
                        cin >> n;
                        if (n < 0 || n > menu_size) {
                            cout << "Invalid selection" << endl;
                        }
                        else {
                            order.add_pizza(pizza_menu[n-1]);
                        }
                    }
                    else if (sel == '2') {
                        Pizza created = create_pizza();
                        order.add_pizza(created);
                    }
                    else {
                        break;
                    }
                }
            } break;
            case 2: {
                // Add soda and other cool things
            } break;
            case 3: {
                char sel;
                string comments = "";
                cout << "Any additional comments? (y/n): ";
                cin >> sel;
                if (sel == 'y') {
                    cin.ignore();
                    getline(cin, comments);
                    order.add_comments(comments);
                }
                done = true;
                break;
            }
        }
    }
    cout << order << endl;
    orderio.write_to_file(order);
}

OrderDetails OrderService::create_details(string name, string phone, string address,
                                  string location, int zipcode) {
        if (name == "" || name.size() > 127) {
        // Invalid name, throw an exception
        // throw InvalidNameException();
        }

        if(phone == "" || (phone.length() > 8 || phone.length() < 6)) { 
        // check if string is empty, or number has invalid length
           //throw CustomerPhoneException();
        }
        bool isNumber = true;
        for(unsigned int i=0; i < phone.length(); i++) { // check if phone has non numerals
            if(!isalnum(phone[i])) {
                isNumber = false;
                break;
            }
            if(isNumber == false) {
            //thow CustomerPhoneException)(;
            }
        }
        if(address == "" || address.size() > 127) {
            //throw CustomerAddressException();
        }
        if(location == "" || location.size() > 127) {
            //throw InvalidLocationException();
        }
        if(zipcode > 999 || zipcode < 99) {
            //throw CustomerZipcodeException();
        }
        // Try catch for validation
    //TODO: validate EVERYTHING and throw exceptions
    OrderDetails details(name, phone, address, location, zipcode);
    return details;
}

Pizza OrderService::create_pizza() {
    int s;
    Base* bases = baseio.read_file();
    int b = baseio.number_of_entries();
    while (true) {
        cout << "Available pizza bases: " << endl;
        for (int i = 0; i < b; i++) {
            cout << i + 1 << ": " << bases[i];
        }
        cout << "Selection: ";
        cin >> s;
        if (s < 1 || s > (b + 1)) {
            cout << "Invalid selection!" << endl;
        }
        else {
            break;
        }
    }
    Pizza p(bases[s - 1]);
    delete[] bases;

    Topping* toppings = toppingio.read_file();
    int t = toppingio.number_of_entries();
    while (true) {
        for (int i = 0; i < t; i++) {
            cout << (i + 1) << ": " << toppings[i] << endl;
        }
        cout << "Add toppings or enter 0 to stop: ";
        cin >> s;
        if (s == 0) {
            break;
        }
        else if (s < 0 || s > (t + 1)) {
            cout << "Invalid selection" << endl;
        }
        else {
            p.add_topping(toppings[s - 1]);
        }
    }
    return p;
}
