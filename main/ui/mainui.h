#ifndef MAINUI_H
#define MAINUI_H

#include <iostream>

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

using namespace std;

class MainUI {
    public:
        MainUI();
        void main_menu();
    private:
        string ui_text;
};

#endif
