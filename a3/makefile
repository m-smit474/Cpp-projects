TARGET=a3main
MODULES=a3main.o
CPPFLAGS=$(shell Magick++-config --cppflags) -g -ansi -Wall -Wconversion
LDFLAGS=$(shell Magick++-config --ldflags) -g

$(TARGET): $(MODULES)

$(MODULES): a3main.cpp
	g++ $(CPPFLAGS) -c a3main.cpp

clean:
	rm -f $(TARGET) $(MODULES) *.gif *.*~

all: clean $(TARGET)













