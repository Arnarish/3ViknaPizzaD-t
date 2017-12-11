#ifndef PREPERATION_H
#define PREPERATION_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32

#include <iostream>
#include <string>
using namespace std;

class PreperationUI
{
    public:
        Preperation();
        void main_menu();
        void ask_place();


    private:
        string ui_text;
};

#endif // PREPERATION_H
