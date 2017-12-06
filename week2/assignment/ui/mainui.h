#ifndef MAINUI_H
#define MAINUI_H

#include <iostream>
#include <string>
#include "../models/salary.h"
#include "../services/salaryservice.h"

using namespace std;

class MainUI {
    public:
        MainUI();
        void main_menu();
        void get_new_entry();
        void list_by_ssn();
        void list_total_wages();
        void top_employee();

    private:
        SalaryService service;
        string ui_text;
        string name;
        string ssn;
        double salary;
        int month;
        int year;
        // TODO: add the next layer
};

#endif
