/**
 * @file PopularityCase.h
 * @author Matin Horri (horri031@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef POPULARITYCASE_H
#define POPULARITYCASE_H

#include "ISpecialCase.h"
#include "IRCandidate.h"

/**
 * @brief A class representing a popularity special case implementation.
 * 
 * This class inherits from the ISpecialCase interface and provides an implementation
 * for the run() method. It takes a vector of IRCandidate pointers as input and stores it 
 * in a private member variable. It also provides a helper() method and getter/setter 
 * methods for the candidates member variable.
 */

class PopularityCase : public ISpecialCase {
    public:
    /**
     * @brief Construct a new PopularityCase object with the given vector of IRCandidate pointers.
     * 
     * @param candidates A vector of IRCandidate pointers.
     */
        PopularityCase(std::vector<IRCandidate*>candidates);
    /**
     * @brief Run the popularity special case with the current set of candidates.
     * 
     * @return An integer representing the result of the popularity special case.
     */
        int run();
        //void run1000();
     /**
     * @brief A helper method used internally by the class.
     * 
     * @return An integer representing the result of the helper method.
     */
        int helper();
     /**
     * @brief Get the current set of candidates.
     * 
     * @return A vector of IRCandidate pointers.
     */
        vector<IRCandidate*> getCandidates() const { return candidates; }
    /**
     * @brief Set the current set of candidates to the given vector of IRCandidate pointers.
     * 
     * @param candidates_ A vector of IRCandidate pointers.
     */
        void setCandidates(const vector<IRCandidate*> &candidates_) { candidates = candidates_; }

    private:
        vector<IRCandidate*> candidates;
};

#endif // POPULARITYCASE_H_
