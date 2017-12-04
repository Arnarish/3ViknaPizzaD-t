#include <iostream>
#include "ui/mainui.h"
#include "models/salary.h"

using namespace std;

int main(void) {
    /*
    Salary s("Bob", "1234", 124.4, 1, 2);
    cout << s;
    s.set_verbose(false);
    cout << s;
    */
    MainUI menu = MainUI();
    menu.main_menu();

    return 0;
}
