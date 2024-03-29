TARGET=Grid
TESTS=test_Grid test_Shape test_Shape_Collection
MODULES=Grid.o
GRIDTESTMODULES=test_Grid.o Grid.o 
SHAPETESTMODULES=test_Shape.o Shape.o Grid.o
SHAPECOLLECTIONTESTMODULES=test_Shape_Collection.o Shape_Collection.o Shape.o Grid.o
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GCOV_COMP=-fprofile-arcs -ftest-coverage
GCOV_LINK=-lgcov --coverage
GTFLAGS=-lgtest -lpthread -lgtest_main


$(TARGET): clean $(MODULES)
	g++ $(CPPFLAGS) $(MODULES) -g -o $(TARGET)

test_Grid: clean coveredGrid test_Grid.o
	g++ $(GCOV_LINK) $(GTFLAGS) $(GRIDTESTMODULES) -g -o test_Grid
	test_Grid
	gcov Grid.cpp 2> /dev/null | grep -A 1 Grid.cpp

test_Shape: clean coveredShape test_Shape.o Grid.o
	g++ $(GCOV_LINK) $(GTFLAGS) $(SHAPETESTMODULES) -g -o test_Shape
	test_Shape
	gcov Shape.cpp 2> /dev/null | grep -A 1 Shape.cpp

test_Shape_Collection: clean coveredShape_Collection test_Shape_Collection.o Shape.o Grid.o
	g++ $(GCOV_LINK) $(GTFLAGS) $(SHAPECOLLECTIONTESTMODULES) -g -o test_Shape_Collection
	test_Shape_Collection
	gcov Shape_Collection.cpp 2> /dev/null | grep -A 1 Shape_Collection.cpp

clean:
	/bin/rm -f *.o *.*~ *.g* $(TESTS) $(TARGET)

test_Grid.o: test_Grid.cpp Grid.h
	g++ $(CPPFLAGS) $(GTFLAGS) -g -c test_Grid.cpp

Grid.o: Grid.cpp Grid.h globals.h
	g++ $(CPPFLAGS) -g -c Grid.cpp

coveredGrid: Grid.cpp Grid.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOV_COMP) -g -c $(TARGET).cpp

test_Shape.o: test_Shape.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) -g -c test_Shape.cpp

Shape.o: Shape.cpp
	g++ $(CPPFLAGS) -c Shape.cpp

coveredShape: Shape.cpp Shape.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOV_COMP) -g -c Shape.cpp

test_Shape_Collection.o: test_Shape_Collection.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) -g -c test_Shape_Collection.cpp

Shape_Collection.o: Shape_Collection.cpp Shape.h
	g++ $(CPPFLAGS) -g -c Shape_Collection.cpp

coveredShape_Collection: Shape_Collection.cpp Shape_Collection.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOV_COMP) -g -c Shape_Collection.cpp
