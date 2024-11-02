/** \file CPLVoteBallot.cpp
 *  \brief Initiate CPLVoteBallot.
 *
 *  \author Wenjing Jiang
 *  \bug No known bugs.
 */
#include "include/CPLVoteBallot.h"

CPLVoteBallot::CPLVoteBallot(std::vector<Party*> parties_, std::vector<int> mapBallot_, std::vector<int> mapAllocated_, std::vector<int> mapRemain, int numSeats, int partyNum, int quotaNum) {
    parties = parties_;
    mapBallot = mapBallot_;
    mapAllocatedSeat = mapAllocated_;
    mapRemainSeat = mapRemain;
    seats = numSeats;
    numParties = partyNum;
    quota = quotaNum;
};
