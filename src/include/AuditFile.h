/**
 * @file AuditFile.h
 * @author Matin Horri (horri031@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef AUDITFILE_H
#define AUDITFILE_H

// #include "IVoteBallot.h"
// #include "Candidate.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;
/**
@brief The AuditFile class represents a file that logs information about a voting audit
*/
class AuditFile{
    public:
/**
@brief Default constructor for the AuditFile class
*/
        AuditFile();
/**
@brief Constructor for the AuditFile class that takes a file name as an argument
@param output_result is the parameter
*/
        AuditFile(string output_result);

        void open();
        void close();
/**
@brief A function to label a file with a specific name
@param name The name of the file to be labeled
  */
        void labelFile(string name);//just the name, need to add second parameter
/**
@brief A function to create a new file
*/
        void produceFile();
/**
@brief A function to write the output into the file
@param output_result The output to be written to the file
*/
        void write(string output_result, bool newLine = true);//write the output into the file
/**
@brief Getter function for the file
  */
        FILE* getFile() const { return file; }
/**
@brief Setter function for the file
@param output_result The output to be written to the file
*/
        void setFile(FILE* file_) { file = file_; }
/**
   @brief Getter function for the ouput
  */
        string getOutputResult() const { return output_result; }
/**
@brief Setter function for the output.
@param outputResult The output to be set.
*/
        void setOutputResult(const string &outputResult) { output_result = outputResult; }
/**
@brief Setter function for the name.
@param the name will set to the name variable.
*/     
        void setName(const string& name_) { name = name_; }
/**
@brief getter function for the name.
@param the name will return the name variable.
*/ 
        string getName() const { return name; }
/**
@brief getter function for the name.
@param the file name variable will return the file name variable.
*/
        string getFileName() const { return fileName; }
/**
@brief Setter function for the file name.
@param the name will set to the file name variable.
*/  
        void setFileName(const string& fileName_) { fileName = fileName_; }
/**

@brief Getter functions for fileStream
*/
        ofstream& getFileStream() { return fileStream; }
    
        
    protected: 
        FILE* file;
        ofstream fileStream;
        string output_result;
        string name;
        string fileName;

};
#endif
