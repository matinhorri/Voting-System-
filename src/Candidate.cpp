#include "include/Candidate.h"

using namespace std;

Candidate::Candidate(string candidateName, string candidateParty) {
    name = candidateName;
    party = candidateParty;
};

Candidate::Candidate(string name_) {
    name = name_;
};

Candidate::Candidate() {};