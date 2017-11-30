#include <iostream>
#include <fstream>
#include <string>

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

void do_stuff() {
    cout << "Hey you're in a submenu now wowie oooo" << endl;
}

int main(void)
{
    string menu = read_menu();
    int selection;
    while (true) {
        cout << menu << "Make your selection: ";
        cin >> selection;
        if (!cin.fail()) {
            switch (selection) {
                case 1:
                    do_stuff();
                    break;
                case 2:
                    do_stuff();
                    break;
                case 3:
                    do_stuff();
                    break;
                case 4:
                    do_stuff();
                    break;
                case 5:
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

