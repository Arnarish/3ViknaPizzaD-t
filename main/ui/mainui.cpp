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
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        while (!(cin >> m)) {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Selection: ";
        }
        cout << endl;
        switch (m) {
            case 1:
                management.main_menu();
                break;
            case 2:
                ordering.main_menu();
                break;
            case 3:
                try {
                    preperation.main_menu();
                }
                catch (UserInputException) {
                    cout << "Invalid input." << endl;
                }
                catch (FileExistsException) {
                    cout << "File does not exist." << endl;
                }
                catch (FileReadException) {
                    cout << "Unable to read from file." << endl;
                }
                break;
            case 4:
                try {
                    delivery.ask_place();
                }
                catch (UserInputException) {
                    cout << "Invalid User input." << endl;
                }
                catch (FileExistsException) {
                    cout << "File does not exist." << endl;
                }
                catch (FileReadException) {
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
    }
}
