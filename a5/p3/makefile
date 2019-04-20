#  Name: Matthew Smith
#  MRU E-mail:  msmit474@mtroyal.ca
#  Course:      COMP 1633-001
#  Assignment:  5 part 3
#  Due Date:    Friday, April 5, 2019 at 11:59 p.m.
#  Instructor:  Paul Pospisil
#
#  Source File: main.cpp

TARGET=Paint
TESTG=test_Grid
TESTS=test_Shape
TESTSC=test_Shape_Collection
MODULES=Grid.o Shape.o Square.o Rectangle.o Shape_Collection.o IsoTriangle.o EquTriangle.o ioutil.o main.o
GTESTMODULES=test_Grid.o Grid.o 
STESTMODULES=test_Shape.o Shape.o Grid.o
SCTESTMODULES=test_Shape_Collection.o Shape_Collection.o Shape.o Grid.o
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GCOV_COMP=-fprofile-arcs -ftest-coverage
GCOV_LINK=-lgcov --coverage
GTFLAGS=-lgtest -lpthread -lgtest_main


TESTG: clean coveredGrid test_Grid.o
	g++ $(GCOV_LINK) $(GTFLAGS) $(GTESTMODULES) -g -o $(TESTG)
	$(TESTG)
	gcov Grid.cpp 2> /dev/null | grep -A 1 Grid.cpp

TESTS: clean coveredShape test_Shape.o Grid.o
	g++ $(GCOV_LINK) $(GTFLAGS) $(STESTMODULES) -g -o $(TESTS)
	$(TESTS)
	gcov Shape.cpp 2> /dev/null | grep -A 1 Shape.cpp

TESTSC: clean coveredShape_Collection test_Shape_Collection.o Shape.o Grid.o
	g++ $(GCOV_LINK) $(GTFLAGS) $(SCTESTMODULES) -g -o $(TESTSC)
	$(TESTSC)
	gcov Shape_Collection.cpp 2> /dev/null | grep -A 1 Shape_Collection.cpp

MAIN: clean $(MODULES)
	g++ $(GCOV_COMP) $(CPPFLAGS) $(MODULES) -g -o $(TARGET)
#	$(TARGET)

clean:
	/bin/rm -f *.o *.*~ *.g* $(TESTG) $(TESTS) $(TESTSC) $(TARGET)

all: clean MAIN

main.o: main.cpp
	g++ $(CPPFLAGS) -g -c main.cpp

test_Grid.o: test_Grid.cpp Grid.h
	g++ $(CPPFLAGS) $(GTFLAGS) -c test_Grid.cpp

Grid.o: Grid.cpp Grid.h globals.h
	g++ $(CPPFLAGS) -g -c Grid.cpp

coveredGrid: Grid.cpp Grid.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOV_COMP) -g -c Grid.cpp

test_Shape.o: test_Shape.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) -g -c test_Shape.cpp

Shape.o: Shape.cpp
	g++ $(CPPFLAGS) -g -c Shape.cpp

coveredShape: Shape.cpp Shape.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOV_COMP) -g -c Shape.cpp

test_Shape_Collection.o: test_Shape_Collection.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) -g -c test_Shape_Collection.cpp

Shape_Collection.o: Shape_Collection.cpp Shape.h
	g++ $(CPPFLAGS) -g -c Shape_Collection.cpp

coveredShape_Collection: Shape_Collection.cpp Shape_Collection.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOV_COMP) -g -c Shape_Collection.cpp

Rectangle.o: Rectangle.cpp
	g++ $(CPPFLAGS) -g -c Rectangle.cpp

Square.o: Square.cpp
	g++ $(CPPFLAGS) -g -c Square.cpp

IsoTriangle.o: IsoTriangle.cpp
	g++ $(CPPFLAGS) -g -c IsoTriangle.cpp

EquTriangle.o: EquTriangle.cpp
	g++ $(CPPFLAGS) -g -c EquTriangle.cpp
