#include "ProdLineUI.h"

ProdLineUI::ProdLineUI(){
    ui_text = " --- Very Important Pizza Inc. ---\n"
              " ---      Production Line      ---\n"
              " 1. \n" // start with entering location?
              " 2. \n" // select pizza from current location
              " 3. \n" // mark status, in the works, in the oven, etc
              " 4. \n" // sign out?
              " 5. \n";
}

void ProdLineUI::prod_menu()
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
                cout << "I can do magic" << endl;
                // do something
                break;
            default:
                break;
        }
        cout << endl;
    }
}
