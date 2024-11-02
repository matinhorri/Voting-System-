#include <gtest/gtest.h>
#include "../../src/include/PoBallot.h"
#include "../../src/include/Ballot.h"


class PoBallotTests : public ::testing::Test {
    protected:
        PoBallot po_test_ballot;

        PoCandidate* can_1;
        PoCandidate* can_2;
        PoCandidate* can_3;
        PoCandidate* can_4;

        std::vector<PoCandidate*> PoCandidates;
        std::vector<int> sample_map;
        std::vector<double> sample_map_percentage;
        int numCandidates;

        void SetUp() override {
            PoCandidates = {can_1, can_2, can_3, can_4};
            sample_map = {1, 2, 3, 4};
            sample_map_percentage = {0.25, 0.5, 0.75, 0.1};
            numCandidates = PoCandidates.size();

            po_test_ballot = PoBallot(PoCandidates, sample_map, sample_map_percentage);

        }
};

TEST_F(PoBallotTests, Constructor) {
    std::vector<int> compareMapping = {1, 2, 3, 4};
    std::vector<double> comparePercentages = {0.25, 0.5, 0.75, 0.1};

    ASSERT_EQ(PoCandidates, po_test_ballot.getCandidates());
    EXPECT_EQ(compareMapping, sample_map);
    EXPECT_EQ(comparePercentages, po_test_ballot.getMapPercentage());

};

TEST_F(PoBallotTests, setGetCandidatesTest) {
    po_test_ballot.setCandidates(PoCandidates);
    int sizePOList = PoCandidates.size();
    ASSERT_EQ(po_test_ballot.getCandidates(), PoCandidates);
    ASSERT_EQ(sizePOList, numCandidates);
};

TEST_F(PoBallotTests, setMapPercentageTest) {
    po_test_ballot.setMapPercentage(sample_map_percentage);
    EXPECT_EQ(po_test_ballot.getMapPercentage(), sample_map_percentage);
};

TEST_F(PoBallotTests, setGetNumCandidatesTest) {
    po_test_ballot.setNumCandidates(4);
    EXPECT_EQ(po_test_ballot.getNumCandidates(), 4);

    po_test_ballot.setNumCandidates(2);
    EXPECT_EQ(po_test_ballot.getNumCandidates(), 2);

    po_test_ballot.setNumCandidates(6);
    EXPECT_EQ(po_test_ballot.getNumCandidates(), 6);
};
