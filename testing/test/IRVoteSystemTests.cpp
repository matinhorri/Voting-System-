#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>
#include <typeinfo>
#include <iostream>
#include "../../src/include/IRProcessing.h"
#include "../../src/include/IRBallot.h"
#include "../../src/include/IRVoteSystem.h"

class IRVoteSystemTests : public ::testing::Test {
    protected:
	string testfile = "data/IR.csv";
	const char * path = testfile.c_str();
    FILE *file = fopen (path, "r");
	IRProcessing* ir_test;
	IRBallot* irBallot;
	IRVoteSystem* ir_testVote;
	AuditFile audit = AuditFile("audit.txt");
	
	void SetUp() override {
	    char buffer[100];
	    fgets(buffer, 100, file);
	    ir_test = new IRProcessing(file);	

	    audit.labelFile("IRAudit");
        audit.open();
        ir_test->setAudit(&audit);

	    ir_test->setUp();
        //ir_test->read();
        irBallot = ir_test->output();
	    ir_testVote = new IRVoteSystem(ir_test,irBallot);
	    ir_testVote->setAuditFile(&audit);
	}

	void TearDown() override {
	    audit.close();
	}

};

TEST_F(IRVoteSystemTests, startElectionTest) {
    bool start = ir_testVote->startElection();
    EXPECT_TRUE(start);
};


TEST_F(IRVoteSystemTests, getWinnerTest) {
    bool conduct = ir_testVote->startElection();

    IRCandidate Winner = ir_testVote->getWinner();
    EXPECT_EQ("Rosen (D)", Winner.getName());
};


TEST_F(IRVoteSystemTests, simpleGetSetWinner) {
	IRCandidate winner = IRCandidate("Johnny");
	ir_testVote->setWinner(winner);

	EXPECT_EQ(ir_testVote->getWinner().getName(), "Johnny");
};


TEST_F(IRVoteSystemTests, getSetProcessedBallot) {
	IRCandidate* can1 = new IRCandidate("John");
	IRCandidate* can2 = new IRCandidate("Doe");
	IRCandidate* can3 = new IRCandidate("Sally");

	std::vector<IRCandidate*> candidates = {can1, can2, can3};
	std::vector<int> sample_map = {1,2,3};
	std::vector<double> sample_map_percntage = {0.17, 0.33, 0.5};

	IRBallot* test = new IRBallot(candidates, sample_map, sample_map_percntage);

	ir_testVote->setProcessedBallot(test);

	EXPECT_EQ(ir_testVote->getProcessedBallot(), test);

};

TEST_F(IRVoteSystemTests, getSetCandidate) {
  IRCandidate* c1 = new IRCandidate("Sally");
  IRCandidate* c2 = new IRCandidate("Jane");
  std::vector<IRCandidate*> candidates{c1, c2};

  ir_testVote->setCandidates(candidates);
  EXPECT_EQ(ir_test->getCandidates(), candidates);
};