#include "ordering.h"

using namespace std;

OrderUI::OrderUI() {
    ui_text = " --- Ordering ---\n"
              " 1.  Create a new order\n"
              " 2.  List all ready orders\n"
              " 3.  Go back\n";
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
                int zipcode;

                cin.ignore(); //Get rid of a lingering newline character

                cout << "Customer name: ";
                getline(cin, name);
                cout << "Customer phone number: ";
                getline(cin, phone);
                cout << "Order for pick-up? (y/n): ";
                getline(cin, pick_up);
                if (pick_up == "y") {
                    int n = location_service.number_of_entries();
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
                    zipcode = locations[select_input-1].get_postcode();

                    delete[] locations;
                }
                else if (pick_up == "n") {
                    // Prompt for customer address
                    cout << "Customer address: ";
                    getline(cin, address);
                    cout << "Customer zip code: ";
                    while(!(cin >> zipcode)) {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.clear();
                        cout << "Invalid input, please try again: ";
                    }
                    //Find the nearest store location
                    location = location_service.find_nearest_store(zipcode);
                }
                else {
                    //throw InvalidPickUpException();
                }
                create_order(name, phone, address, location, zipcode);
            } break;
            case 2:{
                return;
            }
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}

void OrderUI::create_order(string name, string phone, string address, string location, int zipcode) {
char c;
    int m;
    bool done = false;
    OrderDetails details(name, phone, address, location, zipcode);
    Order order(details);
    //Order order(OrderDetails(name, phone, address, location, zipcode));
    while (true) {
        // Add pizzas and orders
        if (done) {
            break;
        }
        cout << "1. Add a pizza\n"
             << "2. Add other products\n" //Soda, breadsticks, etc.
             << "3. Finish order" << endl;
        cout << "Selection: ";
        cin >> c;
        m = c - 48;
        switch (m) {
            case 1: {
                // From menu or create your own
                char sel;
                vector<Pizza> pizza_menu = order_service.pizza_menu();
                int menu_size = pizza_menu.size();
                while (true) {
                    cout << "1. Menu\n"
                         << "2. Create\n"
                         << "3. Go back" << endl;
                    cout << "Selection: ";
                    cin >> sel;
                    if (sel == '1') {
                        int n;
                        for (int i = 0; i < menu_size; i++) {
                            cout << "Pizza #" << (i + 1) << ": ";
                            cout << pizza_menu[i] << endl;
                        }
                        cout << "Selection: ";
                        cin >> n;
                        if (n < 0 || n > menu_size) {
                            cout << "Invalid selection" << endl;
                        }

                        else {
                            order.add_pizza(pizza_menu[n-1]);
                        }
                    }
                    else if (sel == '2') {
                        Pizza created = create_pizza();
                        order.add_pizza(created);
                    }
                    else {
                        break;
                    }
                    cout << order << endl;
                }
            } break;
            case 2: { //split into 3 submenus, drinks, sides and others.
                Product* product_menu = order_service.product_menu();
                int n = order_service.product_entries();
                char sel;
                while (true) {
                    cout << "1. drinks\n"
                         << "2. sides\n"
                         << "3. other\n"
                         << "4. Go back" << endl;
                    cout << "Selection: ";
                    cin >> sel;
                    if(sel=='1') { //  it's a bit of a messy solution, but it's 0200 and i couldn't figure anything better out
                        int drink_selection;
                        vector<string> drinks = products_drinks();
                        cout << "Selection: " << endl;
                        for(unsigned int i=0; i < drinks.size(); i++) {
                            cout << i+1 << ". " << drinks[i] << endl;
                        }
                        while (!(cin >> drink_selection)) { // validate input, only accepts integers
                            cout << "Only integers, please!" << endl;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        for(int i=0; i < n; i++)
                        { // compares the string selected and the name of all of the products, adds the corresponding product
                            if(drinks[drink_selection-1] == product_menu[i].get_name()) {
                                order.add_product(product_menu[i]);
                                cout << product_menu[i].get_name();
                            }
                        }
                    }
                    else if(sel=='2') {
                        int sides_selection;
                        vector<string> sides = products_sides();
                        cout << "Selection: " << endl;
                        for(unsigned int i=0; i < sides.size(); i++) {
                            cout << i+1 << ". " << sides[i] << endl;
                        }
                        while (!(cin >> sides_selection)) {
                            cout << "Only integers, please!" << endl;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        for(int i=0; i < n; i++)
                        {
                            if(sides[sides_selection-1] == product_menu[i].get_name()) {
                                order.add_product(product_menu[i]);
                                cout << product_menu[i].get_name();
                            }
                        }
                    }
                    else if(sel=='3') {
                        int other_selection;
                        vector<string> other = products_other();
                        cout << "Selection: " << endl;
                        for(unsigned int i=0; i < other.size(); i++) {
                            cout << i+1 << ". " << other[i] << endl;
                        }
                        while (!(cin >> other_selection)) {
                            cout << "Only integers, please!" << endl;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        for(int i=0; i < n; i++)
                        {
                            if(other[other_selection-1] == product_menu[i].get_name()) {
                                order.add_product(product_menu[i]);
                                cout << product_menu[i].get_name();
                            }
                        }
                    }
                    else if(sel=='4') {
                        break;
                    }
                    else {
                        cout << "Invalid input." << endl;
                    }
                delete [] product_menu;
                }
            } break;
            case 3: {
                char sel;
                string comments = "";
                cout << "Any additional comments? (y/n): ";
                cin >> sel;
                if (sel == 'y') {
                    cin >> comments;
                    order.add_comments(comments);
                }
                done = true;
                break;
            }
        }
    }
    cout << order << endl;
    order_service.write_order(order);
}

Pizza OrderUI::create_pizza() {
    int s;
    Base* bases = order_service.read_base();
    int b = order_service.base_entries();
    while (true) {
        cout << "Available pizza bases: " << endl;
        for (int i = 0; i < b; i++) {
            cout << i + 1 << ": " << bases[i];
        }
        cout << "Selection: ";
        cin >> s;
        if (s < 1 || s > (b + 1)) {
            cout << "Invalid selection!" << endl;
        }
        else {
            break;
        }
    }
    Pizza p(bases[s - 1]);
    delete[] bases;

    Topping* toppings = order_service.read_topping();
    int t = order_service.topping_entries();
    while (true) {
        for (int i = 0; i < t; i++) {
            cout << (i + 1) << ": " << toppings[i] << endl;
        }
        cout << "Add toppings or enter 0 to stop: ";
        cin >> s;
        if (s == 0) {
            break;
        }
        else if (s < 0 || s > (t + 1)) {
            cout << "Invalid selection" << endl;
        }
        else {
            p.add_topping(toppings[s - 1]);
        }
    }
    return p;
}

vector<string> OrderUI::products_drinks() { // filters the product menu to drinks only
    Product* menu = order_service.product_menu();
    int n = order_service.product_entries();
    vector<string> drinks;
    for(int i=0; i < n; i++) {
        if(menu[i].get_category() == 'd') {
            drinks.push_back(menu[i].get_name());
        }
    }
    return drinks;
}

vector<string> OrderUI::products_sides() { // filters the product menu to sides only
    Product* menu = order_service.product_menu();
    int n = order_service.product_entries();
    vector<string> sides;
    for(int i=0; i < n; i++) {
        if(menu[i].get_category() == 's') {
            sides.push_back(menu[i].get_name());
        }
    }
    return sides;
}

vector<string> OrderUI::products_other() { // filters the product menu to others
    Product* menu = order_service.product_menu();
    int n = order_service.product_entries();
    vector<string> other;
    for(int i=0; i < n; i++) {
        if(menu[i].get_category() == 'o') {
            other.push_back(menu[i].get_name());
        }
    }
    return other;
}
