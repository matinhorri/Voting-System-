#include "include/PopularityCase.h"

PopularityCase::PopularityCase(std::vector<IRCandidate*> candidates_) {
    candidates = candidates_;
}

int PopularityCase::run() {
    return helper();
}

int PopularityCase::helper() {
    int max = 0;
    int winIndex = 0;
    for(auto i = 0; i < (int)candidates.size(); i++) {
        if(candidates[i]->getNumBallots() == max) {
            max += 100;
            return max;
        }

        if(candidates[i]->getNumBallots() > max) {
            max = candidates[i]->getNumBallots();
            winIndex = i;
        }
    }

    return winIndex;
};