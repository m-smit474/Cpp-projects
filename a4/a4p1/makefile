TARGET=a4p1
MODULES=a4p1.o indexList.o ignoreList.o ioutil.o

CPPFLAGS= -ansi -pedantic-errors -Wall -Wconversion


$(TARGET): $(MODULES)
	g++ $(MODULES) -o $(TARGET)


clean:
	/bin/rm -f a4p1.o $(TARGET) *.*~

all:    clean $(TARGET)
