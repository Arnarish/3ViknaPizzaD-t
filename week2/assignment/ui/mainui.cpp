#include <iostream>
#include <string>
#include "mainui.h"

using namespace std;

MainUI::MainUI() { 
    // TODO: add salary service object
    ui_text = " --- Very Important Business Inc. ---\n"
                     " 1. Add a salary record\n"
                     " 2. List salary records by SSN\n"
                     " 3. Total yearly salary by SSN\n"
                     " 4. Print the highest paid employee";
}

void MainUI::main_menu() {
    char c;
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection> ";
        cin >> c;

        m = c - 48;
        switch (m) {
            case 1:
                cout << "1" << endl;
                break;
            case 2:
                cout << "2" << endl;
                break;
            case 3:
                cout << "3" << endl;
                break;
            case 4:
                cout << "4" << endl;
                break;
            default:
                cout << "Invalid input!" << endl;
                break;
        }
    }
}
