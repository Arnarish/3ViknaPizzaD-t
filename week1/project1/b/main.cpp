#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
    string text;
    ofstream fout;
    fout.open("very_important_text.txt", ios::app);

    while (true) {
        cout << "Write whatever you wish, and it will be saved!" << endl;
        getline(cin, text);
        if (text[0] == '\\') {
            break;
        }
        fout << text << endl;
    }
    return 0;
}

