#include <iostream>
#include "ui/mainui.h"
#include "models/salary.h"
#include "repositories/recordreader.h"
#include "repositories/recordwriter.h"

using namespace std;

int main(void) {
    /*
    Salary s("Bob", "1234", 124.4, 1, 2);
    cout << s;
    s.set_verbose(false);
    cout << s;
    MainUI menu = MainUI();
    menu.main_menu();
    */
    Salary s("Steve", "1234567890", 1234.5, 1, 2);

    RecordWriter rw;
    RecordReader rr;

    cout << "Number of entries: " << rr.entries() << endl;
    rw.append_to_file(s);
    cout << "Number of entries: " << rr.entries() << endl;

    Salary* reads = rr.read_file();
    int n = rr.entries();
    for (int i = 0; i < n; i++) {
        cout << reads[i] << endl;
    }

    Salary* sals = new Salary[2];
    Salary s1("Bob", "1234567890", 1234.5, 1, 2);
    Salary s2("Fred", "1234567890", 1234.5, 1, 2);
    sals[0] = s1;
    sals[1] = s2;

    rw.write_entire_file(sals, 2);
    cout << "Number of entries: " << rr.entries() << endl;

    delete[] sals;
    delete[] reads;

    return 0;
}
