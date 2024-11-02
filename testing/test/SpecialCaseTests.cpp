#include <gtest/gtest.h>
#include "../../src/include/ISpecialCase.h"
#include "../../src/include/TieBreaker.h"
#include "../../src/include/PopularityCase.h"
#include "../../src/include/IRCandidate.h"

class SpecialCaseTests : public ::testing::Test {
    protected:
        TieBreaker t = TieBreaker();
        IRCandidate Canid1 = IRCandidate("Sally");
        IRCandidate Canid2 = IRCandidate("Tom");
        vector<IRCandidate*> candidates = {&Canid1, &Canid2};
        PopularityCase p = PopularityCase(candidates);

        void SetUp() override {
            Canid1.setNumBallots(10);
            Canid2.setNumBallots(20);
        }

        //void TearDown() override {}
};

TEST_F(SpecialCaseTests, tieBreakerValidGenerator) {
    int result;
    for(int i = 0; i < 10; i++) {
        result = t.run();
        if(result >= 2) {
            FAIL();
        }
    }

    SUCCEED();
};

TEST_F(SpecialCaseTests, tieBreakerRunSize) {
    int result;
    for(int i = 0; i < 20; i++) {
        result = t.run();
        if(result >= 3) {
            FAIL();
        }
    }

    SUCCEED();
};

TEST_F(SpecialCaseTests, popularityCase) {
    int winIndex = p.run();

    EXPECT_EQ(winIndex, 1);

    string expectWinCanid = "Tom";
    EXPECT_EQ(candidates[winIndex]->getName(), expectWinCanid);
};

TEST_F(SpecialCaseTests, popTie) {
    Canid1.setNumBallots(20);

    int winIndex = p.run();

    //PopularityCase returns 100 + (highestBallot) if there's a tie
    EXPECT_EQ(winIndex, 120);

};