#include "Preperation.h"

PreperationUI::PreperationUI() {
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
    int n = locio.number_of_entries();
    char user_selection;
    cout << "Select location: " << endl;
    cout << "1" << endl;
    char* locations = locio.read_file();
    cout << "2" << endl;
    vector<char> vLocation;
    for(int i=0; i<n; i++) {
        vLocation.push_back(locations[i]);
    }
    cout << "3" << endl;
    for(int i=0; i <= n; i++) {
        cout << i+1 << ". " << vLocation[i] << endl;
    }
    while(cin >> user_selection) {
        if(!cin.fail()) {
            break;
        }
        else
        {
            cout << "Invalid selection." << endl;
        }
    }
    location = locations[user_selection-1];
    cout << location << endl;
    //b�ta vi� a� a� lesa alla sta�i upp �r skr� og
    //f� input fr� '1 - x' (1 = 0 � array)
    //f� string til a� fara me� lengra � forrit
    delete [] locations;
}
