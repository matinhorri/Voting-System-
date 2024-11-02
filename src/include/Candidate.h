/**
 * @file AuditFile.h
 * @author Mikel ving (horri031@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef CANDIDATE_H_
#define CANDIDATE_H_

#include <string>

using namespace std;
/**
 * @brief An output class from the IBallotProcessing interface.
 * This class holds objects/information for an election Candidate 
 * including their name and party. These attributes will then be displayed
 * when a candidate wins eiher an IR or CPL election
 */
class Candidate {
    public:
        /*
         * @brief Construct a new Candidate object
         * 
         * @param name a string argument for name of a candidate.
         * @param party a string argument for party that a canidate represents
        */
        Candidate(string name, string party);
        Candidate();
         /**
         * @brief Construct a new IRCandidate object
         * 
         * @param name a string argument for name of Candidate.
         */
        Candidate(string name);

        /*
         * @brief getter method to return the name of a candidate
         * 
        */
        string getName() {
            return name;
        };

        void setName(string name_) {
            name = name_;
        };
        
        string getParty() {
            return party;
        };

        void setParty(string party_) {
            party = party_;
        };

    protected: 
        string name;
        string party;
};

#endif // CANDIDATE_H
