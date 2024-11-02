#include "../../src/include/AuditFile.h"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>

TEST(AuditFileTest, ProduceFileTest) {
  AuditFile auditFile("test");
  auditFile.open();
  auditFile.produceFile();
  std::string line;
  auditFile.labelFile("Test_File");
  auditFile.write("line 1");
  std::ifstream file("Test_File.txt");
  line = "line 1";
  std::getline(file, line);
  EXPECT_EQ(line, "line 1");
  auditFile.close();
};

TEST(AuditFileTest, WriteTest_one) {
  AuditFile auditFile("test");
  auditFile.open();
  auditFile.write("line 1");
  auditFile.write("line 2");
  std::ifstream file("test");
  std::string line = "line 1";
  std::getline(file, line);
  EXPECT_EQ(line, "line 1");
  line = "line 2";
  std::getline(file, line);
  EXPECT_EQ(line, "line 2");
  auditFile.close();
};

TEST(AuditFileTest, DefaultConstructor) {
  AuditFile audit;
  EXPECT_EQ(audit.getName(), "audit");
}

// Test the constructor that takes a string argument
TEST(AuditFileTest, ConstructorWithArgs) {
  AuditFile audit("test");
  EXPECT_EQ(audit.getName(), "test");
}

// Test the labelFile function
TEST(AuditFileTest, LabelFile) {
  AuditFile audit("test");
  audit.labelFile("new_test");
  EXPECT_EQ(audit.getName(), "new_test");
}

// Test the open function
TEST(AuditFileTest, Open) {
  AuditFile audit("test");
  audit.open();
  EXPECT_TRUE(audit.getFileStream().is_open());
  audit.close();
}

// Test the close function
TEST(AuditFileTest, Close) {
  AuditFile audit("test");
  audit.open();
  audit.close();
  EXPECT_FALSE(audit.getFileStream().is_open());
}

// Test the produceFile function
TEST(AuditFileTest, ProduceFile) {
  AuditFile audit("test");
  audit.open();
  audit.write("Hello, world!", true);
  audit.produceFile();
  audit.close();
  // Test that the file was created and contains the correct text
  std::ifstream file("test.txt");
  std::string contents((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
  EXPECT_EQ(contents, "Hello, world!\n\n");
  file.close();
}

// Test the write function
TEST(AuditFileTest, Write) {
  AuditFile audit("test");
  audit.open();
  audit.write("Hello, world!", true);
  audit.close();
  // Test that the file was created and contains the correct text
  std::ifstream file("test.txt");
  std::string contents((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
  EXPECT_EQ(contents, "Hello, world!\n");
  file.close();
}

TEST(AuditFileTest, SetAndGetFile) {
  AuditFile file;
  FILE* f = fopen("test.txt", "w+");
  file.setFile(f);
  EXPECT_EQ(f, file.getFile());
  fclose(f);
}

TEST(AuditFileTest, SetAndGetOutputResult) {
  AuditFile file;
  string output = "test output";
  file.setOutputResult(output);
  EXPECT_EQ(output, file.getOutputResult());
}

TEST(AuditFileTest, SetAndGetFileName) {
  AuditFile file;
  string name = "test";
  string filename = "test.txt";
  file.setName(name);
  file.setFileName(filename);
  EXPECT_EQ(name, file.getName());
  EXPECT_EQ(filename, file.getFileName());
}

TEST(AuditFileTest, GetFileStream) {
  AuditFile file;
  ofstream& stream = file.getFileStream();
  EXPECT_TRUE(stream.good());
}