#include "RecordsUI.h"

RecordsUI::RecordsUI()
{
    //ctor
}

void RecordsUI::menu()
{
    newempui newui;
    char input;
    while(true) // skrifar UI, getur lesið inn eða skrifað út upplýsingar í file.
    {
        cout << "Please select the desired function from the list below: " << endl;
        cout << "1) Enter new salary records for an employee." << endl;
        cout << "2) Write out the employee records." << endl << endl;
        cout << "Please select your desired function: ";
        cin >> input;

        if(!validateinput(input))// ef input er ekki 1 eða 2
        {
            cout << "Incorrect input! please try again." << endl;
        }
        else if(validateinput(input))
        {
            switch(input)
            {
            case '1':
                newui.addMenu();// fara í New salary ui
            case '2':
                ;// fara í write salary ui

            }

        }
    }

}

bool RecordsUI::validateinput(char input)
{
    if(isalnum(input))//ef input er tala
    {
        if(input > 0 || input < 3) // stærri en 0, minni en 3
        {
            return true;
        }
    }
    return false;
}
