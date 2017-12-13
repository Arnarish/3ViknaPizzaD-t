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
                string pick_up = "";
                string address;
                string location;
                int zipcode;

                cout << "Customer name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Name: " << name << endl;
                cout << "Customer phone number: ";
                cin.ignore();
                getline(cin, phone);
                cout << "Phone: " << phone << endl;
                cout << "Order for pick-up? (y/n): ";
                cin.ignore();
                getline(cin, pick_up);
                cout << pick_up << "is the way" << endl;
                if (pick_up == "y") {
                    int n = locio.number_of_entries();
                    int select_input = 0;
                    locat = LocServ.get_location_list();
                    string* locations = new string[n];
                    for(int i=0; i<n; i++) {
                        locations[i] = locat[i].get_location();
                    }
                    cout << "Please select Pick-up location: " << endl;
                    for(int i=0; i<n; i++) {
                    cout << i+1 << ". " << locations[i] << endl;
                    }
                    while(!(cin >> select_input)) { // only accept integers as input.
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "please input a valid number from the list above." << endl;
                    }
                    if(select_input > n)
                    {
                        // if input is valid, but exceeds the given no. of stores.
                        //throw UserInputException;
                    }
                    location = locations[select_input-1];
                    address = "Pick-up";
                    zipcode = 0;

                    delete [] locations;
                    delete [] locat;
                }
                else if(pick_up == "n") {
                    // Prompt for customer address
                    cout << "Customer address: ";
                    cin.ignore();
                    getline(cin, address);
                    cout << "Customer zip code: ";
                    while(!(cin >> zipcode)) {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.clear();
                        cout << "Invalid input, please try again: ";
                    }
                    // TODO: Find the nearest store location
                    location = "temp";
                }
                else {
                    throw InvalidPickUpException();
                }
                order_service.create_order(name, phone, address, location, zipcode);
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
