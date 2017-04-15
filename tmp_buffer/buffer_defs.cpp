#include "buffer.h"

buffer::buffer(){
	buff=new char[1];
	length=1;
	cursor=0;
	buff[0]=-1;
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
	//swap the pointer to the temporary array and the old buffer array
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
	//swap the pointer to the temporary array and the old buffer array
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
	/*
	*returns char at buffer address if available
	*otherwise returns NULL
	*/
	if((addr<0)||(addr>=length)){
		return '\0';
	}
	return buff[addr];
}

bool buffer::curHzl(bool dir){
	/*
	*dir==true moves the cursor left
	*dir==false moves the cursor right
	*returns true if cursor moved, false otherwise
	*/
	if((cursor==0)&&(dir==true)){
		return false;
	}
	if((cursor==length-1)&&(dir==false)){
		return false;
	}
	if(dir==true){
		cursor--;
		return true;
	}
	if(dir==false){
		cursor++;
		return true;
	}
	return false;
}

bool buffer::curVrt(bool dir){
	/*
	*moves cursor to its current index, in the line above/below
	*moves up if dir==true, else down
	*if line the cursor is moving into is shorter than its current
	*index then the cursor moves to the end of the new line
	*if the cursor is moved up at the top of the file it is moved to the 
	*first character
	*if the cursor is moved down at the bottom of the file it is moved
	*to the last character
	*returns true if the cursor was moved to a new line; false otherwise
	*/
	int CtoS=1;
	bool move=true;
	while(move){
		move=curHzl(true);
		if((!move)&&(dir)){return false;}
		if((!move)&&(!dir)){CtoS--;}
		if(buff[cursor]=='\n'){
			move=false;
		}
		else{
			CtoS++;
		}
	}
	move=true;
	while(move){
		move=curHzl(dir);
		if((!move)&&(!dir)){return false;}
		if((!move)&&(dir)){CtoS--;}
		if(buff[cursor]=='\n'){
			move=false;
		}
	}
	move=true;
	while(move){
		move=curHzl(false);
		if(buff[cursor]=='\n'){
			move=false;
		}
		else if(CtoS==1){
			move=false;
		}
		else{
			CtoS--;
		}
	}
	return true;
}
