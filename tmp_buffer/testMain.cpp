#include <iostream>
#include <fstream>
#include "buffer.h"
using namespace std;
#define BYTES //if defined prints raw ascii rather than char
int main(){
	fstream file;
	file.open("testFile.txt");
	buffer fbuf;
	while(!file.eof()){
		char hold=file.get();
		if(!file.eof()){
			fbuf.addCh(hold);
		}
	}
	char action='l';
	while(action!='q'){
		#ifndef BYTES
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
		#else
		for(int c=0; c<fbuf.getLen(); c++){
			if(c==fbuf.getCur()){
				cout<<"("<<(int)fbuf.getCh(c)<<")"<<'\t';
			}
			else{
				cout<<(int)fbuf.getCh(c)<<'\t';
			}
		}
		cout<<endl;
		#endif
		cout<<endl;
		cout<<"action?"<<endl;
		cin>>action;
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
