cmake_minimum_required(VERSION 3.14)

set(This AllTests)

set(Sources
    PartyTests.cpp
    CPLVoteSystemTests.cpp
    CPLBallotTests.cpp
    CPLProcessingTests.cpp
    IRCandidateTests.cpp
    BallotTests.cpp
    AuditFileTest.cpp
    DisplayTest.cpp
    CandidateTests.cpp
    IRProcessingTests.cpp
    SpecialCaseTests.cpp
    IRVoteSystemTests.cpp
    IRBallotTests.cpp
    MainTests.cpp
    PoBallotTests.cpp
    PoProcessingTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Project1
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
