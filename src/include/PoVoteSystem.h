/**
 * @file PoVoteSystem.h
 * @author Shivali Mukherji (mukhe105@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-04-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef POVOTESYSTEM_H_
#define POVOTESYSTEM_H_

#include "IVotingSystem.h"
#include "PoBallot.h"
#include "PoProcessing.h"

/**
 * @brief The voting system to conduct the election
 * and determine a winning candidate.
 * 
 * For redistribution, the IR Vote System will use the
 * ballot processing system associating with it.
 * 
 */
class PoVoteSystem : public IVotingSystem {
    public:
        //Constructors
        
        /**
         * @brief Construct a new PoVoteSystem object
         * 
         */
        PoVoteSystem() {};

        /**
         * @brief Construct a new PoVoteSystem objec
         * given the IR Ballot Processing system and the IR Ballot
         * 
         * @param ballotSystem_ PoProcessing* the processing system used in order to redistribute
         * @param ballot PoBallot* contains all the information to conduct the election
         */
        PoVoteSystem(PoBallot* ballot);

        /**
         * @brief Start the election process and determine a winner
         * 
         * @return true if the winner has been decided
         * @return false if somehow the winner has not been decided
         */
        bool startElection();

        /**
         * @brief Helper function for startElection() where it compares
         * the percentage mapping and if there's a majority winner.
         * @return true if the winner has been decided
         * @return false if somehow the winner has not been decided
         */
        bool conductElection();

      

        //Getters + Setters
        /**
         * @brief Get the information used for the vote election
         * 
         * @return PoBallot* 
         */
        PoBallot* getProcessedBallot() const { return processedBallot; }

        /**
         * @brief Set the information used for the vote election
         * 
         * @param processedBallot_ PoBallot*
         */
        void setProcessedBallot(PoBallot* processedBallot_) { processedBallot = processedBallot_; }

        /**
         * @brief Get the winner
         * 
         * @return Candidate the winner
         */
        Candidate getWinner() const { return winner; }

        /**
         * @brief Set the winner
         * 
         * @param winner_ Candidate
         */
        void setWinner(const Candidate &winner_) { winner = winner_; }

        /**
         * @brief Get the list of Candidates in the election
         * 
         * @return std::vector<Candidate*> 
         */
        std::vector<Candidate*> getCandidates() const { return candidates; }

        /**
         * @brief Set the list of Candidates in the election
         * 
         * @param candidates_ vector<Candidate*> 
         */
        void setCandidates(const std::vector<Candidate*> &candidates_) { candidates = candidates_; }

        

    private:
        PoBallot* processedBallot; ///< Holds the information to conduct the election.
        Candidate winner; ///< The winner
        std::vector<Candidate*> candidates; ///< List of candidates in the election.

};

#endif // POVOTESYSTEM_H
