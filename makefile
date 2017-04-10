OBJECTS = testMain.o buffer_defs.o
CPPFLAGS = -Wall
UNITNAME = bufferTest

all: $(OBJECTS)
	g++ $(CPPFLAGS) $(OBJECTS) -o $(UNITNAME) 

.Phony: clean
clean:
	rm $(OBJECTS)
	rm $(UNITNAME)
