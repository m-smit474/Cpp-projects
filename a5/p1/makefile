TARGET=Grid
TESTS=test_Grid
MODULES=Grid.o
TESTMODULES=test_Grid.o Grid.o
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GCOV_COMP=-fprofile-arcs -ftest-coverage
GCOV_LINK=-lgcov --coverage
GTFLAGS=-lgtest -lpthread -lgtest_main


$(TARGET): clean $(MODULES)
	g++ $(CPPFLAGS) $(MODULES) -g -o $(TARGET)

$(TESTS): clean coveredGrid test_Grid.o
	g++ $(GCOV_LINK) $(GTFLAGS) $(TESTMODULES) -g -o $(TESTS)
	$(TESTS)
	gcov $(TARGET).cpp 2> /dev/null | grep -A 1 $(TARGET).cpp

clean:
	/bin/rm -f *.o *.*~ *.g* $(TESTS) $(TARGET)

$(TESTS).o: $(TESTS).cpp
	g++ $(CPPFLAGS) $(GTFLAGS) -g -c $(TESTS).cpp

Grid.o: $(TARGET).cpp
	g++ $(CPPFLAGS) -g -c $(TARGET).cpp

coveredGrid: $(TARGET).cpp Grid.h
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOV_COMP) -g -c $(TARGET).cpp
