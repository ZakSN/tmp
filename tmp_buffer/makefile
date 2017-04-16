OBJECTS=buffer_defs.o
SRC=buffer_defs.cpp
CPPFLAGS=-Wall
UNITNAME=bufferTest

.PHONY: all test clean

all: $(OBJECTS)
test: $(OBJECTS) testMain.o
	g++ $(CPPFLAGS) $(OBJECTS) testMain.o -o $(UNITNAME)
clean:
	rm *.o
	rm $(UNITNAME)
