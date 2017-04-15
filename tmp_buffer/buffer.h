#ifndef __TMPBUFFER__
#define __TMPBUFFER__
class buffer{
	public:
		//moves cursor index within buffer
		buffer();
		~buffer();
		void curUp();
		void curDn();
		void curLt();
		void curRt();
		void addCh(char); //add char in front of cursor
		void rmvCh(); //remove char that cursor is pointing at
		int getLen(){return length;} //returns length of buffer
		int getCur(){return cursor;} //returns pos of cursor
		char getCh(int); //returns char at index
	private:
		int length; //length of buffer
		int cursor; //cursor index
		char* buff; //the buffer
		bool curHzl(bool); //horizontal cursor movement
		bool curVrt(bool); //vertical cursor movement
};
#endif
