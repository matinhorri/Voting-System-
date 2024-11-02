/**
 * @file PoProcessing.h
 * @author Shivali Mukherji (mukhe105@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-04-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef POPROCESSING_H_
#define POPROCESSING_H_

#include "PoBallot.h"
#include "IBallotProcessing.h"
#include "Candidate.h"

/**
 * @brief PO Processing is to process all ballots in a
 * .csv file and prepare an organized set of information to send
 * to the PoVoteSystem class, conducting and determining the winner.
 * 
 * 
 */
class PoProcessing: public IBallotProcessing {
    public:

        PoProcessing() {};

        /**
         * @brief Construct a new PoProcessing object.
         * 
         * @param file FILE (the .csv file)
         */
        PoProcessing(FILE *file_) {
            file = file_;
        };

        /**
         * @brief Construct a new PoProcessing object
         * 
         * @param file_ The FILE object (the first one)
         * @param files_ List of all the files inputted
         */
        PoProcessing(FILE *file_, std::vector<std::string> files_) {
            file = file_;
            files = files_;
        }

        /**
         * @brief Construct a new PoProcessing object
         * given the PoBallot (A class containing the organized
         * information to send to vote election).
         * @param ballot PoBallot*
         */
        PoProcessing(PoBallot *ballot_) {
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
        PoBallot* output();

        /**
         * @brief Calculate the map percentage.
         * Each candidate's number of ballots is divided by the
         * total ballots found in the .csv file.
         */
        void calculate();

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

		//Getters and Setters
        /**
         * @brief Get the number of ballots for each candidate.
         * 
         * @return int 
         */
        int getNumBallots() const { return numBallots; }

        /**
         * @brief Set the number of ballots for each candidate.
         * 
         * @param numBallots_ int
         */
        void setNumBallots(int numBallots_) { numBallots = numBallots_; }

        /**
         * @brief Get the list of Candidates
         * 
         * @return std::vector<Candidate*> 
         */
        std::vector<Candidate*> getCandidates() const { return candidates; }

        /**
         * @brief Set the list of Candidates
         * 
         * @param candidates_ vector<Candidate*>
         */
        void setCandidates(const std::vector<Candidate*> &candidates_) { candidates = candidates_; }

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
		int numBallots = 0; ///< Holds number of ballots for each candidate in the election
        std::vector<Candidate*> candidates; ///< Holds the list of candidates
        std::vector<double> mapPercentage; ///< Holds the percentage mapping of ballots to candidates.


        char buffer[100]; ///< Buffer for reading in from the .csv file
};


#endif // POPROCESSING_H
