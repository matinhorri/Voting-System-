/**
 * @file IVoteBallot.h
 * @author Michael Vang (vang2891@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef IVOTEBALLOT_H_
#define IVOTEBALLOT_H_

#include <vector>

/**
 * @brief The abstract class
 * where all VoteBallots are inherited from.
 * 
 * VoteBallots contains all necessarily information and is produced
 * by a Ballot Processing class.
 * 
 * VoteBallots are used in its pertaining Vote Election to conduct
 * an election
 * 
 */
class IVoteBallot {
    public:

        /**
         * @brief get the mapping of ballots to <candidates / parties / ...>
         * 
         * @return std::vector<int> 
         */
        std::vector<int> getMapBallot() const { return mapBallot; }

        /**
         * @brief Set the mapping of ballots to <candidates / parties / ...>
         * 
         * @param mapBallot_ 
         */
        void setMapBallot(const std::vector<int> &mapBallot_) { mapBallot = mapBallot_; }

        /**
         * @brief Get the total amount of ballots
         * 
         * @return int 
         */
        int getTotalBallot() const { return totalBallot; }

        /**
         * @brief Set the total amount of ballots
         * 
         * @param totalBallot_ int
         */
        void setTotalBallot(int totalBallot_) { totalBallot = totalBallot_; }

    protected:
        std::vector<int> mapBallot; ///< Holds the mapping of ballots
        int totalBallot; ///< total amount of ballots
};
#endif // IVOTEBALLOT_H

