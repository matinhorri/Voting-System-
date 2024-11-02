#include "include/IRBallot.h"

IRBallot::IRBallot(std::vector<IRCandidate*> can, std::vector<int> ballot, std::vector<double> percent){
    candidates = can;
    mapBallot = ballot;
    mapPercentage = percent;
    numCandidates = candidates.size();
}

IRBallot::IRBallot() {

};