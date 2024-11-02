#include <gtest/gtest.h>
#include "../../src/include/Candidate.h"

class CandidateTests : public ::testing::Test {
    protected:
        Candidate canTest = Candidate();

        void SetUp() override {
        }

        //void TearDown() override {}
};

TEST_F(CandidateTests, setGetFunction) {
    canTest.setName("Mike");
    EXPECT_EQ("Mike", canTest.getName());

    canTest.setParty("Demo");
    EXPECT_EQ("Demo", canTest.getParty());
};

TEST_F(CandidateTests, constructer) {
    Candidate canid = Candidate("Dolly", "Repo");
    EXPECT_EQ("Dolly", canid.getName());

    EXPECT_EQ("Repo", canid.getParty());
};