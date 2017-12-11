#include "orderservice.h"

using namespace std;

void OrderService::create_order(string name, string phone, string address, string location) {
    char c;
    int m;
    bool done = false;
    Order order(address, name, phone, location);
        while (true) {
            // Add pizzas and orders
            if (done) {
                break;
            }
            cout << "1. Add a pizza\n"
                 << "2. Add other products\n" //Soda, breadsticks, etc.
                 << "3. Finish order" << endl;
            cin >> c;
            m = c - 48;
            switch (m) {
                case 1: {
                    // From menu or create your own
                    char sel;
                    vector<Pizza> pizza_menu = menuio.read_file();

                    while (sel != '1' && sel != '2') {
                        cout << "1. Menu\n"
                             << "2. Create" << endl;
                        cout << "Selection: ";
                        cin >> sel;
                        if (sel == '1') {
                            int n;
                            for (unsigned int i = 0; i < pizza_menu.size(); i++) {
                                cout << (i+1) << endl;
                                cout << pizza_menu[i];
                            }
                            cout << "Selection: ";
                            cin >> n;
                            n++;
                            if (n < 1 || n > (int)pizza_menu.size()) {
                                cout << "Invalid selection" << endl;
                            }
                            else {
                                order.add_pizza(pizza_menu[n-1]);
                            }
                        }
                        else if (sel == '2') {
                            cout << "ok" << endl;
                        }
                        else { 
                            cout << "bla";
                        }
                    }

                } break;
                case 2: {
                    // Add soda and other cool things
                } break;
                case 3:
                    done = true;
                    break;
            }
        }
        cout << "done";
        //Insert order, order_service handles this
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
