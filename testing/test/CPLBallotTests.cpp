#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>
#include <typeinfo>
#include <iostream>
#include "../../src/include/CPLProcessing.h"
#include "../../src/include/CPLVoteBallot.h"
#include "../../src/include/Party.h"
//#include "../../src/include/Ballot.h"

class CPLBallotTests : public ::testing::Test {
    protected:
	string testfile = "data/CPL.csv";
	const char * path = testfile.c_str();
        FILE *file = fopen (path, "r");
	CPLProcessing* test_cplprocessing;
	CPLVoteBallot* test_cplBallot;
	AuditFile audit = AuditFile("audit.txt");
	
	void SetUp() override {
	    char buffer[100];
	    fgets(buffer, 100, file);
	    test_cplprocessing = new CPLProcessing(file);
	    audit.labelFile("CPLAudit");
            audit.open();
            test_cplprocessing->setAudit(&audit);
	    test_cplprocessing->setUp();
            test_cplBallot = test_cplprocessing->output();
	}
	void TearDown() override {
	    audit.close();
	}
};

TEST_F(CPLBallotTests, getPartiesTest) {
    std::vector<Party*> test_cplParties = test_cplBallot->getParties();
    EXPECT_EQ("Democratic",test_cplParties[0]->getName());
    EXPECT_EQ("New Wave",test_cplParties[2]->getName());
}

TEST_F(CPLBallotTests, getMapAllocatedSeatTest) {
    std::vector<int> mapAllocatedSeat = test_cplBallot->getMapAllocatedSeat();
    EXPECT_EQ(0,mapAllocatedSeat[0]);
    EXPECT_EQ(0,mapAllocatedSeat[2]);
}

TEST_F(CPLBallotTests, setMapAllocatedSeatTest) {
    std::vector<int> mapAllocatedSeat = test_cplBallot->getMapAllocatedSeat();
    mapAllocatedSeat[0] = 1;
    test_cplBallot->setMapAllocatedSeat(mapAllocatedSeat);
    mapAllocatedSeat = test_cplBallot->getMapAllocatedSeat();
    EXPECT_EQ(1,mapAllocatedSeat[0]);
}

TEST_F(CPLBallotTests, getMapRemainSeatTest) {
    std::vector<int> mapRemainSeat = test_cplBallot->getMapRemainSeat();
    EXPECT_EQ(3,mapRemainSeat[0]);
    EXPECT_EQ(2,mapRemainSeat[2]);
}

TEST_F(CPLBallotTests, setMapRemainSeatTest) {
    std::vector<int> mapRemainSeat = test_cplBallot->getMapRemainSeat();
    mapRemainSeat[0] = 1;
    test_cplBallot->setMapRemainSeat(mapRemainSeat);
    mapRemainSeat = test_cplBallot->getMapRemainSeat();
    EXPECT_EQ(1,mapRemainSeat[0]);
}

TEST_F(CPLBallotTests, getSeatsTest) {
    int seat = test_cplBallot->getSeats();
    EXPECT_EQ(3,seat);
}

TEST_F(CPLBallotTests, setSeatsTest) {
    test_cplBallot->setSeats(10);
    int seat = test_cplBallot->getSeats();
    EXPECT_EQ(10,seat);
}

TEST_F(CPLBallotTests, getMapBallotTest) {
    std::vector<int> mapBallot = test_cplBallot->getMapBallot();
    EXPECT_EQ(3,mapBallot[0]);
    EXPECT_EQ(0,mapBallot[2]);
}

TEST_F(CPLBallotTests, getNumPartiesTest) {
    int numParties = test_cplBallot->getNumParties();
    EXPECT_EQ(6,numParties);
}

TEST_F(CPLBallotTests, getQuotaTest) {
    int quota = test_cplBallot->getQuota();
    EXPECT_EQ(3,quota);
}
