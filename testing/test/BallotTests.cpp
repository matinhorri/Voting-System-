#include <gtest/gtest.h>
#include "../../src/include/Ballot.h"

class BallotTests : public ::testing::Test {
    protected:
        Ballot test_ballot;

        void SetUp() override {
            std::vector<int> sample_map = {1,2,3,4};
            test_ballot = Ballot(1, sample_map);
        }

        //void TearDown() override {}
};

TEST_F(BallotTests, Constructor) {
    std::vector<int> comparedTo = {1,2,3,4};
    EXPECT_EQ(1, test_ballot.getRank());
    EXPECT_EQ(comparedTo, test_ballot.getMapping());
};

TEST_F(BallotTests, setInvalidRanking) {
    test_ballot.setRank(-1);
    EXPECT_EQ(1, test_ballot.getRank());

    test_ballot.setRank(0);
    EXPECT_EQ(1, test_ballot.getRank());

    test_ballot.setRank(5);
    EXPECT_EQ(4, test_ballot.getRank());

};

TEST_F(BallotTests, setValidRanking) {
    test_ballot.setRank(1);
    EXPECT_EQ(1, test_ballot.getRank());

    test_ballot.setRank(3);
    EXPECT_EQ(3, test_ballot.getRank());

    test_ballot.setRank(4);
    EXPECT_EQ(4, test_ballot.getRank());
};

TEST_F(BallotTests, increaseRank) {
    test_ballot.setRank(3);
    test_ballot.increaseRank();

    EXPECT_EQ(4, test_ballot.getRank());
};

TEST_F(BallotTests, getAndSetIndex) {
    test_ballot.setRank(3);
    EXPECT_EQ(3, test_ballot.getRank());

    int index = test_ballot.getIndex();
    EXPECT_EQ(2, index);

};

TEST(BallotTest, ConstructorWithParameters) {
    vector<int> mapping{1, 2, 3};
    Ballot ballot(1, mapping);
    EXPECT_EQ(ballot.getRank(), 1);
    EXPECT_EQ(ballot.getMapping(), mapping);
};

TEST(BallotTest, GetRank) {
    vector<int> mapping{1, 2, 3};
    Ballot ballot(1, mapping);
    EXPECT_EQ(ballot.getRank(), 1);
};

TEST_F(BallotTests, setGetMapping) {
  std::vector<int> mapping1 = {1, 2, 3};
  std::vector<int> mapping2 = {4, 5, 6};
  Ballot ballot = Ballot(1, mapping1);
  ballot.setMapping(mapping2);

  EXPECT_EQ(ballot.getMapping(), mapping2);
};