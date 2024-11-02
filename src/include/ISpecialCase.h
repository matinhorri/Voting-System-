/**
 * @file ISpecialCase.h
 * @author Michael Vang (vang2891@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ISPECIALCASE_H
#define ISPECIALCASE_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;
/**

*@file ISpecialCase.h
*@brief This is the header file for the ISpecialCase abstract class which defines the interface for special case ballot processing classes.
*/

class ISpecialCase
{
    public: 
    /**
     * @brief Runs the special case ballot processing
     * 
     * This function runs the special case ballot processing.
     * 
     * @return int Returns the result of the processing as an integer.
     */
        virtual int run() = 0;
        //virtual void run1000() = 0;

    protected:
        std::vector<int> mapBiasTracker;
};

#endif // ISPECIALCASE_H
