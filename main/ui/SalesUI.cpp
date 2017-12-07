#include "SalesUI.h"

SalesUI::SalesUI(){
    ui_text = " --- Very Important Pizza Inc. ---\n"
              " ---           Sales           ---\n"
              " 1. Create new order\n"
              " 2. \n";
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
                cout << "" << endl;
                // make new order
                break;
            case 2:
                cout << "" << endl;
                // do we need more functions?
                break;
            default:
                break;
        }
        cout << endl;
    }
}
