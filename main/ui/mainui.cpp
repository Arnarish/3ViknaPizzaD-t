#include "mainui.h"

MainUI::MainUI() {
    ui_text = " --- Very Important Pizza Inc. ---\n" // nota gamla pizza_menu text skjalið?
              " 1. Management\n" // add toppings, etc
              " 2. Sales\n" // add orders
              " 3. Product line\n" // baker menu
              " 4. Storefront\n" // pizza handout
              " 5. Exit\n"; // exit program
}

void MainUI::main_menu() {
    char c;
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        cin >> c;
        m = c - 48;
        switch (m) {
            case 1: // enter ManagementUI
                cout << "Entering Management menu." << endl;
                // call AdminUI
                break;
            case 2: // enter SalesUI
                cout << "Entering Sales menu." << endl;
                // call SalesUI
                break;
            case 3: // enter ProdLineUI
                cout << "Entering product line menu." << endl;
                // call ProdLineUI
                break;
            case 4: // enter StorefrontUI
                cout << "Entering Storefront menu." << endl;
                // Call StoreUI
                break;
            case 5: // Goodbye!
                cout << "Goodbye!" << endl;
                break;
            default:
                exit(0);
                break;
        }
        cout << endl;
    }
}

