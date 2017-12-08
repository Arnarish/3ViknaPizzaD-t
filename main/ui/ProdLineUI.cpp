#include "ProdLineUI.h"

ProdLineUI::ProdLineUI(){
    ui_text = " --- Very Important Pizza Inc. ---\n"
              " ---      Production Line      ---\n"
              " 1. \n" // start with entering location?
              " 2. \n" // select pizza to work on, bound to current store location
              " 3. \n" // Switch store? in case of wrong store selected?
              " 4. Exit.\n";
}

void ProdLineUI::prod_menu()
{
    select_store();
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
            case 4:
                exit(0);
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}

void ProdLineUI::select_store()
{
    cout << "Please select your current location from the list below: " << endl;
    // print list of store locations, catch entry and add set to string location.
}

void ProdLineUI::bake_pizza()
{
    // call pizza from list, print out list and select pizza to bake.
}
