#include "SalesUI.h"

SalesUI::SalesUI(){
    ui_text = " --- Very Important Pizza Inc. ---\n"
              " ---           Sales           ---\n"
              " 1. Create new order\n" // enter new pizza order
              " 2. Create order from menu\n" // could be unified under new order as a submenu
              " 3. " // edit order?
              " 4. Exit. "; // end program
}

void SalesUI::sales_menu()
{
    char c;
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        cin >> c;
        m = c - 48;
        switch (m) {
            case 1:
                new_pizza();
                break;
            case 2:
                cout << "" << endl;
                // do we need more functions?
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}

void SalesUI::new_pizza()
{
    // create new pizza.
}
