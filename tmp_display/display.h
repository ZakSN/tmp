#ifndef __TMPDISPLAY__
#define __TMPDISPLAY__
#include "buffer.h"
class display{
	public:
		display(); //create a display with a pointer to a null buffer
		display(buffer*); //create a display and initialize it with a buffer*
		~display(); //point away from buff
		void init(buffer*); //initialize a display with a buffer*
		void refresh(); //redraw the display
	private:
		/*
		*since a buffer contains an entire file it is inherently massive
		*for this reason the display deals only with pointers to buffers
		*this avoids making unecessary copies of buffers; especially
		*important if I ever decide to implement multi-buffering
		*/
		buffer* buff;
};
#endif
