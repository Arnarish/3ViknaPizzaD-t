#include "mainui.h"

using namespace std;

ManagementUI::ManagementUI() {
    ui_text = " --- Management ---\n"
              " 1.  New pizza base\n"
              " 2.  New topping\n"
              " 3.  New menu item\n"
              " 4.  New product\n"
              " 5.  New pick-up location\n"
              " 6.  Exit\n";
}

void ManagementUI::main_menu() {
    char c;
    int m;
    while (true) {
        cout << ui_text << endl;
        cout << "Selection: ";
        cin >> c;
        cout << endl;
        m = c - 48;
        switch (m) {
            // Lets wrap these switch cases in blocks so I can reuse variable names (I'm lazy)
            case 1: {
                    string name;
                    int price;
                    int size;
                    // Pizza base is a class (char[128], int, int)
                    cout << "Base name: ";
                    cin.ignore(); // Ignore a newline character in the stream
                    getline(cin, name);
                    cout << "Price: ";
                    cin >> price;
                    cout << "Size: ";
                    cin >> size;
                    // TODO: Wrap this into a try-catch block and relay info back to the user
                    management_service.create_new_base(name, price, size);
                } break;
            case 2: {
                    // Topping is a class
                    string name;
                    int price;
                    cout << "Topping name: ";
                    cin.ignore(); // Ignore a newline character in the stream
                    getline(cin, name);
                    cout << "Price: ";
                    cin >> price;
                    // TODO: Wrap this into a try-catch block and relay info back to the user
                    management_service.create_new_topping(name, price);
                } break;
            case 3: {
                // The menu is a dynamic array or a vector of pizza classes
                    management_service.create_new_menu_item();
                } break;
            case 4: {
                // Product is a class
                } break;
            case 5: {
                // Locations are enums? TODO: think about this
                } break;
            case 6: 
                return;
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}
