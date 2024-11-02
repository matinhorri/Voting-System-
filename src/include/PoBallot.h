/**
 * @file PoBallot.h
 * @author Matin Horri (horri031@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-05-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef POVOTEBALLOT_H_
#define POVOTEBALLOT_H_

#include "IVoteBallot.h"
#include "Candidate.h"
#include <string>

/**
 * @brief An output class from the Po Processing class.
 * This class holds objects/information for the Po Vote System 
 * to condut its election and determine who's the winner.
 */
class PoBallot : public IVoteBallot {
    public:

        /**
         * @brief Construct a new PoBallot object
         * @param candidate vector<Candidate*> holds all the candidates 
         * @param mapBallot vector<int> maps the amount of ballot each candidate has
         * @param mapPercentage vector<double> maps the percentage each candidate has overall
         */
        PoBallot(std::vector<Candidate*> candidate, std::vector<int> mapBallot, std::vector<double> mapPercentage);
        PoBallot();

        //Getters + Setters
        /**
         * @brief Get the list of Candidates
         * 
         * @return std::vector<PoCandidate*> 
         */
        std::vector<Candidate*> getCandidates() const { return candidates; }

        /**
         * @brief Set the list of Candidates
         * 
         * @param candidates_ vector<PoCandidate*>
         */
        void setCandidates(const std::vector<Candidate*> &candidates_) { 
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
        std::vector<Candidate*> candidates; ///< Holds the list of candidates
        std::vector<double> mapPercentage; ///< Holds the mapping percentage of candidates
        int numCandidates; ///< How many candidates
};

#endif // PoVOTEBALLOT_H