#ifndef __TMPDISPLAY__
#define __TMPDISPLAY__
#include "buffer.h"
class display{
	public:
		display(); //create a display with a pointer to a null buffer
		display(buffer*) //create a display an initialize it with a buffer*
		~display(); //point away from buff
		init(buffer*); //initialize a display with a buffer*
		refresh(); //redraw the display
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
