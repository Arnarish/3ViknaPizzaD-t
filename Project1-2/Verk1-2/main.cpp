#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout;
    string text;
    bool quit = false;
    fout.open("textOutput.txt", ios::app);
    do{
        cout << "Please enter the text you wish to input into the text file." << endl;
        getline(cin, text);

        if(text[0] == '\\')
        {
            quit = true;
            break;
        }

        if(fout.is_open())
        {
            fout << text << endl;
        }
        else
        {
            cout << "File could not be opened." << endl;;
        }
    }while(!quit);
    fout.close();

    return 0;
}
