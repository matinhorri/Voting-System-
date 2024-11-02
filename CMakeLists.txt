cmake_minimum_required(VERSION 3.14)
project(Project1)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

set(This Project1)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

set(Headers
    src/include/IRCandidate.h
    src/include/Ballot.h
    src/include/AuditFile.h
    src/include/Display.h
    src/include/Candidate.h
    src/include/ISpecialCase.h
    src/include/TieBreaker.h
    src/include/PopularityCase.h
    src/include/IRProcessing.h
    src/include/IRBallot.h
    src/include/IRVoteSystem.h
    src/include/CPLProcessing.h
    src/include/CPLVoteSystem.h
    src/include/CPLVoteBallot.h
    src/include/Party.h
)

set(Sources
    src/IRCandidate.cpp
    src/Ballot.cpp
    src/AuditFile.cpp
    src/Display.cpp
    src/Candidate.cpp
    src/TieBreaker.cpp
    src/PopularityCase.cpp
    src/IRProcessing.cpp
    src/IRBallot.cpp
    src/IRVoteSystem.cpp
    src/CPLProcessing.cpp
    src/CPLVoteSystem.cpp
    src/CPLVoteBallot.cpp
    src/Party.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
include(GoogleTest)
add_subdirectory(testing/test)
file(COPY testing/data DESTINATION testing/test)