#include "AdminUI.h"

AdminUI::AdminUI() {
    ui_text = " --- Admin and admin accessories ---\n"
              " 1. Manage toppings\n"
              " 2. Manage menu\n"
              " 3. Quit\n";

    ui_manage_toppings_text =   " --- Manage toppings ---\n"
                                " 1. Add topping\n"
                                " 2. remove topping\n"
                                " 3. <--";

    ui_manage_menu_text =   " --- Manage menu ---\n"
                            " 1. Add special\n"
                            " 2. Remove special\n"
                            " 3. Add product\n"
                            " 4. Remove product\n"
                            " 5. <--";

}



void AdminUI::admin_menu() {
    char c;
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        cin >> c;
        m = c - 48;
        switch (m) {
            case 1:
                manage_toppings_menu();
                break;
            case 2:
                manage_menu_menu();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid input!" << endl;
                break;
        }
        cout << endl;
    }
}

void AdminUI::manage_toppings_menu() {
    char c;
    int m;
    while (true) {
        cout << ui_manage_toppings_text << endl;
        cout << "Selection: ";
        cin >> c;
        m = c - 48;
        switch (m) {
            case 1:
                newtoppingservice.add_topping(create_topping());
                break;
            case 2:
                cout << "remove topping hey" << endl;
                break;
            case 3:
                return;
            default:
                cout << "Invalid input!" << endl;
                break;
        }
        cout << endl;
    }
}

void AdminUI::manage_menu_menu() {
    char c;
    int m;
    while (true) {
        cout << ui_manage_menu_text << endl;
        cout << "Selection: ";
        cin >> c;
        m = c - 48;
        switch (m) {
            case 1:
                cout << "add special hey" << endl;
                break;
            case 2:
                cout << "remove special hey" << endl;
                break;
            case 3:
                cout << "add product hey" << endl;
                break;
            case 4:
                cout << "remove product hey" << endl;
                break;
            case 5:
                return;
            default:
                cout << "Invalid input!" << endl;
                break;

        }
        cout << endl;
    }
}

Topping AdminUI::create_topping() {
    string name;
    int price;

    cout << "Name: ";
    cin >> name;
    cout << "Price: ";
    cin >> price;
    Topping topping(name, price);
    return topping;
}
