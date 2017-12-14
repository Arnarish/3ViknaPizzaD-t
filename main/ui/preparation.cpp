#include "preparation.h"

PreperationUI::PreperationUI() {
    ui_text = " --- Preperation ---\n"
            " 1.  Process earliest order\n"
            " 2.  Process specific order\n"
            " 3.  List all ready orders\n"
            " 4.  Go back\n";
}

void PreperationUI::main_menu() {
    ask_place();
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        if (!(cin >> m)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw UserInputException();
        }
        cout << endl;
        vector<Order> all_orders = orderservice.get_ordered();
        orders = preparationservice.get_orders_by_location(store_location, all_orders);
        if (orders.size() == 0) {
            cout << "No orders in processing!" << endl;
            return;
        }
        switch (m) {
            case 1: {
                // Process latest order
                string selection;
                Order order = orders[0];
                cout << order << endl;
                cout << "Mark this product as ready? (y/n): ";
                cin >> selection;
                if (selection == "y") {
                    preparationservice.process_earliest_order(order);
                    cout << "Done!";
                }
                else if (selection == "n") {
                    break;
                }
                else {
                    throw UserInputException();
                }
            } break;
            case 2: {
                // Process a latest order
                cout << "Specific" << endl;
            } break;
            case 3: {
                // List all ordered orders
                cout << "All" << endl;
            } break;
            case 4: {
                return;
            } break;
            default: {
                cout << "Invalid input." << endl;
            } break;
        }
        cout << endl;
    }
}

void PreperationUI::ask_place() {
    int number_of_locations = locationservice.number_of_entries();
    int select_input = 0;
    Location* locations = locationservice.get_location_list();

    while (true) {
        cout << "Please select your current workplace from list: " << endl;
        for (int i = 0; i < number_of_locations; i++) {
            cout << i + 1 << ". " << locations[i].get_location() << endl;
        }
        if (!(cin >> select_input)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw UserInputException();
        }
        if (select_input < 0 || select_input > number_of_locations) {
            throw UserInputException();
        }
        else {
            break;
        }
    }
    store_location = locations[select_input - 1];
    delete[] locations;
}
