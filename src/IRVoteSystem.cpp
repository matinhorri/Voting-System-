#include "include/IRVoteSystem.h"
#include "include/TieBreaker.h"
#include "include/PopularityCase.h"

//All access of information comes from ballot
//IRProcessing* system is only there for redistribution
IRVoteSystem::IRVoteSystem(IRProcessing* system, IRBallot* ballot) {
    ballotSystem = system;
    processedBallot = ballot;
};


bool IRVoteSystem::startElection() {
    std::vector<IRCandidate*> elimnateCandidate;
    specialCase.push_back(new TieBreaker());

    while(status != 1) {
        if(conductElection()) {
            status = 1;
            return true;
        }

        //Popularity case
        if(ballotSystem->getNumCandidates() == 2) {
            cout << "IR Election has come to a Popularity case between 2 candidates." <<endl;
            specialCase.push_back(new PopularityCase(candidates));
            int winIndex = specialCase[1]->run();

            if(auditing) {
            audit->write("\\\\ Popular Votes \\\\");
            for(int i = 0; i < (int)candidates.size(); i++) {
                audit->write(candidates[i]->getName() + " [" + to_string(candidates[i]->getNumBallots()) + "] ", false);
            }
            audit->write("\n");
            }

            //PopularityCase returns a large int size to indicate there's a
            //tie breaker required.
        
            if(winIndex > (int)candidates.size()) {
                vector<IRCandidate*> samePopular;
                for(int i = 0; i < (int)candidates.size(); i++) {
                    if(candidates[i]->getNumBallots() != -1) {
                        samePopular.push_back(candidates[i]);
                    }
                }
                winner = *samePopular[specialCase[0]->run()];
                
                cout << "There is a tie among candidates with popularity votes. Tiebreaker initiated." << endl;
                if(auditing) {
                     audit->write("\\\\ Tie between Popularity Vote. Tiebreaker initiated. \\\\");
                }

            } else {
                winner = *candidates[winIndex];  
            }

            status = 1;
            return true;
        }

        //Redistribution
        cout << "There is no majority." << endl;
        elimnateCandidate = getElimnation();
        int indexEliminated = 0;

        if((int)elimnateCandidate.size() > 1) {
            cout << "There is a tie among candidates with the lowest ballot." << endl;
            TieBreaker* t = static_cast<TieBreaker*>(specialCase[0]);
            indexEliminated = t->run((int)elimnateCandidate.size());

            if(auditing) {
                audit->write("\\\\ Tie between candidate with lowest ballots. Tiebreaker initiated. \\\\");
            }
        }
        
        cout << "Candidate " << elimnateCandidate[indexEliminated]->getName() + " has been eliminated." << endl;

        ballotSystem->redistribute(elimnateCandidate[indexEliminated]);
        processedBallot = ballotSystem->output();

    }
    return false;

};

bool IRVoteSystem::conductElection() {
    candidates = processedBallot->getCandidates();
    std::vector<double> mapPercentage = processedBallot->getMapPercentage();

    for(int i = 0; i < (int)mapPercentage.size(); i++) {
        //cout << mapPercentage[i] << " ";
        if(mapPercentage[i] >= 0.51) {
            winner = *candidates[i];
            return true;
        }
    }

    return false;

};

std::vector<IRCandidate*> IRVoteSystem::getElimnation() {
    std::vector<IRCandidate*> lowestCandidate;
    std::vector<int> candidateBallots = processedBallot->getMapBallot();
    int min;

    //Set the minimum
    for(int i = 0; i < (int)candidateBallots.size(); i++) {
        if(candidateBallots[i] != -1) {
            min = candidateBallots[i];
            break;
        }
    }

    //Find the minimum
    for(int i = 1; i < (int)candidateBallots.size(); i++) {
        if (candidateBallots[i] < min && candidateBallots[i] != -1) {
            min = candidateBallots[i];
        }
    }

    //Add the candidate with the minimum ballots to the vector
    for(int i = 0; i < (int)candidates.size(); i++) {
        if(candidateBallots[i] == min) {
            lowestCandidate.push_back(candidates[i]);
        }
    }

    return lowestCandidate;
}
