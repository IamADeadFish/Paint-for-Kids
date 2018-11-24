#pragma once
#include "Action.h"

class LoadAction :public Action
{
	string filename;
public:
	LoadAction(ApplicationManager * pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
	~LoadAction(void);
};
