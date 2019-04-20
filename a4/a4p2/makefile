#  Name: Matthew Smith
#  MRU E-mail:  msmit474@mtroyal.ca
#  Course:      COMP 1633-001
#  Assignment:  4 Part 2
#  Due Date:    Wednesday, March 20, 2019 at 11:59 p.m.
#  Instructor:  Paul Pospisil
#
#  Source File: makefile

INDEX=indexList
TESTING=test_indexList
SOURCE=test_indexList
MODULES=indexList.o ignoreList.o a4p2.o ioutil.o
TESTMODULES=test_indexList.o indexList.o 
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GCOV_COMP=-fprofile-arcs -ftest-coverage
GCOV_LINK=-lgcov --coverage
GTFLAGS=-lgtest -lpthread -lgtest_main

$(INDEX): clean $(MODULES)
	g++ $(CPPFLAGS) $(MODULES) -o $(INDEX)           

$(TESTING): clean coverIndexList test_indexList.o
	g++ $(GCOV_LINK) $(GTFLAGS) $(TESTMODULES) -o $(TESTING)
	$(TESTING)
	gcov $(INDEX).cpp 2> /dev/null | grep -A 1 $(INDEX).cpp

clean:
	/bin/rm -f *.o *.*~ *.g* $(TESTING) $(INDEX)

all:	clean $(INDEX) $(TESTING)

$(TESTING).o: $(TESTING).cpp
	g++ $(CPPFLAGS) $(GTFLAGS)  -c $(TESTING).cpp

coverIndexList: $(INDEX).cpp indexList.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOV_COMP) -c $(INDEX).cpp

indexList.o: $(INDEX).cpp
	g++ $(CPPFLAGS) -c $(INDEX).cpp

a4p2.o: a4p2.cpp
	g++ $(CPPFLAGS) -c a4p2.cpp

ignoreList.o: ignoreList.cpp
	g++ $(CPPFLAGS) -c ignoreList.cpp

ioutil.o: ioutil.cpp
	g++ $(CPPFLAGS) -c ioutil.cpp
