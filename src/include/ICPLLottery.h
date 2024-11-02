/**
 * @file ICPLLottery.h
 * @author Matin Horri (horri031@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef ICPLLOTTERY_H_
#define ICPLLOTTERY_H_
#include <string>
#include <iostream>
using namespace std;
#include "Party.h"
/**

*@brief A class representing a special case for a lottery process for a set of parties in a voting system.
*@param The CPLLottery class inherits from the ISpecialCase interface class.
*/
class CPLLottery : public ISpecialCase {

    public:
    /**
* @brief Default constructor for the CPLLottery class.
*/
        CPLLottery();
    /**
  * @brief Constructor for the CPLLottery class that takes an array of parties as input.
  * 
  * @param parties An array of parties to be used in the lottery process.
  */
        CPLLottery(Party[] parties);
/**
  * @brief Getter function for the result of the lottery process after 1000 runs.
  * 
  * @return A string representing the result of the lottery process after 1000 runs.
  */
        string result1000() const { return result_1000; }
    /**
  * @brief Setter function for the result of the lottery process after 1000 runs.
  * 
  * @param result1000 A string representing the result of the lottery process after 1000 runs.
  */
        void setResult1000(const string &result1000) { result_1000 = result1000; }
        
            
    protected:
        Party result; 
        std::vector<Party> parties;
        string result_1000; 
};
#endif
