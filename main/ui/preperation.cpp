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
        switch (m) {
            case 1: {
/*
                cout << "All orders:" << endl;

                vector<Order> orders = orderio.read_file(); //sækir öll orders
                OrderDetails orders_details[orders.size()];    //tómt array af taginu OrderDetails

                //cout á öll orders
                for (int i=0; i < order_size; i++) {
                    cout << orders[i] << endl;
                }

                //sækir details úr öllum orders og fyllir OrderDetails array
                for (unsigned int i=0; i < orders.size(); i++) {
                    orders_details[i] = orders[i].get_details();
                }
                //ber saman location í details við location á bakaranum
                int counter = 1;
                for (unsigned int i=0; i < orders.size(); i++) {
                    string lalli = orders_details[i].get_location();
                        if (store_location == lalli) {
                            cout << "Order number " << counter << "#" << endl;
                            cout << orders[i] << endl;
                            counter++;
                        }
                    }
*/
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
    cout << "Please select current workplace from list: " << endl;
    for(int i=0; i<n; i++) {
        cout << i+1 << ". " << locations[i] << endl;
    }
    while(!(cin >> select_input)) { // only accept integers as input.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please input a valid number from the list above." << endl;
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
