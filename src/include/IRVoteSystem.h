/**
 * @file IRVoteSystem.h
 * @author Michael Vang (vang2891@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef IRVOTESYSTEM_H_
#define IRVOTESYSTEM_H_

#include "IVotingSystem.h"
#include "IRBallot.h"
#include "IRProcessing.h"

/**
 * @brief The voting system to conduct the election
 * and determine a winning candidate.
 * 
 * For redistribution, the IR Vote System will use the
 * ballot processing system associating with it.
 * 
 */
class IRVoteSystem : public IVotingSystem {
    public:
        //Constructors
        
        /**
         * @brief Construct a new IRVoteSystem object
         * 
         */
        IRVoteSystem() {};

        /**
         * @brief Construct a new IRVoteSystem objec
         * given the IR Ballot Processing system and the IR Ballot
         * 
         * @param ballotSystem_ IRProcessing* the processing system used in order to redistribute
         * @param ballot IRBallot* contains all the information to conduct the election
         */
        IRVoteSystem(IRProcessing* ballotSystem_, IRBallot* ballot);

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

        /**
         * @brief Get the eliminated candidate. It is
         * the candidate with the lowest amount of ballots.
         * 
         * It is a vector incase there is more than 1 candidate with
         * the same amount of lowest ballots.
         * @return std::vector<IRCandidate*> List of candidate with the lowest amount of ballots. Often times, there's only 1 candidate.
         */
        std::vector<IRCandidate*> getElimnation();


        //Getters + Setters
        /**
         * @brief Get the information used for the vote election
         * 
         * @return IRBallot* 
         */
        IRBallot* getProcessedBallot() const { return processedBallot; }

        /**
         * @brief Set the information used for the vote election
         * 
         * @param processedBallot_ IRBallot*
         */
        void setProcessedBallot(IRBallot* processedBallot_) { processedBallot = processedBallot_; }

        /**
         * @brief Get the ballot processing system used for the vote election
         * 
         * @return IRProcessing* 
         */
        IRProcessing* getBallotSystem() const { return ballotSystem; }

        /**
         * @brief Set the ballot processing system used for the vote election
         * 
         * @param ballotSystem_ IRProcessing*
         */
        void setBallotSystem(IRProcessing* ballotSystem_) { ballotSystem = ballotSystem_; }

        /**
         * @brief Get the winner
         * 
         * @return IRCandidate the winner
         */
        IRCandidate getWinner() const { return winner; }

        /**
         * @brief Set the winner
         * 
         * @param winner_ IRCandidate
         */
        void setWinner(const IRCandidate &winner_) { winner = winner_; }

        /**
         * @brief Get the list of Candidates in the election
         * 
         * @return std::vector<IRCandidate*> 
         */
        std::vector<IRCandidate*> getCandidates() const { return candidates; }

        /**
         * @brief Set the list of Candidates in the election
         * 
         * @param candidates_ vector<IRCandidate*> 
         */
        void setCandidates(const std::vector<IRCandidate*> &candidates_) { candidates = candidates_; }

        

    private:
        IRBallot* processedBallot; ///< Holds the information to conduct the election.
        IRProcessing* ballotSystem; ///< The processing ballot system
        IRCandidate winner; ///< The winner
        std::vector<IRCandidate*> candidates; ///< List of candidates in the election.

};

#endif // IRVOTESYSTEM_H
