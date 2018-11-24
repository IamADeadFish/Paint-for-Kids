#ifndef _EXIT_
#define _EXIT_

#include "Action.h"
class Exit :public Action
{
public:
	Exit(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Exit();
};
#endif