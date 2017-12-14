#include "mainui.h"

using namespace std;

ManagementUI::ManagementUI() {
    ui_text = " --- Management ---\n"
              " 1.  New pizza base\n"
              " 2.  New topping\n"
              " 3.  New menu item\n"
              " 4.  New product\n"
              " 5.  New pick-up location\n"
              " 6.  Go back\n";
}

void ManagementUI::main_menu() {
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
                int price;
                int size;
                // Pizza base is a class (char[128], int, int)

                cout << "Base name: ";
                cin.ignore(); // Ignore a newline character in the stream
                getline(cin, name);
                cout << "Price: ";
                cin >> price;
                cout << "Size: ";
                cin >> size;
                try {
                    management_service.create_new_base(name, price, size);
                    cout << "Done!" << endl;
                }
                catch (InvalidNameException) {
                    cout << "Invalid name!" << endl;
                }
                catch (InvalidPriceException) {
                    cout << "Invalid price!" << endl;
                }
                catch (InvalidSizeException) {
                    cout << "Invalid size!" << endl;
                }
                catch (FileExistsException) {
                    cout << "File doesn't exist!" << endl;
                }
                catch (FileWriteException) {
                    cout << "Couldn't open file!" << endl;
                }
                catch (FileReadException) {
                    cout << "Couldn't read file!" << endl;
                }
            } break;
            case 2: {
                // Topping is a class
                string name;
                int price;
                cout << "Topping name: ";
                cin.ignore(); // Ignore a newline character in the stream
                getline(cin, name);
                cout << "Price: ";
                cin >> price;
                try {
                    management_service.create_new_topping(name, price);
                    cout << "Done!" << endl;
                }
                catch (InvalidNameException) {
                    cout << "Invalid name!" << endl;
                }
                catch (InvalidPriceException) {
                    cout << "Invalid price!" << endl;
                }
                catch (FileReadException) {
                    cout << "Couldn't read file!" << endl;
                }
                catch (FileExistsException) {
                    cout << "File doesn't exist!" << endl;
                }
                catch (FileWriteException) {
                    cout << "Could not open file!" << endl;
                }
            } break;

            case 3: {
                // The menu is a vector of pizza classes
                // First we need to select a pizza base
                // then we select toppings
                // then we set the name
                vector<Base> bases;
                vector<Topping> toppings;

                try {
                    bases = management_service.get_all_bases();
                }
                catch (FileEmptyException) {
                    cout << "There are no bases registered!" << endl;
                    break;
                }
                try {
                    toppings = management_service.get_all_toppings();
                }
                catch (FileEmptyException) {
                    cout << "There are no toppings registered!" << endl;
                    break;
                }
                vector<int> selected_toppings;
                for (unsigned int i = 0; i < bases.size(); i++) {
                    cout << i + 1 << ". " << bases[i] << "\n";
                }
                cout << "Please select a pizza base: ";
                int base_select = 0;
                do {
                    while (!(cin >> base_select)) {
                        cout << "Only integers, please!" << endl;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Please select a pizza base: ";
                    }
                } while (base_select < 0 || base_select > (int)bases.size());
                base_select--;
                for (unsigned int i = 0; i < toppings.size(); i++) {
                    cout << i + 1 << ". " << toppings[i]
                         << " ( " << toppings[i].get_price() << " kr)\n";
                }
                int topping_select = 0;
                do {
                    cout << "Select toppings or enter 0 to stop: ";
                    cin >> topping_select;
                    if (topping_select < 0 || topping_select > (int)toppings.size()) {
                        cout << "Invalid selection!" << endl;
                    }
                    else {
                        selected_toppings.push_back(topping_select - 1);
                    }
                } while (topping_select != 0);
                cout << "Name your pizza: ";
                string name;
                cin.ignore();
                getline(cin, name);
                try {
                    management_service.create_new_menu_item(name, base_select, selected_toppings);
                    cout << "Done!" << endl;
                }
                catch (FileExistsException) {
                    cout << "File not found!" << endl;
                }
                catch (FileReadException) {
                    cout << "Unable to read from menu!" << endl;
                }
                catch (FileWriteException) {
                    cout << "Unable to write to menu!" << endl;
                }
            } break;

            case 4: {
                string name;
                int price;
                int category;
                cout << "Please enter the name of the new product: ";
                cin.ignore();
                getline(cin, name);
                cout << "1. Drinks\n 2. Sides\n 3. Other\n";
                cout << "Please enter the category for the new product: ";
                while (!(cin >> category)) {
                    cout << "Only integers, please!" << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Please enter the category for the new product: ";
                }
                cout << "Selected category: " << category << endl;
                category--;
                cout << "Please enter the price of the new product: ";
                while (!(cin >> price)) {
                    cout << "Only integers, please!" << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Please enter the price of the new product: ";
                }
                try {
                   management_service.create_new_product(name, price, category);
                   cout << "Done!" << endl;
                }
                catch (InvalidNameException) {
                    cout << "Invalid name!" << endl;
                }
                catch (InvalidPriceException) {
                    cout << "Invalid price!" << endl;
                }
                catch (InvalidCategoryException) {
                    cout << "Invalid category!" << endl;
                }
                catch (FileWriteException) {
                    cout << "Couldn't open file!" << endl;
                }
            } break;

            case 5: {
                string location_name;
                int postcode;
                cout << "Please enter the address of the location: ";
                cin.ignore();
                getline(cin, location_name);
                cout << "Please enter the zip code: ";
                while (!(cin >> postcode)) {
                    cout << "Only integers, please!" << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Please enter the zip code: ";
                }
                try {
                    management_service.add_new_store_location(location_name, postcode);
                    cout << "Done!" << endl;
                }
                catch (InvalidLocationException) {
                    cout << "Invalid location!" << endl;
                }
                catch (InvalidPostcodeException) {
                    cout << "Invalid postcode!" << endl;
                }
                catch (FileWriteException) {
                    cout << "Couldn't open file!" << endl;
                }
                catch (FileReadException) {
                    cout << "Couldn't open file!" << endl;
                }
                catch (FileExistsException) {
                    cout << "File not found!" << endl;
                }
            } break;
            case 6: {
                return;
            }
            default: {
                cout << "Invalid input." << endl;
            } break;
        }
    }
}
