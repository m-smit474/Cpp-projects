TARGET=a2
TESTMODULES=test_indexList.o indexList.o
TESTS=test_indexList
MODULES=a2main.o indexList.o ignoreList.o ioutil.o 

CPPFLAGS= -ansi -pedantic-errors -Wall -Wconversion
GTFLAGS= -lgtest -lgtest_main


$(TARGET): $(MODULES)
	g++ $(MODULES) -o $(TARGET)
	$(TARGET)

$(TESTS): $(TESTMODULES)
	g++ $(GTFLAGS) $(TESTMODULES) -o $(TESTS)
	$(TESTS) 

clean:
	/bin/rm -f *.o $(TARGET) *.*~

all:	clean $(TARGET)

ioutil.o: ioutil.h ioutil.cpp
	g++ $(CPPFLAGS) -c ioutil.cpp

ignoreList.o: ignoreList.cpp globals.h ignoreList.h
	g++ $(CPPFLAGS) -c ignoreList.cpp

indexList.o: indexList.cpp globals.h indexList.h
	g++ $(CPPFLAGS) -c indexList.cpp

a2main.o: a2main.cpp ioutil.h globals.h indexList.h ignoreList.h
	g++ $(CPPFLAGS) -c a2main.cpp

test_indexList.o: test_indexList.cpp indexList.h
	g++ $(CPPFLAGS) -c test_indexList.cpp
