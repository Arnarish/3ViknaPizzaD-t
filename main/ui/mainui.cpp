#include "mainui.h"

MainUI::MainUI() {
    ui_text = " --- Very Important Pizza Inc. ---\n"
              " 1. Hey\n";
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
            case 1:
                cout << "Hey" << endl;
                break;
            default:
                exit(0);
                break;
        }
        cout << endl;
    }
}

