#ifndef _ROTATE_
#define _ROTATE_

#include "Action.h"
class Rotate:public Action
{
public:
	Rotate(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Rotate();
};
#endif 
