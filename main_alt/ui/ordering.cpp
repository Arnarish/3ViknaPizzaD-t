#include "ordering.h"

using namespace std;

OrderUI::OrderUI() {
    ui_text = " --- Ordering ---\n"
              " 1.  Create a new order\n"
              " 2.  Exit\n";
}

void OrderUI::main_menu() {
    char c;
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        cin >> c;
        cout << endl;
        m = c - 48;
        switch (m) {
            // Lets wrap these switch cases in blocks so I can reuse variable names (I'm lazy)
            case 1: {
                    string name;
                    string phone;
                    string pick_up;
                    string address;
                    string location;

                    cout << "Customer name: ";
                    cin >> name;
                    cout << "Customer phone number: ";
                    cin >> phone;
                    cout << "Order for pick-up? (y/n): ";
                    cin >> pick_up;
                    if (pick_up == "y") {
                        // List all locations
                        address = "Pick-up";
                    }
                    else {
                        // Prompt for customer address
                        cout << "Customer address: ";
                        cin >> address;
                        // What's the store location?
                        // Special location for deliveries maybe
                    }
                    // Try catch for validation
                    order_service.create_order(name, phone, address, location);
                } break;
           case 2: 
                return;
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}
