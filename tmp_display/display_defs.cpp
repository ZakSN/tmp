#include "buffer.h"
#include "display.h"
#include <iostream>

display::display(){
	buff=NULL;
}

display::display(buffer* toDisp){
	init(toDisp);
}

display::~display(){
	buff=NULL;
}

void display::init(buffer* toDisp){
	buff=toDisp;
}

void display::refresh(){
	/*
	*dummy display function.
	*exists to test my makefile and project structure
	*eventually this will be handled with ncurses... after I figure that out
	*/	
	for(int c=0; c<buff->getLen(); c++){
		if(c==buff->getCur()){
			std::cout<<"_";
			if(buff->getCh(c)=='\n'){
				std::cout<<std::endl;		
			}
		}
		else{
			std::cout<<buff->getCh(c);
		}
	}
}
