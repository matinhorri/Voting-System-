/**
 * @file IRProcessing.h
 * @author Michael Vang (vang2891@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef IRPROCESSING_H_
#define IRPROCESSING_H_

#include "IRBallot.h"
#include "IBallotProcessing.h"

/**
 * @brief IR Processing is to process all ballots in a
 * .csv file and prepare an organized set of information to send
 * to the IRVoteSystem class, conducting and determining the winner.
 * 
 * THe processing will also handle redistribution if
 * a candidate is eliminated.
 * 
 */
class IRProcessing: public IBallotProcessing {
    public:

        IRProcessing() {};

        /**
         * @brief Construct a new IRProcessing object.
         * 
         * @param file FILE (the .csv file)
         */
        IRProcessing(FILE *file_) {
            file = file_;
        };

        /**
         * @brief Construct a new IRProcessing object
         * 
         * @param file_ The FILE object (the first one)
         * @param files_ List of all the files inputted
         */
        IRProcessing(FILE *file_, std::vector<std::string> files_) {
            file = file_;
            files = files_;
        }

        /**
         * @brief Construct a new IRProcessing object
         * given the IRBallot (A class containing the organized
         * information to send to vote election).
         * @param ballot IRBallot*
         */
        IRProcessing(IRBallot *ballot_) {
            voteBallot = ballot_;
        };

        /**
         * @brief Helper function to read the next line and
         * return the contente seperated by ','.
         * 
         * @return char* 
         */
        char* nextLine();

        /**
         * @brief Overall function to control
         * reading the header informations of multiple
         * files and redistributing approriate ballots.
         * @return true if the set up was suceessful
         * @return false if the set up fail
         */
        bool setUp();

        /**
         * @brief Function to read the header parts of the .csv file
         * and fill out the necessarily information.
         * Does not read the ballots in the .csv file.
         * @return true if the set up was suceessful
         * @return false if the set up fail
         */
        bool readHeader(int multiple);

        /**
         * @brief Function to read all the ballots in the .csv
         * and distribute to each candidate.
         * 
         * @return true if the reading was sucessful
         * @return false if the reading failed
         */
        bool read();

        /**
         * @brief Create an object holding required information
         * for the voting election in order to conduct.
         * 
         * @return IRBallot* the class containing information.
         */
        IRBallot* output();

        /**
         * @brief Calculate the map percentage.
         * Each candidate's number of ballots is divided by the
         * total ballots found in the .csv file.
         */
        void calculate();

        /**
         * @brief Function to remove all the ballots in a
         * eliminated candidate and distribute the ballot to
         * the next preference candidate.
         * 
         * @param cand IRCandidate* the eliminated candidate.
         * @return true if redistribution was sucessful.
         * @return false if an error has occured.
         */
        bool redistribute(IRCandidate* cand);


        //Getters and Setters
        /**
         * @brief Get the number of candidates left in election.
         * 
         * @return int 
         */
        int getNumCandidates() const { return numCandidates; }

        /**
         * @brief Set the number of candidates left in election.
         * 
         * @param numCandidates_ int
         */
        void setNumCandidates(int numCandidates_) { numCandidates = numCandidates_; }

        /**
         * @brief Get the list of IRCandidates
         * 
         * @return std::vector<IRCandidate*> 
         */
        std::vector<IRCandidate*> getCandidates() const { return candidates; }

        /**
         * @brief Set the list of IRCandidates
         * 
         * @param candidates_ vector<IRCandidate*>
         */
        void setCandidates(const std::vector<IRCandidate*> &candidates_) { candidates = candidates_; }

        /**
         * @brief Get the mapping of percentage
         * 
         * @return std::vector<double> 
         */
        std::vector<double> getMapPercentage() const { return mapPercentage; }

        /**
         * @brief Set the percentage mapping
         * 
         * @param mapPercentage_ vector<double>
         */
        void setMapPercentage(const std::vector<double> &mapPercentage_) { mapPercentage = mapPercentage_; }

        /**
         * @brief Get the list of inputted files.
         * 
         * @return std::vector<string> 
         */
        std::vector<string> getFiles() const { return files; }

        /**
         * @brief Set the list of inputted files.
         * 
         * @param files_ 
         */
        void setFiles(const std::vector<string> &files_) { files = files_; }
        

    private:
        int numCandidates; ///< Holds the number of candidate STILL IN ELECTION.
        std::vector<IRCandidate*> candidates; ///< Holds the list of candidates
        std::vector<double> mapPercentage; ///< Holds the percentage mapping of ballots to candidates.


        char buffer[100]; ///< Buffer for reading in from the .csv file
};


#endif // IRPROCESSING_H
