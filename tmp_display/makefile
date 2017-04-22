OBJECTS=display_defs.o
SRC=display_defs.cpp
EXTOBJECTS=buffer_defs.o
CPPFLAGS=-Wall
UNITNAME=displayTest
INCLUDEPATH=../tmp_buffer
HERE=../tmp_display

.PHONY: all test clean

all: $(OBJECTS)
test: $(OBJECTS) $(EXTOBJECTS) testMain.o
	g++ $(CPPFLAGS)  $(OBJECTS) $(EXTOBJECTS) -lncurses testMain.o -o $(UNITNAME)
$(OBJECTS):
	g++ $(CPPFLAGS) -I$(INCLUDEPATH) $(SRC) -c
$(EXTOBJECTS):
	$(MAKE) -C $(INCLUDEPATH)
	mv $(INCLUDEPATH)/$(EXTOBJECTS) $(HERE)
testMain.o:
	g++ $(CPPFLAGS) -I$(INCLUDEPATH) testMain.cpp -c
clean:
	rm *.o
	rm $(UNITNAME)
