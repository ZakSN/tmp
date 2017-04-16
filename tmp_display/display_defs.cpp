#include "buffer.h"
#include <iostream>

display::display(){
	buff=0;
}

display::display(buffer* toDisp){
	init(toDisp);
}

display::~display(){
	buff=-1;
}

display::init(buffer* toDisp){
	buff=toDisp;
}

display::refresh(){
	/*
	*dummy display function.
	*exists to test my makefile and project structure
	*eventually this will be handled with ncurses... after I figure that out
	*/	
	for(int c=0; c<fbuf.getLen(); c++){
		if(c==fbuf.getCur()){
			cout<<"_";
			if(fbuf.getCh(c)=='\n'){
				cout<<endl;		
			}
		}
		else{
			cout<<fbuf.getCh(c);
		}
	}
}
