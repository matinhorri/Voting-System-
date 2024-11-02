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

#ifndef TIEBREAKER_H
#define TIEBREAKER_H

#include "ISpecialCase.h"
#include <ctime>

/**
 * @brief A class representing a tiebreaker special case implementation.
 * 
 * This class inherits from the ISpecialCase interface and provides implementations
 * for the run() and run(int) methods. It also has a default constructor.
 */

class TieBreaker : public ISpecialCase {
    public:
    /**
     * @brief Construct a new TieBreaker object.
     * 
     */
        TieBreaker() {};
    /**
     * @brief Run the tiebreaker special case with default parameters.
     * 
     * @return An integer representing the result of the tiebreaker.
     */
        int run();
    /**
     * @brief Run the tiebreaker special case with the given size parameter.
     * 
     * @param size An integer representing the size parameter for the tiebreaker.
     * @return An integer representing the result of the tiebreaker.
     */
    
        int run(int size);

        //void run1000();

};

#endif // TIEBREAKER_H
