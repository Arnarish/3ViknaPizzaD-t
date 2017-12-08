#include "StoreUI.h"

StoreUI::StoreUI(){
    ui_text = " --- Very Important Pizza Inc. ---\n"
              " ---         Storefront        ---\n"
              " 1. New order.\n" // add new order to list, can be marked as payed after confirmation
              " 2. Pizza Pick-up.\n" // Customer pick up, select pizza from list, mark as payed/completed
              " 3. \n" // Pizza delivery?
              " 4. Exit.\n";
}

void StoreUI::store_menu()
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
                cout << "" << endl;
                // Do a thing
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

void StoreUI::new_pizza()
{
    // is it better to include this function from salesui?
}


