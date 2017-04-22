#include <iostream>
#include <fstream>
#include "buffer.h"
#include "display.h"
#include <ncurses.h>
using namespace std;

int main(){
	//read a file into a buffer:
	fstream file;
	file.open("../tmp_buffer/testFile.txt");
	if(!file.is_open()){
		cerr<<"file not found"<<endl; 
		return -1;
	}
	buffer fbuf;
	while(!file.eof()){
		char hold=file.get();
		if(hold>0){fbuf.addCh(hold);}
	}
	fbuf.rmvCh();
	//create a display
	display disp(&fbuf);
	//display and input loop:
	char action='l';
	while(action!='q'){
		disp.refresh();
		printw("action?");
		action=getch();
		switch(action){
			case 'w':
				fbuf.curUp();
			break;
			case 's':
				fbuf.curDn();
			break;
			case 'a':
				fbuf.curLt();
			break;
			case 'd':
				fbuf.curRt();
			break;
			case 'r':
				fbuf.rmvCh();
			break;
			case 'i':
				fbuf.addCh('@');
			break;
		};
	}		
	file.close();
	return 0;
}
