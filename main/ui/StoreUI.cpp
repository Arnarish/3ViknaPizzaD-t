#include "StoreUI.h"

StoreUI::StoreUI(){
    ui_text = " --- Very Important Pizza Inc. ---\n"
              " ---         Storefront        ---\n"
              " 1. \n"
              " 2. \n"
              " 3. \n"
              " 4. \n"
              " 5. \n";
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
            default:
                break;
        }
        cout << endl;
    }
}


