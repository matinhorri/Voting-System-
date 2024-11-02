#include <gtest/gtest.h>
#include "../../src/include/IRCandidate.h"
#include "../../src/include/Ballot.h"
#include "../../src/include/Candidate.h"



class IRCandidateTests : public ::testing::Test {
    protected:
        IRCandidate test_candidate;
        std::vector<int> mapping = {1,2,3};

        Ballot* test_ballot = new Ballot(1, mapping);
        string candidateName = "name";

        Ballot* ballot_1 = new Ballot(1, mapping);
        Ballot* ballot_2 = new Ballot(1, mapping);
        Ballot* ballot_3 = new Ballot(1, mapping);


        std::vector<Ballot*> ballotList = {ballot_1, ballot_2, ballot_3};

        void SetUp() override {
            test_candidate = IRCandidate(candidateName);
        }

        //void TearDown() override {}
};

TEST_F(IRCandidateTests, ConstructorTest) {
        EXPECT_EQ(test_candidate.getName(), candidateName);
};

TEST_F(IRCandidateTests, setNumBallotsTest) {
        test_candidate.setNumBallots(5);
        EXPECT_EQ(test_candidate.getNumBallots(), 5);

        test_candidate.setNumBallots(1);
        EXPECT_EQ(test_candidate.getNumBallots(), 1);

        test_candidate.setNumBallots(3);
        EXPECT_EQ(test_candidate.getNumBallots(), 3);

};

TEST_F(IRCandidateTests, setBallotsListTest) {
        test_candidate.setBallotList(ballotList);
        ASSERT_EQ(test_candidate.getBallotList(), ballotList);
};

TEST_F(IRCandidateTests, addBallotTest) {
        test_candidate.setBallotList(ballotList);

        std::vector<int> ranking = {1,2,3};
        Ballot* newBallot = new Ballot(1, ranking);
        ballotList.push_back(newBallot);

        test_candidate.addBallot(newBallot);

        EXPECT_EQ(test_candidate.getBallotList(), ballotList);

        EXPECT_EQ(test_candidate.getBallotList().back(), newBallot);

        EXPECT_EQ(test_candidate.getNumBallots(), 4);
};


TEST_F(IRCandidateTests, addAndPopBallot) {
        IRCandidate Canid = IRCandidate("Canid");
        vector<int> ranking1 = {1,2};
        vector<int> ranking2 = {2,1};

        Ballot Ballot1 = Ballot(1, ranking1);
        Ballot Ballot2 = Ballot(1, ranking2);

        Canid.addBallot(&Ballot1);
        Canid.addBallot(&Ballot2);

        EXPECT_EQ(Canid.getNumBallots(), 2);

        Ballot *popped = Canid.popBallot();

        EXPECT_EQ(popped->getMapping(), Ballot2.getMapping());
        EXPECT_EQ(Canid.getNumBallots(), 1);
};



