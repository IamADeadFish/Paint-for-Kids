#pragma once
#include "Action.h"

class saveAction :public Action
{
	string filename;
public:
	saveAction(ApplicationManager * pApp);
	virtual void Execute();
	virtual void ReadActionParameters();
	~saveAction(void);
};
