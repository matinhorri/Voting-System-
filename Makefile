CC = g++
CFLAGS = -Wall -g
OBJDIR = objects

OBJECTS := Party.cpp main.cpp IRVoteSystem.cpp IRProcessing.cpp IRCandidate.cpp IRBallot.cpp CPLVoteSystem.cpp CPLVoteBallot.cpp CPLProcessing.cpp Candidate.cpp Ballot.cpp Display.cpp AuditFile.cpp TieBreaker.cpp PopularityCase.cpp PoBallot.cpp PoProcessing.cpp PoVoteSystem.cpp


main: $(OBJDIR)/main.o
	$(CC) $(CFLAGS) -o main $(OBJDIR)/main.o

$(OBJDIR)/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp
	mv main.o $@

mainIR: src/main.cpp
	$(CC) $(CFLAGS) -o main src/main.cpp src/IRProcessing.cpp src/IRBallot.cpp src/IRCandidate.cpp src/Candidate.cpp src/Ballot.cpp src/IRVoteSystem.cpp

mainCPL: src/mainCPL.cpp src/CPLProcessing.cpp src/Party.cpp src/Candidate.cpp src/CPLVoteBallot.cpp src/CPLVoteSystem.cpp
	$(CC) $(CFLAGS) -o mainCPL src/mainCPL.cpp src/CPLProcessing.cpp src/Party.cpp src/Candidate.cpp src/CPLVoteBallot.cpp src/CPLVoteSystem.cpp 

mainAll:
	cd src && \
	$(CC) $(CFLAGS) -o main $(OBJECTS) && \
	mv "main" "../"
