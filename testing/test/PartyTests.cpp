#include <gtest/gtest.h>
#include "../../src/include/Party.h"
#include "../../src/include/Candidate.h"

class PartyTests : public ::testing::Test {
    protected:
        Party testParty;
	vector<Candidate> candidates;
	Candidate candidate1 = Candidate("Foster", "Democratic");
	Candidate candidate2 = Candidate("Volz", "Democratic");
        void SetUp() override {
	    candidates.push_back(candidate1);
            testParty = Party(candidates, 0, "Democratic");
        }

        //void TearDown() override {}
};

TEST_F(PartyTests, setNameTest) {
    testParty.setName("Republican");
    EXPECT_EQ("Republican", testParty.getName());
};

TEST_F(PartyTests, getNameTest) {
    EXPECT_EQ("Democratic", testParty.getName());
};

TEST_F(PartyTests, getCandidateTest) {
    Candidate testCanditate = testParty.getCandidate()[0];
    EXPECT_EQ("Foster", testCanditate.getName());
};

TEST_F(PartyTests, setCandidateTest) {
    testParty.setCandidate(candidate2);
    Candidate testCanditate = testParty.getCandidate()[1];
    EXPECT_EQ("Volz", testCanditate.getName());
};

TEST_F(PartyTests, getMaxSeatTest) {
    EXPECT_EQ(0, testParty.getMaxSeat());
};

TEST_F(PartyTests, setMaxSeatTest) {
    testParty.setMaxSeat(2);
    EXPECT_EQ(2, testParty.getMaxSeat());
};

