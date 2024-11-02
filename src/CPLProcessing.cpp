/** \file CPLProcessing.cpp
 *  \brief Process CPL ballot file and save the information of parties,
 *  candidates and seats.
 *
 *  Implementation of the functions of CPLProcessing
 *
 *  \author Wenjing Jiang
 *  \bug No known bugs.
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <numeric>

#include "include/CPLProcessing.h"

CPLProcessing::CPLProcessing(FILE *file_) {
    file = file_;
};

bool CPLProcessing::setUp() {
    read();

    for(int i = 1; i < (int)files.size(); i++) {
        file = fopen(files[i].c_str(), "r");

        if(!readHeader(1)) {
            invalid_files.push_back(files[i]);
            continue;
        }
    }

    for(int i = 0; i < (int)invalid_files.size(); i++) {
        cout << "Invalid files: " << invalid_files[i] << " ";
        if(i < (int)invalid_files.size()) {
            cout << endl;
        }
    };
    return true;
}

bool CPLProcessing::read() {
    if (file == NULL) {
    	perror ("Error opening file");
    	return false;
    }
    else {
    	int iLine = 0;
        while ( ! feof(file) )
        {
            if ( fgets(buffer, 100 , file) == NULL ) break;
            if (iLine == 0) {
                numParties = atoi(buffer);
                //std::cout << numParties;
            }
            if (iLine == 1) {
                char *pch = strtok(buffer,",\n");
                for (int i=0; i < numParties; i++){
            	    //std::cout << pch << endl;
            	    vector<Candidate> candidates;
            	    Party *party = new Party(candidates ,0 , pch);
            	    parties.push_back(party);
            	    mapAllocatedSeat.push_back(0);
            	    mapRemainBallot.push_back(0);
            	    mapRemainSeat.push_back(0);
            	    pch = strtok(NULL,",\n");
                }
            }
            if (iLine >= 2){
            	if (iLine < 2+numParties) {
            		//vector<Candidate> candidates;
            		char *pch = strtok(buffer,",\n");
            		while (pch) {
            			//std::cout << pch << endl;
            			string partyName = parties[iLine-2]->getName();
            			//std::cout << partyName << endl;
            			Candidate candidate = Candidate(pch, partyName);
            			parties[iLine-2]->setCandidate(candidate);
            			pch = strtok(NULL,",\n");
            		}
            		//parties[iLine-2]->setCandidate(candidate);
            		parties[iLine-2]->setMaxSeat(parties[iLine-2]->getCandidate().size());
            		mapRemainSeat[iLine-2] = parties[iLine-2]->getCandidate().size();
            	}
		//Candidate testCan = parties[iLine-2]->getCandidate()[0];
		//std::cout << "Test candidate name: " << testCan.getName() << endl;
            	if (iLine == 2+numParties) {
            		seat = atoi(buffer);
            		//std::cout << seat << endl;
                }
                if (iLine == 2+numParties+1) {
            		bLinesToRead = atoi(buffer);
            		//std::cout << bLinesToRead << endl;

		        audit->write("CPL");
	                audit->write("Number of Parties: "+ to_string(numParties));
	                audit->write("Candidates in each party: ");
	                for (int i=0; i < numParties; i++) {
	                    string party_candidates = "-- ";
	                    party_candidates += parties[i]->getName() + ": ";
	                    std::vector<Candidate> p_candidates = parties[i]->getCandidate();
	                    for (int j=0; j < (int)p_candidates.size(); j++) {
	                        party_candidates += p_candidates[j].getName() + " ";
	                    }
	                    audit->write(party_candidates);
	                }
	                audit->write("Number of ballots: " + to_string(bLinesToRead));
			audit->write("Number of seats: " + to_string(seat));
                        audit->write("-----BALLOT PROCESS----- \n");
                }
                if (iLine > 2+numParties+1) {
                	char vote = '1';
	            	if (iLine <= 2+numParties+1+bLinesToRead) {
	            		for (int i=0; i < numParties; i++) {
	            			if (buffer[i] == vote){
	            				mapRemainBallot[i] += 1;
	            				//std::cout << buffer[i]<< ',' << i << endl;
						audit->write("|| Ballot " + to_string(iLine-(2+numParties+1)) + "||");
						audit->write("Ballot -> "+parties[i]->getName()+"\n");
	            			}
	            		}
	            	}                	
                }
            }
            iLine += 1;
        }
        //for (int i=0; i < numParties; i++) {
        //	//std::cout << mapRemainBallot[i]<< endl;
        //}
        quota = bLinesToRead/seat;
        std::cout << "quota: " << quota << endl;
	audit->write("-----Quota (#Ballots/#Seats)-----");
        audit->write("Quota = "+ to_string(quota) +"\n");
        fclose(file);
        return true;
    }
};

bool CPLProcessing::readHeader(int multiple) {
    if (file == NULL) {
    	perror ("Error opening file");
    	return false;
    }
    if(multiple) {
    	int iLine = 0;
        while ( ! feof(file) )
        {
            if ( fgets(buffer, 100 , file) == NULL ) break;
            if (iLine == 1) {
                int numParties_add = atoi(buffer);
		if (numParties_add != numParties) {
		    std::cout << "numParties not match" << numParties_add << numParties << endl;
		    return false;
		}
            }
            if (iLine == 2) {
                char *pch = strtok(buffer,",\n");
                for (int i=0; i < numParties; i++){
            	    if (pch != parties[i]->getName()) {
			std::cout << "party not match" << pch << parties[i]->getName() << endl;
			return false;
		    }
            	    pch = strtok(NULL,",\n");
                }
            }
            if (iLine >= 3){
            	if (iLine < 3+numParties) {
            		char *pch = strtok(buffer,",\n");
			int can_idx = 0;
            		while (pch) {
            			Candidate candidate = parties[iLine-3]->getCandidate()[can_idx];
				if (pch != candidate.getName()) {
				    std::cout << "candidate not match" << pch << candidate.getName() << endl;
			            return false;
				}
				pch = strtok(NULL,",\n");
				can_idx += 1;
            		}
            	}
            	if (iLine ==3+numParties) {
            	    int seat_add = atoi(buffer);
		    if (seat_add != seat) {
			std::cout << "seat not match" << seat_add << seat << endl;
			return false;
		    }
                }
                if (iLine == 3+numParties+1) {
            		bLinesToRead = atoi(buffer);
		        audit->write("CPL");
	                audit->write("Number of Parties: "+ to_string(numParties));
	                audit->write("Candidates in each party: ");
	                for (int i=0; i < numParties; i++) {
	                    string party_candidates = "-- ";
	                    party_candidates += parties[i]->getName() + ": ";
	                    std::vector<Candidate> p_candidates = parties[i]->getCandidate();
	                    for (int j=0; j < (int)p_candidates.size(); j++) {
	                        party_candidates += p_candidates[j].getName() + " ";
	                    }
	                    audit->write(party_candidates);
	                }
	                audit->write("Number of ballots: " + to_string(bLinesToRead));
			audit->write("Number of seats: " + to_string(seat));
                        audit->write("-----BALLOT PROCESS----- \n");
                }
                if (iLine > 3+numParties+1) {
                	char vote = '1';
	            	if (iLine <= 3+numParties+1+bLinesToRead) {
	            		for (int i=0; i < numParties; i++) {
	            			if (buffer[i] == vote){
	            				mapRemainBallot[i] += 1;
	            				//std::cout << buffer[i]<< ',' << i << endl;
						audit->write("|| Ballot " + to_string(iLine-(3+numParties+1)) + "||");
						audit->write("Ballot -> "+parties[i]->getName()+"\n");
	            			}
	            		}
	            	}                	
                }
            }
            iLine += 1;
        }
        //for (int i=0; i < numParties; i++) {
        //	//std::cout << mapRemainBallot[i]<< endl;
        //}
        quota = std::accumulate(mapRemainBallot.begin(), mapRemainBallot.end(), 0)/seat;
        std::cout << "quota: " << quota << endl;
	audit->write("-----Quota (#Ballots/#Seats)-----");
        audit->write("Quota = "+ to_string(quota) +"\n");
        fclose(file);
        return true;
    }
    return true;
}

CPLVoteBallot* CPLProcessing::output() {
    CPLVoteBallot* cplVoteBallot = new CPLVoteBallot(parties, mapRemainBallot, mapAllocatedSeat, mapRemainSeat, seat, numParties, quota);
    return cplVoteBallot;
};
