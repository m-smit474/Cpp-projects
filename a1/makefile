# Name: Matthew Smith
# MRU E-mail: msmit474@mtroyal.ca
# Course:     COMP 1633-001
# Assignment: 1
# Due Date:   Monday, January 28, 2019 at 11;59 p.m.
# Instructor: Paul Pospisil

# Source File: makefile


TESTS=test_printDate
MODULES=test_printDate.o printDate.o printDate.h

CPPFLAGS= -ansi -pedantic-errors -Wall -Wconversion
GTFLAGS= -lgtest -lgtest_main

$(TESTS): $(MODULES)
	g++ $(GTFLAGS) $(MODULES) -o $(TESTS)
	$(TESTS)

clean:	
	/bin/rm [^p]*.o $(TESTS) *.*~

all:	clean $(TESTS)

test_printDate.o: test_printDate.cpp printDate.h
		g++ $(CPPFLAGS) -c test_printDate.cpp
