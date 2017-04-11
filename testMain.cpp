#include <iostream>
#include <fstream>
#include "buffer.h"
using namespace std;

//this is a comment made on test-branch
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
		for(int c=0; c<fbuf.getLen(); c++){
			if(c==fbuf.getCur()){
				cout<<"_";
			}
			else{
				cout<<fbuf.getCh(c);
			}
		}
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
