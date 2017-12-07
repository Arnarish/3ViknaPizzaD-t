#include "ProdLineUI.h"

ProdLineUI::ProdLineUI(){
    ui_text = " --- Very Important Pizza Inc. ---\n"
              " ---      Production Line      ---\n"
              " 1. \n"
              " 2. \n"
              " 3. \n"
              " 4. \n"
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
