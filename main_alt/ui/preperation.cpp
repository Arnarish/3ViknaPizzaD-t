#include "Preperation.h"

PreperationUI::Preperation() {
    ui_text = " --- Preperation ---\n"
            " 1.  Process order\n"
            " 2.  Exit\n";
}

void PreperationUI::main_menu() {

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

void PreperationUI::ask_place() {
    cout << "where u at?: " << endl;
    cout << "(user inputs here etc.)" << endl;
    //b�ta vi� a� a� lesa alla sta�i upp �r skr� og
    //f� input fr� '1 - x' (1 = 0 � array)
    //f� string til a� fara me� lengra � forrit
}
