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
                try {
                    management.main_menu();
                }
                catch(FileEmptyException) {
                    cout << "Critical: file is empty." << endl;
                }
                catch(FileExistsException) {
                    cout << "Critical: file does not exist." << endl;
                }
                catch(FileReadException) {
                    cout << "Critical: unable to read from file." << endl;
                }
                catch(FileWriteException) {
                    cout << "Critical: unable to write to file." << endl;
                }
                break;
            case 2:
                try {
                    ordering.main_menu();
                }
                catch(FileEmptyException) {
                    cout << "Critical: file is empty." << endl;
                }
                catch(FileExistsException) {
                    cout << "Critical: file does not exist." << endl;
                }
                catch(FileReadException) {
                    cout << "Critical: unable to read from file." << endl;
                }
                catch(FileWriteException) {
                    cout << "Critical: unable to write to file." << endl;
                }
                break;
            case 3:
                try {
                    preparation.main_menu();
                }
                catch (UserInputException) {
                    cout << "Invalid input." << endl;
                }
                catch(FileEmptyException) {
                    cout << "Critical: file is empty." << endl;
                }
                catch(FileExistsException) {
                    cout << "Critical: file does not exist." << endl;
                }
                catch(FileReadException) {
                    cout << "Critical: unable to read from file." << endl;
                }
                catch(FileWriteException) {
                    cout << "Critical: unable to write to file." << endl;
                }
                break;
            case 4:
                try {
                    delivery.main_menu();
                }
                catch(FileEmptyException) {
                    cout << "Critical: file is empty." << endl;
                }
                catch(FileExistsException) {
                    cout << "Critical: file does not exist." << endl;
                }
                catch(FileReadException) {
                    cout << "Critical: unable to read from file." << endl;
                }
                catch(FileWriteException) {
                    cout << "Critical: unable to write to file." << endl;
                }
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
