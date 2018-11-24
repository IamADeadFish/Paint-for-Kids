#ifndef _COPY_
#define _COPY_

#include "Action.h"

class Copy :public Action
{
private:
	int ClipBoardCount;

public:
	Copy(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Copy();
};

#endif 