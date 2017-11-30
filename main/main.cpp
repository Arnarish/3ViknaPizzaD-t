#include <iostream>
#include <fstream>
#include <string>
#include "topping.h"

using namespace std;

string read_menu() {
    ifstream fin;
    fin.open("pizza_menu.txt");

    string menu = "";
    string buf;
    if (fin.is_open()) {
        while (!fin.eof()) {
            getline(fin, buf);
            if (fin.eof())
                break;
            menu += buf + "\n";
        }
    }
    else {
        //TODO: throw exception
        return "oops";
    }
    return menu;
}

void create_new_topping() {
    cout << "hey new topping time yass" << endl;
}

int main(void)
{
    string menu = read_menu();
    int selection;
    int subselection;
    while (true) {
        cout << menu << ">> Make your selection: ";
        cin >> selection;
        if (!cin.fail()) {
            switch (selection) {
                case 1:
                    // Go to the administration submenu
                    //TODO: clean this up
                    cout << " * 1) Create new topping\n"
                         << " * 2) Create new base pizza\n"
                         << ">> ";
                    cin >> subselection;
                    if (subselection == 1) {
                        create_new_topping();
                    }
                    break;
                case 2:
                    // Go to the order menu
                    break;
                case 3:
                    //TODO: clean this up
                    cout << "* 1) Manage placed orders\n"
                         << "* 2) Manage prep orders\n"
                         << "* 3) Manage deliveries\n"
                         << "* 4) Manage order\n"
                         << ">> ";
                    cin >> subselection;
                    break;
                case 4:
                    cout << "Bye!" << endl;
                    return 0;
                default:
                    cout << "Sorry, that's not a valid option" << endl;
            }
        }
        else {
            cout << "Sorry, that's not a valid option" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
    return 0;
}

