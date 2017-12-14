#include "preperation.h"

PreperationUI::PreperationUI() {
    ui_text = " --- Preperation ---\n"
            " 1.  Process order\n"
            " 2.  Exit\n";
}

void PreperationUI::main_menu() {
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
        cout << endl;
        string complete = "";
        switch (m) {
            case 1: {
                vector<Order> orders = orderio.read_file(); //sækir öll orders
                OrderDetails orders_details[(int)orders.size()]; //tómt array af taginu OrderDetails

                //sækir details úr öllum orders og fyllir OrderDetails array
                for (unsigned int i=0; i < orders.size(); i++) {
                    orders_details[i] = orders[i].get_details();
                }
                if (store_location == orders_details[0].get_location()) {
                            cout << "Order number " << endl;
                            cout << orders[0] << endl;
                        }
                cout << "do you wish to mark order complete(y/n)? ";
                while(cin >> complete) {
                    if(complete == "y") {
                        cout << "Marking order complete." << endl;
                        break;
                    }
                    else {
                        break;
                    }
                }
            }


                break;
            case 2:
                return;
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}

void PreperationUI::ask_place() {
    int n = locio.number_of_entries();
    int select_input = 0;
    Location* locat = LocServ.get_location_list();
    string* locations = new string[n];
    for(int i=0; i<n; i++) {
        locations[i] = locat[i].get_location();
    }
    cout << "please select current workplace from list: " << endl;
    for(int i=0; i<n; i++) {
        cout << i+1 << ". " << locations[i] << endl;
    }
    while(!(cin >> select_input)) { // only accept integers as input.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please input a valid number from the list above." << endl;
    }
    if(select_input > n) {
        // if input is valid, but exceeds the given no. of stores.
        throw UserInputException();
    }
    store_location = locations[select_input-1];
    cout << store_location << " selected." << endl << endl;

    delete [] locat;
    delete [] locations;
}
