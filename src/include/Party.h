/**
 * @file Party.h
 * @author Matin Horri (horri031@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2023-03-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef PARTY_H_
#define PARTY_H_

#include "Candidate.h"
#include <string>
#include <vector>

using namespace std;
/**
 * @brief A class representing a political party with candidate information and seat limits.
 * 
 * This class stores a vector of Candidate objects, an integer maximum number of seats,
 * and a string name for the party. It provides methods to get and set these values, as well
 * as add candidates to the party.
 */
class Party {
    public:
    /**
     * @brief Construct a new Party object with the given candidates, maximum number of seats, and name.
     * 
     * @param candidates A vector of Candidate objects representing the candidates in the party.
     * @param maxSeat An integer representing the maximum number of seats the party can have.
     * @param name A string representing the name of the party.
     */
        Party(vector<Candidate> candidates, int maxSeat, string name);
    /**
     * @brief Construct a new, empty Party object.
     * 
     */
        Party();
    /**
     * @brief Get the name of the party.
     * 
     * @return A string representing the name of the party.
     */
        string getName() {
            return name;
        };
      /**
     * @brief Set the name of the party.
     * 
     * @param newName A string representing the new name of the party.
     */
        void setName(string newName) {
            name = newName;
        };
      /**
     * @brief Get the vector of Candidate objects representing the candidates in the party.
     * 
     * @return A vector of Candidate objects representing the candidates in the party.
     */
        vector<Candidate> getCandidate() {
            return candidates;
        };

    /**
     * @brief Set the maximum number of seats the party can have.
     * 
     * @param newMaxSeat An integer representing the new maximum number of seats for the party.
     */
        void setMaxSeat(int newMaxSeat) {
            maxSeat = newMaxSeat;
        }
     /**
     * @brief Add a new Candidate to the party.
     * 
     * @param candidate A Candidate object representing the new candidate to add to the party.
     */
        void setCandidate(Candidate candidate) {
            candidates.push_back(candidate);
        };
      /**
     * @brief Get the maximum number of seats the party can have.
     * 
     * @return An integer representing the maximum number of seats the party can have.
     */ 
        int getMaxSeat() {
           return maxSeat;
        };       


    protected:
        vector<Candidate> candidates;
        int maxSeat;
        string name;
};

#endif // PARTY_H_
