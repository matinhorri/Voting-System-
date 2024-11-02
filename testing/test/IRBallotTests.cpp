#include <gtest/gtest.h>
#include "../../src/include/IRBallot.h"
#include "../../src/include/Ballot.h"


class IRBallotTests : public ::testing::Test {
    protected:
        IRBallot ir_test_ballot;

        IRCandidate* can_1;
        IRCandidate* can_2;
        IRCandidate* can_3;
        IRCandidate* can_4;

        std::vector<IRCandidate*> IRCandidates;
        std::vector<int> sample_map;
        std::vector<double> sample_map_percentage;
        int numCandidates;

        void SetUp() override {
            IRCandidates = {can_1, can_2, can_3, can_4};
            sample_map = {1, 2, 3, 4};
            sample_map_percentage = {0.25, 0.5, 0.75, 0.1};
            numCandidates = IRCandidates.size();

            ir_test_ballot = IRBallot(IRCandidates, sample_map, sample_map_percentage);

        }
};

TEST_F(IRBallotTests, Constructor) {
    std::vector<int> compareMapping = {1, 2, 3, 4};
    std::vector<double> comparePercentages = {0.25, 0.5, 0.75, 0.1};

    ASSERT_EQ(IRCandidates, ir_test_ballot.getCandidates());
    EXPECT_EQ(compareMapping, sample_map);
    EXPECT_EQ(comparePercentages, ir_test_ballot.getMapPercentage());

};

TEST_F(IRBallotTests, setGetCandidatesTest) {
    ir_test_ballot.setCandidates(IRCandidates);
    int sizeIRList = IRCandidates.size();
    ASSERT_EQ(ir_test_ballot.getCandidates(), IRCandidates);
    ASSERT_EQ(sizeIRList, numCandidates);
};

TEST_F(IRBallotTests, setMapPercentageTest) {
    ir_test_ballot.setMapPercentage(sample_map_percentage);
    EXPECT_EQ(ir_test_ballot.getMapPercentage(), sample_map_percentage);
};

TEST_F(IRBallotTests, setGetNumCandidatesTest) {
    ir_test_ballot.setNumCandidates(4);
    EXPECT_EQ(ir_test_ballot.getNumCandidates(), 4);

    ir_test_ballot.setNumCandidates(2);
    EXPECT_EQ(ir_test_ballot.getNumCandidates(), 2);

    ir_test_ballot.setNumCandidates(6);
    EXPECT_EQ(ir_test_ballot.getNumCandidates(), 6);
};
