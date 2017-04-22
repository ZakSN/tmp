#include "buffer.h"
#include "display.h"
#include <iostream>

namespace ncurses{
	#include <ncurses.h>
}
using namespace ncurses;

display::display(){
	buff=NULL;
}

display::display(buffer* toDisp){
	init(toDisp);
}

display::~display(){
	endwin(); //exit curses mode
	//having each display object start/stop its own window may present a
	//problem in the futur if I implement multi-buffering...
	buff=NULL;
}

void display::init(buffer* toDisp){
	initscr(); //initialize ncurses screen
	curs_set(0);
	buff=toDisp;
}

void display::refresh(){
	/*
	*dummy display function.
	*exists to test my makefile and project structure
	*eventually this will be handled with ncurses... after I figure that out
	*/
	erase();
	for(int c=0; c<buff->getLen(); c++){
		if(c==buff->getCur()){
			attron(A_REVERSE);
			if(buff->getCh(c)=='\n'){
				addch(' ');
			}
			addch(buff->getCh(c));
			attroff(A_REVERSE);
		}
		else{
			addch(buff->getCh(c));
		}
	}
	ncurses::refresh();
}
