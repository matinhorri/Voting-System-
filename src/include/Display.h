/**
 * @file Display.h
 * @author Matin Horri (horri031@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DISPLAY_H
#define DISPLAY_H

// #include "IVoteBallot.h"
// #include "Candidate.h"
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

/**

@class Display
@brief The Display class represents a display that can be used to output information.
*/

class Display {
    public: 
/**
@brief Constructor for the Display class.
@param outputTerminal The output terminal to be used.
*/
        Display(string outputTerminal);
/**
@brief Default constructor for the Display class.
*/    
        Display();
/**
@brief A function to append to the output terminal.
@param outputTerminal is the information that will be appended to the terminal.
*/
        // void write(string outputTerminal);//append to the output terminal
/**
@brief A function to overwrite the output terminal.
@param outputTerminal The new output to be displayed.
*/
        void overWrite(string outputTerminal);//overwrite, just clear
/**
@brief A function to print the output.
@return The output.
*/
        string print();//show the output
/**
@brief Getter function for the output terminal.
@return The output terminal.
*/
        string getOutputTerminal() const { return outputTerminal; }
/**
@brief Setter function for the output terminal.
@param outputTerminal_ The output terminal to be set.
*/
        void setOutputTerminal(const string &outputTerminal_) { outputTerminal = outputTerminal_; }

    protected:
        string outputTerminal; 

};
#endif
