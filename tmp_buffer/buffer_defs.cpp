#include "buffer.h"

buffer::buffer(){
	buff=new char[1];
	length=1;
	cursor=0;
}

buffer::~buffer(){
	delete[] buff;
	buff=0;
	length=-1;
	cursor=-1;
}

void buffer::curUp(){
	curVrt(true);
}

void buffer::curDn(){
	curVrt(false);
}

void buffer::curLt(){
	curHzl(true);
}

void buffer::curRt(){
	curHzl(false);
}

void buffer::addCh(char toAdd){
	//create an array 1 index longer than the buffer
	char* tmp;
	tmp=new char[length+1];
	//copy over buffer data and stick in the new char
	for(int c=0; c<length+1; c++){
		if(c<cursor){
			tmp[c]=buff[c];
		}
		else if(c==cursor){
			tmp[c]=toAdd;
		}
		else{
			tmp[c]=buff[c-1];
		}
	}
	//swapt the pointer to the temporary array and the old buffer array
	char* hold;
	hold=buff;
	buff=tmp;
	tmp=hold;
	//delete the old buffer
	delete[] tmp;
	length++;
	cursor++;
}

void buffer::rmvCh(){
	if(length<=1){return;} //can't remove a char
	//create an array 1 index shorter than the buffer
	char* tmp;
	tmp = new char[length -1];
	//copy over buffer data ommitting the char that cursor is pointing to
	for(int c=0; c<length-1; c++){
		if(c<cursor){
			tmp[c]=buff[c];
		}
		else if(c>cursor){
			tmp[c]=buff[c+1];
		}
	}
	//swapt the pointer to the temporary array and the old buffer array
	char* hold;
	hold=buff;
	buff=tmp;
	tmp=hold;
	//delete the old buffer
	delete[] tmp;
	length--;
	if(cursor==length){
		cursor--;
	}
}

char buffer::getCh(int addr){
	//returns char at buffer address if available
	//otherwise returns NULL
	if((addr<0)||(addr>=length)){
		return '\0';
	}
	return buff[addr];
}

void buffer::curHzl(bool dir){
	//dir==true moves the cursor left
	//dir==false moves the cursor right
	//attempting to move the cursor off the end of the buffer results in
	//a no-op
	if((cursor==0)&&(dir==true)){
		return;
	}
	if((cursor==length-1)&&(dir==false)){
		return;
	}
	if(dir==true){
		cursor--;
	}
	if(dir==false){
		cursor++;
	}
}

void buffer::curVrt(bool dir){
	//dir==true moves the cursor to the same index in the line above
	//dir==flase moves the cursor to the same index in the line below
	//if the line that the cursor is moved to is shorter than the
	//line it is moved from the cursor is placed at the end of the new line
	//attempting to move the cursor into a line that doesn't exist results in a
	//no-op
	int d;
	if(!dir){d=1;}
	else{d=-1;}
	bool cont=true;
	int pos=cursor;
	int count=1;
	while(cont){
		pos+=d;
		if((pos<0)||(pos>=length)){
			return; //no line to move into
		}
		count++;
		if(buff[pos]=='\n'){
			cont=false;
		}
	}
	cont=true;
	pos+=d;
	while(cont){
		if(pos==0){
			cont=false; //hit the left end of the buffer
		}
		else if(pos==(length-1)){
			cont=false; //hit the right end of the buffer
		}
		else if(buff[pos]=='\n'){
			cont=false; //found a newline
		}
		pos+=d;
	}
	cont=true;
	while(cont){	
		if(pos==0){
			cont=false; //hit the left end of the buffer
		}
		else if(pos==(length-1)){
			cont=false; //hit the right end of the buffer
		}
		else if(buff[pos]=='\n'){
			cont=false; //found a newline
		}
		else if(count==0){
			cont=false; //at correct position
		}
		count--;
		pos+=(d*-1);
	}
	cursor=pos;
}
