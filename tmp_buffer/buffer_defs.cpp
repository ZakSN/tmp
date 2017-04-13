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

bool buffer::curVrt(bool dir){
	//dir==true moves the cursor to the same index in the line above
	//dir==flase moves the cursor to the same index in the line below
	//true if cursor moved, false otherwise
	bool move=true;
	int CtoE=1; //distance between cursor and end of line
	int Clinel=1; //(c)urrent(line)(l)ength
	int Nlinel=1; //(n)ew(line)(l)ength
	while(move){
		move=curHzl(dir);
		if(buff[cursor]=='\n'){
			move=false;
		}
		else{
			CtoE++;
		}
	}
	move=true;
	while(move){
		move=curHzl(!dir);
		if(buff[cursor]=='\n'){
			move=false;
		}
		else{
			Clinel++;
		}
	}
	move=true;
	while(move){
		move=curHzl(dir);
		if(buff[cursor]=='\n'){
			move=false;
		}
	}
	move=true;
	while(move){
		move=curHzl(dir);
		if(buff[cursor]=='\n'){
			move=false;
		}
		else{
			Nlinel++;
		}
	}
	if(dir&&(Nlinel<CtoE)){return true;}
	if(Nlinel<(Clinel-CtoE)){return true;}
	int backtrack;
	if(dir){backtrack=Clinel-CtoE;}
	else{backtrack=CtoE;}
	move=true;
	while(move){
		move=curHzl(!dir);
		backtrack--;
		if(backtrack==1){
			move=false;
		}
	}
	return true;
}
