/**
 * @file IRCandidate.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef IRCANDIDATE_H_
#define IRCANDIDATE_H_

#include "Ballot.h"
#include "Candidate.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief A candidate class for an Instant Runoff Candidate.
 * This classs is for holding ballots.
 */
class IRCandidate : public Candidate {
    public:

        /**
         * @brief Construct a new IRCandidate object
         * 
         * @param name a string argument for name of Candidate.
         */
        IRCandidate(string name);

        /**
         * @brief Construct a new IRCandidate object
         * 
         */
        IRCandidate();

        /**
         * @brief Add a ballot to the candidate
         * 
         * @param ballot_ A Ballot class input
         */
        void addBallot(Ballot* ballot_);

        //Getters and setters

        /**
         * @brief Get the Ballot List object
         * 
         * @return vector<Ballot*> 
         */
        vector<Ballot*> getBallotList() {
            return ballotList;
        };
        
        /**
         * @brief Set the Ballot List object
         * 
         * @param list vector<Ballot*>
         */
        void setBallotList(vector<Ballot*> list) {
            ballotList = list;
        };

        // /**
        //  * @brief Get the number of Ballots in an IR Candidate
        //  * 
        //  * @return int 
        //  */
        // int getBallots() {
        //     return numBallots;
        // };

        // /**
        //  * @brief Set the number of Ballots in an IR Candidate
        //  * 
        //  * @param n int
        //  */
        // void setBallot(int n){
        //     numBallots = n;
        // };
        
        /**
         * @brief Get the number of ballots the IR Candidate has.
         * 
         * @return int 
         */
        int getNumBallots() const { return numBallots; }

        /**
         * @brief Set the number of ballots the IR Candidate has.
         * 
         * @param numBallots_ int
         */
        void setNumBallots(int numBallots_) { numBallots = numBallots_; }

        Ballot* popBallot();


    protected:
        int numBallots = 0;  ///< Holds the number of ballots
        vector<Ballot*> ballotList; ///< Hold the list of ballots an IR candidate has.

};

#endif // IRCANDIDATE_H