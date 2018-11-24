#ifndef _CUT_
#define _CUT_

#include "Action.h"


class Cut :public Action
{
private:
	int ClipBoardCount;


public:
	Cut(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Cut();
};

#endif 