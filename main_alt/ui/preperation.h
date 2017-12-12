#ifndef PREPERATION_H
#define PREPERATION_H

#if _WIN32
#include <stdlib.h>
#endif // _WIN32
#include "../repositories/locationio.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class PreperationUI
{
    public:
        PreperationUI();
        void main_menu();
        void ask_place();


    private:
        string ui_text, location;
        locationio locio;
};

#endif // PREPERATION_H
