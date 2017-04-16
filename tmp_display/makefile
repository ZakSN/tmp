OBJECTS=display.o display_defs.o testMain.o
EXTOBJECTS=buffer.o buffer_defs.o
EXTSRC=buffer.h buffer_defs.cpp
CPPFLAGS=-Wall
UNITNAME=displayTest
INCLUDEPATH=../tmp_buffer

.PHONY: all clean

all: $(OBJECTS) $(EXTOBJECTS)
	g++ $(CPPFLAGS) -I$(INCLUDEPATH) $(EXTOBJECTS) $(OBJECTS) -o $(UNITNAME)

$(EXTOBJECTS):
	#jump to the external directory and make the external .o files
	pushd $(INCLUDEPATH)
	g++ $(CPPFLAGS) -c $(EXTSRC)
	popd

clean:
	#clean this directory
	rm $(OBJECTS)
	rm $(UNITNAME)
	#clean the external directory
	pushd $(INCLUDEPATH)
	rm $(EXTOBJECTS)
	popd
