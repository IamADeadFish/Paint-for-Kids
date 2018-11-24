#ifndef SELECT_H
#define SELECT_H

#include "Action.h"

class Select : public Action
{
	Point P;
public:
	Select (ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	
};

#endif