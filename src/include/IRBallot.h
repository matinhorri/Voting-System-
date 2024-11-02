/**
 * @file IRBallot.h
 * @author Michael Vang (vang2891@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef IRVOTEBALLOT_H_
#define IRVOTEBALLOT_H_

#include "IVoteBallot.h"
#include "IRCandidate.h"
#include <string>

/**
 * @brief An output class from the IR Processing class.
 * This class holds objects/information for the IR Vote System 
 * to condut its election and determine who's the winner.
 */
class IRBallot : public IVoteBallot {
    public:

        /**
         * @brief Construct a new IRBallot object
         * @param candidate vector<IRCandidate*> holds all the candidates 
         * 
         * @param candidate vector<IRCandidate*> holds all the candidates 
         * @param mapBallot vector<int> maps the amount of ballot each candidate has
         * @param mapPercentage vector<double> maps the percentage each candidate has overall
         */
        IRBallot(std::vector<IRCandidate*> candidate, std::vector<int> mapBallot, std::vector<double> mapPercentage);
        IRBallot();

        //Getters + Setters
        /**
         * @brief Get the list of Candidates
         * 
         * @return std::vector<IRCandidate*> 
         */
        std::vector<IRCandidate*> getCandidates() const { return candidates; }

        /**
         * @brief Set the list of Candidates
         * 
         * @param candidates_ vector<IRCandidate*>
         */
        void setCandidates(const std::vector<IRCandidate*> &candidates_) { 
            candidates = candidates_; 
            numCandidates = candidates.size();
            }

        /**
         * @brief Get the Percentage mapping
         * 
         * @return std::vector<double> 
         */
        std::vector<double> getMapPercentage() const { return mapPercentage; }

        /**
         * @brief Set the Percentage mapping
         * 
         * @param mapPercentage_ 
         */
        void setMapPercentage(const std::vector<double> &mapPercentage_) { mapPercentage = mapPercentage_; }
        
        /**
         * @brief Get the number of candidates
         * 
         * @return int 
         */
        int getNumCandidates() const { return numCandidates; }

        /**
         * @brief Set the number of candidates
         * 
         * @param numCandidates_ int
         */
        void setNumCandidates(int numCandidates_) { numCandidates = numCandidates_; }

    
    private:
        std::vector<IRCandidate*> candidates; ///< Holds the list of candidates
        std::vector<double> mapPercentage; ///< Holds the mapping percentage of candidates
        int numCandidates; ///< How much candidates
};

#endif // IRVOTEBALLOT_H
