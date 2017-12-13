#include "mainui.h"

using namespace std;

MainUI::MainUI() {
    ui_text = " --- Very Important Pizza Inc. ---\n"
              " 1.  Management\n"
              " 2.  Ordering\n"
              " 3.  Preparation\n"
              " 4.  Delivery\n"
              " 5.  Exit\n";
}

void MainUI::main_menu() {
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
                management.main_menu();
                break;
            case 2:
                ordering.main_menu();
                break;
            case 3:
                try{
                    preperation.ask_place();
                }
                catch(UserInputException) {
                    cout << "Invalid User input." << endl;
                }
                catch(FileExistsException) {
                    cout << "File does not exist." << endl;
                }
                catch(FileReadException) {
                    cout << "Unable to read from file." << endl;
                }
                preperation.main_menu();
                break;
            case 4:
                try {
                    delivery.ask_place();
                }
                catch(UserInputException) {
                    cout << "Invalid User input." << endl;
                }
                catch(FileExistsException) {
                    cout << "File does not exist." << endl;
                }
                catch(FileReadException) {
                    cout << "Unable to read from file." << endl;
                }
                delivery.main_menu();
                break;
            case 5:
                cout << "Bye!" << endl;
                exit(0);
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}
