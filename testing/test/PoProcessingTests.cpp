#include <gtest/gtest.h>
#include <stdio.h>
#include <string.h>
#include <typeinfo>
#include <iostream>

#include "../../src/include/PoProcessing.h"
#include "../../src/include/PoBallot.h"
#include "../../src/include/Ballot.h"
#include "../../src/include/Candidate.h"

class PoProcessingTests : public ::testing::Test {
    protected:
        string testfile = "data/PO.csv";
        const char * path = testfile.c_str();
        FILE *file = fopen (path, "r");
        PoProcessing* po_test;
        PoBallot* po_ballot;
	
	void SetUp() override {
        char buffer[100];
	    fgets(buffer, 100, file);
        
	    po_test = new PoProcessing(file);
	}

    void TearDown() override {
        //fclose(file);
    }

};

TEST_F(PoProcessingTests, runSetup) {
    
    if(!(po_test->readHeader(0))) {
        FAIL();
    }

    SUCCEED();
};


TEST_F(PoProcessingTests, readFunction) {

//    if(!(po_test->setUp())) {
//        FAIL();
//    }

    
    if(!(po_test->readHeader(0))) {
       FAIL();
    }

    if(!(po_test->read())) {
       FAIL();
    }

   SUCCEED();
};

TEST_F(PoProcessingTests, readCorrectly) {
    if(!(po_test->readHeader(0))) {
       FAIL();
    }

    if(!(po_test->read())) {
       FAIL();
    }

    int expectedBLines = 6;
    int expectedNumCanid = 4;

    Candidate E1 = Candidate("[Rosen, D]");
    E1.setNumBallots(3);

    Candidate E2 = Candidate("[Kleinberg, R]");

    Candidate E3 = Candidate("[Chou, I]");
    E3.setNumBallots(2);

    Candidate E4 = Candidate("[Royce, L]");
    E4.setNumBallots(1);

    vector<Candidate*> expectedCanid = {&E1, &E2, &E3, &E4};

    EXPECT_EQ(expectedBLines, po_test->getBLinesToRead());
    EXPECT_EQ(expectedNumCanid, po_test->getNumCandidates());

    for(int i = 0; i < (int)expectedCanid.size(); i++) {
        Candidate* expectCanid = expectedCanid[i];
        Candidate* systemCanid = po_test->getCandidates()[i];

        //Check for name
        ASSERT_EQ(expectCanid->getName(), systemCanid->getName());

        //Check for # of ballots
        ASSERT_EQ(expectCanid->getNumBallots(), systemCanid->getNumBallots());

    };
};

TEST_F(PoProcessingTests, outputBallot) {
    PoBallot* ballot = po_test->output();
    PoBallot* POBALLOT;
    EXPECT_TRUE(typeid(*ballot) == typeid(*POBALLOT));
};

TEST_F(PoProcessingTests, calculate) {
    if(!(po_test->readHeader(0))) {
       FAIL();
    }

    if(!(po_test->read())) {
       FAIL();
    }

    int expectedBLines = 6;
    int expectedNumCanid = 4;

    Candidate E1 = Candidate("[Rosen, D]");
    E1.setNumBallots(3);

    Candidate E2 = Candidate("[Kleinberg, R]");

    Candidate E3 = Candidate("[Chou, I]");
    E3.setNumBallots(2);

    Candidate E4 = Candidate("[Royce, L]");
    E4.setNumBallots(1);

    vector<Candidate*> expectedCanid = {&E1, &E2, &E3, &E4};

    std::vector<double> percentageMapping;

    for(int i = 0; i < (int)expectedCanid.size(); i++) {
        double percentage = (expectedCanid[i]->getNumBallots()/1.0)/expectedBLines;
        percentageMapping.push_back(percentage);
    }

    std::vector<double> systemPercentage = po_test->getMapPercentage();
    for(int i = 0; i < (int)percentageMapping.size(); i++) {
        ASSERT_EQ(percentageMapping[i], systemPercentage[i]);
    };  
};

TEST_F(PoProcessingTests, simpleGetSetNumCandidates) {
    po_test->setNumCandidates(5);
    EXPECT_EQ(5, po_test->getNumCandidates());
};

TEST_F(PoProcessingTests, getSetCandidate) {
    Candidate* c1 = new Candidate("[Sally, D]");
    Candidate* c2 = new Candidate("[Jane, R]");
    std::vector<Candidate*> candidates{c1, c2};

    po_test->setCandidates(candidates);
    EXPECT_EQ(po_test->getCandidates(), candidates);
};

TEST_F(PoProcessingTests, getSetMapPercentage) {
    std::vector<double> percentages{0.25, 0.75, 0.4, 0.3};
    po_test->setMapPercentage(percentages);
    EXPECT_EQ(po_test->getMapPercentage(), percentages);
};

//New tests... need to be documented!

// TEST_F(PoProcessingTests, setGetFiles) {
//     vector<string> test_files = {"data/PO.csv", "data/PO2.csv"};
//     po_test->setFiles(test_files);

//     EXPECT_EQ(po_test->getFiles(), test_files);
// };

// TEST_F(PoProcessingTests, singularFile) {
//     vector<string> test_files = {"data/PO.csv"};
//     po_test->setFiles(test_files);

//     if(!(po_test->setUp())) {
//        FAIL();
//     };
// };

// TEST_F(PoProcessingTests, multipleFiles) {
//     vector<string> test_files = {"data/PO.csv", "data/PO2.csv"};
//     po_test->setFiles(test_files);

//     if(!(po_test->setUp())) {
//        FAIL();
//     };
// };

// TEST_F(PoProcessingTests, invalidFilesInMultiple) {
//     vector<string> test_files = {"data/PO.csv", "PO2.csv"};
//     po_test->setFiles(test_files);

//     if(!(po_test->setUp())) {
//        FAIL();
//     };
// };