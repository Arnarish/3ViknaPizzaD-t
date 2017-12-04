#include <string>
#include <fstream>
#include "../models/salary.h"
#include "recordwriter.h"

using namespace std;

RecordWriter::RecordWriter() {
    file = "records.dat";
    ofstream fout;
}

void RecordWriter::append_to_file(Salary& salary) {
    fout.open(file, ios::binary | ios::app);
    if (fout.is_open()) {
        fout.write((char*)(&salary), sizeof(Salary));
    }
    else {
        //TODO: throw exception
        cout << "oops" << endl;
    }
    fout.close();
}

void RecordWriter::write_entire_file(Salary* salaries, int n) {
    fout.open(file, ios::binary | ios::trunc);
    if (fout.is_open()) {
        fout.write((char*)salaries, sizeof(Salary) * n);
    }
    else {
        //TODO: throw exception
        cout << "oops" << endl;
    }
    fout.close();
}
