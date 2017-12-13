#include "ordering.h"

using namespace std;

OrderUI::OrderUI() {
    ui_text = " --- Ordering ---\n"
              " 1.  Create a new order\n"
              " 2.  List all received orders\n"
              " 3.  Go back\n";
}

void OrderUI::main_menu() {
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        while (!(cin >> m)) {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Selection: ";
        }
        switch (m) {
            // Lets wrap these switch cases in blocks so I can reuse variable names (I'm lazy)
            case 1: {
                string name;
                string phone;
                string pick_up;
                string address;
                string location;
                int zipcode;

                cin.ignore(); //Get rid of a lingering newline character

                cout << "Customer name: ";
                getline(cin, name);
                cout << "Customer phone number: ";
                getline(cin, phone);
                cout << phone << endl;
                cout << "Order for pick-up? (y/n): ";
                getline(cin, pick_up);
                if (pick_up == "y") {
                    int n = locationio.number_of_entries();
                    int select_input = 0;
                    Location* locations = location_service.get_location_list();
                    cout << "Please select a pick-up location: " << endl;
                    for (int i = 0; i < n; i++) {
                        cout << i + 1 << ". " << locations[i].get_location() << endl;
                    }
                    while (!(cin >> select_input)) { 
                        // Only accept integers as input.
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Please input a valid number from the list above." << endl;
                    }
                    if (select_input > n)
                    {
                        // If input is valid, but exceeds the given no. of stores.
                        //throw UserInputException;
                    }
                    location = locations[select_input - 1].get_location();
                    address = "Pick-up";
                    zipcode = 0;

                    delete[] locations;
                }
                else if (pick_up == "n") {
                    // Prompt for customer address
                    cout << "Customer address: ";
                    getline(cin, address);
                    cout << address << endl;
                    cout << phone << endl;
                    cout << "Customer zip code: ";
                    while (!(cin >> zipcode)) {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.clear();
                        cout << "Invalid input, please try again: ";
                    }
                    // TODO: Find the nearest store location
                    location = "temp";
                }
                else {
                    //throw InvalidPickUpException();
                    cout << "bla" << endl;
                }
                order_service.create_order(name, phone, address, location, zipcode);
            } break;
            case 2: {
                vector<Order> orders = order_service.get_ordered();
                for (unsigned int i = 0; i < orders.size(); i++) {
                    cout << " ------ { ORDER #" << i + 1 << " } ------ \n";
                    cout << orders[i] << endl;
                }
            }
            case 3: {
                return;
            }
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}
