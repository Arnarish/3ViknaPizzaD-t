#include "delivery.h"

DeliveryUI::DeliveryUI() {
    ui_text = " --- Delivery ---\n"
            " 1.  Process order pick-up\n"
            " 2.  Process order delivery\n"
            " 3.  List all ready orders\n"
            " 4.  Go back\n";
}

void DeliveryUI::main_menu() {
    int m;
    while (true) {
        string phone;
        vector<Order> all_orders = order_service.all_orders();
        cout << ui_text << endl;
        cout << "Selection: ";
        while (!(cin >> m)) {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Selection: ";
        }
        cout << endl;
        switch (m) {
            case 1: {
                //todo: checka hvort númerið sé valid
             //   int number;
             //   int e = number_of_entries;
             //   all_orders = read_file
             //   cout << "Enter phone number: ";
             //   cin >> number;

             //   for (int i=0; i < e; i++) {
                        //breyta í order repository
             //       if (number == order[i].get_number) {
               //         order[i].set_delivered;
                 //   }
               // }

                cout << "Please input customer phone-number: ";
                cin.ignore();
                getline(cin, phone);
                for(unsigned int i=0; i<all_orders.size(); i++) {
                    if(all_orders.get_location() == store_location) {

                    }
                }
                break;
            }
            case 2:
                cout << "" << endl;
                break;
            case 3:
                cout << "" << endl;
                break;
            case 4:
                return;
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}

void DeliveryUI::ask_place() {
    int n = locationio.number_of_entries();
    int select_input = 0;
    Location* locations = location_service.get_location_list();
    cout << "Select your workplace from the list" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << locations[i].get_location() << endl;
    }
    while (!(cin >> select_input)) {
        // Only accept integers as input.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "please input a valid number from the list above." << endl;
    }
    if (select_input > n) {
        // If input is valid, but exceeds the given no. of stores.
        throw UserInputException();
    }
    store_location = locations[select_input - 1].get_location();
    cout << store_location << " selected." << endl << endl;

    delete[] locations;
}
