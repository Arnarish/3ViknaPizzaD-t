#include "delivery.h"

DeliveryUI::DeliveryUI() {
    ui_text = " --- Delivery ---\n"
            " 1.  Process order pick-up\n"
            " 2.  Process order delivery\n"
            " 3.  List all ready orders\n"
            " 4.  Go back\n";
}

void DeliveryUI::main_menu() {
    try {
        get_place();
    }
    catch (InvalidLocationException) {
        cout << "There are no locations available." << endl;
        return;
    }
    catch (UserInputException) {
        cout << "Invalid user input." << endl;
        return;
    }
    all_orders = orderservice.get_ready();
    orders = deliveryservice.get_orders_by_location(store_location, all_orders);
    if (orders.size() == 0) {
        cout << "No orders in delivery!" << endl;
        return;
    }
    int m;
    string phone;
    Order order;
    while (true) {
        all_orders = orderservice.get_ready();
        orders = deliveryservice.get_orders_by_location(store_location, all_orders);
        cout << ui_text << endl;
        cout << "Selection: ";
        if (!(cin >> m)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw UserInputException();
        }
        cout << endl;
        switch (m) {
            case 1: {
                cout << "Please input customer phone number: ";
                cin.ignore();
                getline(cin, phone);
                try {
                    order = deliveryservice.get_order_by_phone_number(orders, phone);
                }
                catch (CustomerPhoneException) {
                    cout << "Invalid phone number" << endl;
                    break;
                }
                catch (MissingOrderException) {
                    cout << "No order found at this location for this phone number" << endl;
                    break;
                }
                catch (UserInputException) {
                    cout << "This order is not flagged for pick-up" << endl;
                    break;
                }
                string select;
                cout << order << endl;
                if (order.get_paid()) {
                    cout << order << endl;
                    // If paid, prompt for delivery
                    cout << "The order is paid for, do you want to delivery it? (y/n): ";
                    cin >> select;
                    if (select == "n") {
                        break;
                    }
                    else if (select == "y") {
                        deliveryservice.process_order(order);
                        cout << "Done!" << endl;
                    }
                    else {
                        cout << "Invalid input" << endl;
                        break;
                    }
                }
                else {
                    cout << "The order isn't paid for, do you want to mark it as paid? (y/n): ";
                    cin >> select;
                    if (select == "y") {
                        order.set_paid(true);
                        cout << "The order is paid for, do you want to deliver it? (y/n): ";
                        cin >> select;
                        if (select == "n") {
                            deliveryservice.update_paid(order, all_orders);
                            break;
                        }
                        else if (select == "y") {
                            deliveryservice.process_order(order);
                            cout << "Done!" << endl;
                            return;
                        }
                        else {
                            cout << "Invalid input" << endl;
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }
            } break;
            case 2: { // pizzas for delivery, fails if there are no ready pizzas
                int s;
                bool good_for_pickup = false;
                string select;
                cout << " 1.  Deliver a pizza\n"
                     << " 2.  Go back\n" << endl;
                cout << "Selection: ";
                while (!(cin >> s)) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input" << endl;
                }
                if (m < 1 || m > 2) {
                    cout << "Invalid input" << endl;
                    break;
                }
                Order latest = orders[0];
                for (unsigned int i = 0; i < orders.size(); i++) {
                    if (orders[i].get_details().get_address() != "Pick-up") {
                        good_for_pickup = true;
                        latest = orders[i];
                        break;
                    }
                }
                if (!good_for_pickup) {
                    cout << "No orders ready for delivery for this location" << endl;
                    break;
                }
                cout << latest << endl;
                cout << "Deliver this order? (y/n): ";
                cin >> select;
                if (select == "y") {
                    latest.set_paid(true);
                    deliveryservice.process_order(latest);
                    cout << "Done!";
                }
                else if (select == "n") {
                    break;
                }
                else {
                    cout << "Invalid input" << endl;
                }
            } break;
            case 3: {
                list_orders();
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

void DeliveryUI::get_place() { // returns the current storefront of the working user
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
        if (!(cin >> select_input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw UserInputException();
        }
        cout << endl;
        if (select_input < 1 || select_input > number_of_locations) {
            throw UserInputException();
        }
        else {
            break;
        }
    }
    store_location = locations[select_input - 1];
    delete[] locations;
}

void DeliveryUI::list_orders() {
    for (unsigned int i = 0; i < orders.size(); i++) {
        cout << " ~~~ ORDER #" << i + 1 << " ~~~ \n";
        cout << orders[i] << endl;
    }
}
