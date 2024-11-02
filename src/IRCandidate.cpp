
#include "include/IRCandidate.h"

using namespace std;

IRCandidate::IRCandidate(string name_) {
    name = name_;
};

IRCandidate::IRCandidate() {};

void IRCandidate::addBallot(Ballot* ballot) {
    ballotList.push_back(ballot);
    numBallots++;
};

/*Ballot* IRCandidate::popBallot() {
    Ballot* returnedBallot = ballotList.back();
    ballotList.pop_back();
    return returnedBallot;
}*/

/*void IRCandidate::increaseNum() {
    numBallots++;
}*/

Ballot* IRCandidate::popBallot() {
    if(ballotList.size() == 0) {
        return NULL;
    } 
    
    Ballot* returnedBallot = ballotList.back();
    ballotList.pop_back();

    return returnedBallot;
}

/*void IRCandidate::increaseNum() {
    numBallots++;
}*/

