#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char cont;
    bool quit = false;
    string str;
    ifstream fin;
    fin.open("test_file.txt");
    if(fin.is_open())
    {
        while(!fin.eof())
        {
            for(int i = 0; i < 10; i++)
            {
                getline(fin, str);
                cout << str << endl;
            }
            cout << "Do you wish to continue? (Y/N)" << endl;
            cin >> cont;
            while(cont != 'y' && cont != 'Y')
            {
                if (cont == 'n' || cont == 'N')
                {
                    quit = true;
                    break;
                }
                cout << "Incorrect input. Do you wish to continue? (Y/N)" << endl;
                cin >> cont;
            }
            if (quit) 
                break;
        }
        fin.close();
    }
    else
    {
        cout << "Unable to read from file!" << endl;
    }


    return 0;
}
