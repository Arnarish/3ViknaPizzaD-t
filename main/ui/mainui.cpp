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
            case 1: // enter AdminUI
                cout << "Entering Management menu." << endl;
                adminui.admin_menu();
                break;
            case 2: // enter SalesUI
                cout << "Entering Sales menu." << endl;
                salesui.sales_menu();
                break;
            case 3: // enter ProdLineUI
                cout << "Entering product line menu." << endl;
                produi.prod_menu();
                break;
            case 4: // enter StorefrontUI
                cout << "Entering Storefront menu." << endl;
                storeui.store_menu();
                break;
            case 5:
                cout << "Goodbye!" << endl;
                exit(0);
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}

