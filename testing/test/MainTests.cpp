#include <gtest/gtest.h>
#include "../../src/include/IRVoteSystem.h"
#include "../../src/include/IRProcessing.h"
#include "../../src/include/CPLVoteSystem.h"
#include "../../src/include/CPLProcessing.h"


class MainTests : public ::testing::Test {
    protected:
        string input_file;
        

        void SetUp() override {
            std::vector<string> input_files = {"file1.csv", "file2.csv", "file3.csv", "file4.csv"};
            const char * path = input_file.c_str();
            // file = fopen (path, "r");
        }
};

// TEST_F(MainTests, ReadFileTest) {
//     while(!file.eof) {

//     }
// }

TEST_F(MainTests, MultipleFilesTest) {
    std::vector<string> files_list = {"file1.csv", "file2.csv", "file3.csv", "file4.csv"};
    EXPECT_EQ(files_list[0], "file1.csv");
    EXPECT_EQ(files_list[1], "file2.csv");
    EXPECT_EQ(files_list[2], "file3.csv");
    EXPECT_EQ(files_list[3], "file4.csv");
    EXPECT_EQ(files_list.size(), 4);
};

TEST_F(MainTests, AddFileTest) {
    std::vector<string> files_list = {"file1.csv", "file2.csv", "file3.csv", "file4.csv"};
    input_file = "file5.csv";
    cin >> input_file;
    files_list.push_back(input_file);
    EXPECT_EQ(files_list.size(), 5);
    EXPECT_EQ(files_list[4], input_file);
};

