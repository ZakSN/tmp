OBJECTS=testMain.o buffer_defs.o
CPPFLAGS=-Wall
UNITNAME=bufferTest

.PHONY: all clean

all: $(OBJECTS)
	g++ $(CPPFLAGS) $(OBJECTS) -o $(UNITNAME) 

clean:
	rm $(OBJECTS)
	rm $(UNITNAME)
