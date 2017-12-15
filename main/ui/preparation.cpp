#include "preparation.h"

PreparationUI::PreparationUI() {
    ui_text = " --- Preparation ---\n"
            " 1.  Process earliest order\n"
            " 2.  List all ready orders\n"
            " 3.  Go back\n";
}

void PreparationUI::main_menu() {
    try {
        ask_place();
    }
    catch (InvalidLocationException) {
        cout << "There are no locations available." << endl;
        return;
    }
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                list_orders();
            } break;
            case 3: {
                return;
            } break;
            default: {
                cout << "Invalid input." << endl;
            } break;
        }
        cout << endl;
    }
}

void PreparationUI::ask_place() {
    int number_of_locations = locationservice.number_of_entries();
    if (number_of_locations == 0) {
        throw InvalidLocationException();
    }
    int select_input = 0;
    Location* locations = locationservice.get_location_list();
    while (true) {
        cout << "Please select your current workplace from list: " << endl;
        for (int i = 0; i < number_of_locations; i++) {
            cout << i + 1 << ". " << locations[i].get_location() << endl;
        }
        cout << "Selection: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void PreparationUI::list_orders() {
    for (unsigned int i = 0; i < orders.size(); i++) {
        cout << " ~~~ ORDER #" << i + 1 << " ~~~ \n";
        cout << orders[i];
    }
}
