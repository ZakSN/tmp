#ifndef __TMPDISPLAY__
#define __TMPDISPLAY__
#include "buffer.h"
class display{
	public:
		display();
		display(buffer)
		~display();
		show(buffer);
		refresh();
	private:
		buffer buff;
};
#endif
