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
//moves cursor to the same position in the line above
//if the line above is shorter than the cursor's position in the current line
//the cursor is moved to the end of line above
//trying to move off the left of the buffer is a no-op
	int CtoE=1;
	bool move=true;
	while(move){
		move=curHzl(true);
		if(buff[cursor]=='\n'){
			move=false;
		}
		else{
			CtoE++;
		}
	}
	move=true;
	while(move){
		move=curHzl(true);
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
		else if(CtoE==1){
			move=false;
		}
		else{
			CtoE--;
		}
	}
}

void buffer::curDn(){
//moves cursor to the same position in the line below
//if the line below is shorter than the cursor's position in the current line
//the cursor is moved to the end of line below
//trying to move off the right of the buffer is a no-op
	int CtoE=1;
	int nlinel=1;
	bool move=true;
	while(move){
		move=curHzl(true);
		if(buff[cursor]=='\n'){
			move=false;
		}
		else{
			CtoE++;
		}
	}
	move=true;
	while(move){
		move=curHzl(false);
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
		else{
			nlinel++;
		}
	}
	if(nlinel<=CtoE){return;}
	move=true;
	int backtrack=nlinel-CtoE;
	while(move){
		move=curHzl(true);
		if(buff[cursor]=='\n'){
			move=false;
		}
		else if(backtrack==1){
			move=false;
		}
		else{
			backtrack--;
		}
	}
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

bool buffer::curHzl(bool dir){
	//dir==true moves the cursor left
	//dir==false moves the cursor right
	//returns true if cursor moved, false otherwise
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
