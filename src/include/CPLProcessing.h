/** \file CPLProcessing.h
 *  \brief Process CPL ballot file and save the information of parties,
 *  candidates and seats.
 *
 *  \author Wenjing Jiang
 *  \bug No known bugs.
 */


#include <vector>

#include "IBallotProcessing.h"
#include "Party.h"
#include "Candidate.h"
#include "CPLVoteBallot.h"

class CPLProcessing : public IBallotProcessing {
    public:
	    /**
	     * \brief Create a new CPLProcessing with an input file CPL election
	     *
	     * \param file_ CPL ballot file
	     * \return void 
	     */
	    CPLProcessing(FILE *file_);
	    CPLProcessing(FILE *file_, std::vector<std::string> files_) {
	        file = file_;
		files = files_;
	    }
	    /**
	     * \brief Output a CPLVoteBallot that contains all ballot information 
	     *
	     * \param no parameter
	     * \return CPLVoteBallot* 
	     */
	    CPLVoteBallot* output();
	    /**
	     * \brief Start to read files/ 
	     *
	     * \param no parameter
	     * \return bool
	     */
	    bool read();
	    /**
	     * \brief Parse files and save ballot infomration/ 
	     *
	     * \param no parameter
	     * \return bool
	     */
	    bool setUp();
	    /**
	     * \brief Read header information of input file and check consistency 
	     *
	     * \param multiple If the input file is an additional file
	     * \return bool
	     */
	    bool readHeader(int multiple);


	private:
	    /**
	     * \brief Total number of parties that participate election
	     */
		int numParties;
	    /**
	     * \brief List of parties that participate election
	     */
		std::vector<Party*> parties;
	    /**
	     * \brief Map to save how many seats that each party is assgined
	     */
        std::vector<int> mapAllocatedSeat;
	    /**
	     * \brief Map to save how many seats that each party can receive
	     */
        std::vector<int> mapRemainSeat;
	    /**
	     * \brief Map to save how many ballots that each party have now
	     */
        std::vector<int> mapRemainBallot;
	    /**
	     * \brief Number of total seats
	     */
		int seat;
	    /**
	     * \brief Number of ballots needed to get one seat
	     */
		int quota;
	    /**
	     * \brief Lines in ballot file
	     */
		char buffer [100];
};
