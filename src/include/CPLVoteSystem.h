/** \file CPLVoteSystem.h
 *  \brief Conduct election and show winners.
 *
 *  \author Wenjing Jiang
 *  \bug No known bugs.
 */


#include "CPLVoteBallot.h"
#include "IVotingSystem.h"
#include <vector>

class CPLVoteSystem : public IVotingSystem {
    public:
	/**
	 * \brief Create a new CPLVoteSystem with an input CPLVoteBallot
	 *
	 * \param incomingBallot CPL ballot file
	 * \return void 
	 */
    	CPLVoteSystem(CPLVoteBallot* CPLVoteBallot);
        CPLVoteSystem() {};
	/**
	 * \brief Start election with checking the information ballots of each party
	 *
	 * \param no parameter 
	 * \return bool
	 */
        bool startElection();
	/**
	 * \brief Conduct election according to CPL rules
	 *
	 * \param no parameter
	 * \return tool 
	 */
        bool conductElection();
	/**
	 * \brief Get the number of unassigned seasts
	 *
	 * \param no parameter
	 * \return int 
	 */
	int getRemainSeat() {return remainSeat;};
	/**
	 * \brief Draw lottery for unassigned seats
	 *
	 * \param parties_size Number of parties that can be assigned a seat
	 * \return int 
	 */
	int CPLLottery(int parties_size);
	/**
	 * \brief Get the winners in each party
	 *
	 * \param no parameter
	 * \return std::vector<Candidate> 
	 */
	std::vector<Candidate> getWinner() {return seatWinners;};


    private:
	/**
	 * \brief CPLVoteBallot
	 */
    	CPLVoteBallot* processedBallot;
	/**
	 * \brief The list of winners in election
	 */
    	std::vector<Candidate> seatWinners;
	/**
	 * \brief The list of parties that participate election
	 */
    	std::vector<Party*> parties;
	/**
	 * \brief The map of allocated seat of each party
	 */
    	std::vector<int> mapAllocatedSeat;
	/**
	 * \brief The map of remaining ballots of each party
	 */
        std::vector<int> mapRemainBallot;
	/**
	 * \brief The map of remaining seats of each party
	 */
        std::vector<int> mapRemainSeat;
	/**
	 * \brief Total number seats
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
	/**
	 * \brief Total number of remaining seats
	 */
        int remainSeat;
};
