#include <gtest/gtest.h>
#include "../../src/include/Display.h"

TEST(DisplayTest, Overwrite) {
    Display display("test output");
    display.overWrite("new output");
    EXPECT_EQ("new output", display.print());
};

TEST(DisplayTest, EmptyOutput) {
    Display display("");
    EXPECT_EQ("", display.print());
};

TEST(DisplayTest, RandomOutput) {
    Display display("");
    srand(time(nullptr));
    std::string random_output;
    const int kOutputLength = 10;
    for (int i = 0; i < kOutputLength; i++) {
        char random_char = 'a' + rand() % 26;
        random_output += random_char;
    }
    display.overWrite(random_output);
    EXPECT_EQ(random_output, display.print());
};

TEST(DisplayTest, MultipleOverwrites) {
    Display display("initial output");
    display.overWrite("first overwrite");
    display.overWrite("second overwrite");
    EXPECT_EQ("second overwrite", display.print());
};

TEST(DisplayTest, OutputLength) {
    Display display("test output");
    EXPECT_EQ(11, display.print().length());
};

TEST(DisplayTest, OutputEquality) {
    Display display1("test output");
    Display display2("test output");
    EXPECT_EQ(display1.print(), display2.print());
};

TEST(DisplayTest, LongOutput) {
    Display display("");
    std::string long_output = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec eget velit eu purus molestie sodales vel at risus. Maecenas laoreet vel augue id ultricies. Sed finibus odio id urna lacinia, ut dapibus urna interdum. Phasellus tincidunt diam quis diam tristique, vel aliquet tellus malesuada. Vestibulum ac pretium metus. Etiam mattis elit quis porttitor varius. Nulla aliquam leo non felis pretium, sit amet rhoncus mauris auctor. Nunc imperdiet orci ac augue auctor tristique. Aliquam et dui sapien.";
    display.overWrite(long_output);
    EXPECT_EQ(long_output, display.print());
};

TEST(DisplayTest, LargeOutput) {
    Display display("");
    std::string large_output;
    for (int i = 0; i < 10000; i++) {
        large_output += 'a';
    }
    display.overWrite(large_output);
    EXPECT_EQ(large_output, display.print());
};

TEST(DisplayTest, EmptyOverwrite) {
    Display display("test output");
    display.overWrite("");
    EXPECT_EQ("", display.print());
};

TEST(DisplayTest, CopyConstructor) {
    Display display1("test output");
    Display display2 = display1;
    EXPECT_EQ(display1.print(), display2.print());
};