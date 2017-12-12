#include "delivery.h"

DeliveryUI::DeliveryUI() {
    ui_text = " --- Delivery ---\n"
            " 1.  Process order\n"
            " 2.  Exit\n";
}

void DeliveryUI::main_menu() {

    char c;
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        cin >> c;
        cout << endl;
        m = c - 48;
        switch (m) {
            case 1:
                cout << "process order" << endl;
                break;
            case 2:
                cout << "Bye!" << endl;
                exit(0);
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}

void DeliveryUI::ask_place() {
    cout << "Ask location" << endl;
}
