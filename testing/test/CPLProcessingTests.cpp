#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>
#include <typeinfo>
#include <iostream>
#include "../../src/include/CPLProcessing.h"
#include "../../src/include/CPLVoteBallot.h"
#include "../../src/include/Party.h"

class CPLProcessingTests : public ::testing::Test {
    protected:
	string testfile = "data/CPL.csv";
	vector<string> input_files;	
	const char * path = testfile.c_str();
    FILE *file = fopen (path, "r");
	CPLProcessing* test_cplprocessing;
    AuditFile audit = AuditFile("audit.txt");

	void SetUp() override {
	    input_files.push_back("data/CPL.csv");
	    char buffer[100];
	    fgets(buffer, 100, file);
	    test_cplprocessing = new CPLProcessing(file, input_files);
	    audit.labelFile("CPLAudit");
        audit.open();
        test_cplprocessing->setAudit(&audit);
	    test_cplprocessing->setUp();
	}
	void TearDown() override {
	    audit.close();
	}
};

TEST_F(CPLProcessingTests, outputBallot) {
    CPLVoteBallot* test_cplBallot = test_cplprocessing->output();
    CPLVoteBallot* cplBallot;
    EXPECT_TRUE(typeid(*test_cplBallot) == typeid(*cplBallot));

}

TEST_F(CPLProcessingTests, inputsConsistency) {
    bool pass = test_cplprocessing->readHeader(1);
    EXPECT_TRUE(pass);
}

