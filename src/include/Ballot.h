/**
 * @file Ballot.h
 * @author Matin Horri (horri031@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef BALLOT_H_
#define BALLOT_H_

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief A Ballot class to hold an individual ballot
 * found in a Instant Runoff election. Each IR Candidate will
 * hold a list of this Ballot.
 * 
 */
class Ballot {
    public:

        /**
         * @brief Construct a new Ballot object.
         * 
         * @param rank int the current preference (rank).
         * @param mapping vector<int> the mapping of preferences to candidates.
         */
        Ballot(int rank, vector<int> mapping);

        /**
         * @brief Construct a new Ballot object
         * 
         */
        Ballot();

        /**
         * @brief Is used to increase the ranking variable
         */
        void increaseRank();
        
        /**
         * @brief Get the index of ranking in
         * the map.
         * @return int 
         */
        int getIndex();

        /**
         * @brief Get the ranking
         * 
         * @return int 
         */
        int getRank() {
            return rank;
        };
        
        /**
         * @brief Set the ranking. Error checks if the ranking
         * goes below 0 and if the ranking is beyond the size of 
         * the mapping.
         * @param rank_ int
         */
        void setRank(int rank_) {
            if(rank_ <= 0) {
                rank = 1;
            } 
            else if (rank_ > (int)mapping.size()) {
                rank = mapping.size();
            }
            else {
                rank = rank_;
            }
        };

        /**
         * @brief Get the mapping
         * 
         * @return vector<int> 
         */
        vector<int> getMapping() {
            return mapping;
        };

        /**
         * @brief Set the mapping
         * 
         * @param mapping 
         */
        void setMapping(vector<int> &mapping) {
            mapping = this->mapping;
        };

    private:
        int rank; ///< The current ranking of Ballot. Every ballot starts at 1.
        vector<int> mapping; ///< The mapping of the preference (ranking) to candidate
        
};
#endif
