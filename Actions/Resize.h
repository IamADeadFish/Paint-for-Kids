#ifndef _RESIZE_
#define _RESIZE_

#include "Action.h"
class Resize :public Action
{
private:
	bool ResizeBig;

public:
	Resize(ApplicationManager *pApp, bool b);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Resize();
};
#endif