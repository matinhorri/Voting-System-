/**
 * @file CPLVoteBallot.h
 * @author Wenjing Jiang (you@domain.com)
 * @brief CPLVoteBallot saves information of election
 * @version 0.1
 * @date 2023-03-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef CPLVOTEBALLOT_H_
#define CPLVOTEBALLOT_H_

#include "IVoteBallot.h"
#include "Party.h"
#include <string>

/**
 * @brief 
 * 
 */
class CPLVoteBallot : public IVoteBallot {
    public:

	/**
	 * \brief Create a new CPLVoteBallot
	 *
	 * \param parties list of parties that participate election
	 * \param mapBallot map of parties and their total number of ballots received
	 * \param mapAllocated map of parites and the number of seats they received
	 * \param mapRemain map of parties and the number of remaining ballots
	 * \param numSeat total number of seats
	 * \param partyNum total number of parties
	 * \param quotaNum quota value
	 * \return void 
	 */
    	CPLVoteBallot(std::vector<Party*> parties, std::vector<int> mapBallot, std::vector<int> mapAllocated, std::vector<int> mapRemain, int numSeats, int parttNum, int quotaNum);
        CPLVoteBallot();
	/**
	 * \brief Get list of parties that participate election
	 *
	 * \param no parameters
	 * \return std::vector<Party*>
	 */
        std::vector<Party*> getParties() const { return parties; }
	/**
	 * \brief Set a list of parties that participate election
	 *
	 * \param no parameters
	 * \return void 
	 */
        void setParties(const std::vector<Party*> &parties_) { parties = parties_; }
	/**
	 * \brief Get the map of allocated seat
	 *
	 * \param parties_ the new list of parties
	 * \return std::vector<int> 
	 */
        std::vector<int> getMapAllocatedSeat() const { return mapAllocatedSeat; }
	/**
	 * \brief Get the map of allocated seat
	 *
	 * \param mapAllocatedSeat_ the new map of allocated seat
	 * \return void 
	 */
        void setMapAllocatedSeat(const std::vector<int> &mapAllocatedSeat_) { mapAllocatedSeat = mapAllocatedSeat_; }
	/**
	 * \brief Get the map of remaining seats
	 *
	 * \param no parameters
	 * \return std::vector<int> 
	 */
        std::vector<int> getMapRemainSeat() const { return mapRemainSeat; }
	/**
	 * \brief Set the map of remaining seats
	 *
	 * \param mapRemainSeat_ the new map of remaining seats
	 * \return void 
	 */
        void setMapRemainSeat(const std::vector<int> &mapRemainSeat_) { mapRemainSeat = mapRemainSeat_; }
	/**
	 * \brief Get the total number of seats
	 *
	 * \param no parameters
	 * \return int 
	 */
        int getSeats() const { return seats; }
	/**
	 * \brief Set the total number of seats
	 *
	 * \param seats_ tota number of seat
	 * \return void 
	 */
        void setSeats(int seats_) { seats = seats_; }
	/**
	 * \brief Get the map of ballots
	 *
	 * \param no parameters
	 * \return std::vector<int> 
	 */
        std::vector<int> getMapBallot() const { return mapBallot; }
	/**
	 * \brief Get the total number of parties
	 *
	 * \param no parameters
	 * \return int
	 */
        int getNumParties() const { return numParties; }
	/**
	 * \brief Get the quota value
	 *
	 * \param no parameters
	 * \return int 
	 */
        int getQuota() const { return quota; }
    
    private:
	/**
	 * \brief List of parties that participate election
	 */
        std::vector<Party*> parties;
	/**
	 * \brief The map of the number of seats assigned to each party 
	 */
        std::vector<int> mapAllocatedSeat;
	/**
	 * \brief The map of the remaining ballots of each party
	 */
        std::vector<int> mapRemainSeat;
	/**
	 * \brief The map of the total ballots of each party
	 */
        std::vector<int> mapBallot;
	/**
	 * \brief Total number of seats
	 */
        int seats;
	/**
	 * \brief Total number of parties that participate election
	 */
        int numParties;
	/**
	 * \brief Quota value
	 */
        int quota;
};

#endif // CPLVOTEBALLOT_H
