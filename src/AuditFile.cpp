#include "include/AuditFile.h"
using namespace std;

AuditFile::AuditFile() {
    name = "audit";
};

AuditFile::AuditFile(string fileName) {
    name = fileName;
};

void AuditFile::labelFile(string fileName) {
    name = fileName;
};

void AuditFile::open() {
    fileStream.open(name+".txt", ios::trunc);
};

void AuditFile::close() {
    fileStream.close();
};

void AuditFile::produceFile() {
    name = name + ".txt";
    //ofstream myfile(name);
    if (fileStream.is_open()) {
        fileStream << output_result << endl;
        //myfile.close();
    } else {
        cout << "Failed to create file." << endl;
    }
};

void AuditFile::write(string output_result, bool newLine){ 
    if (fileStream.is_open()) {
        fileStream << output_result;
        if(newLine) {
            fileStream << endl;
        }
        //file.close();
    } else {
        cout << "Error writing to file." << endl;
    }
};