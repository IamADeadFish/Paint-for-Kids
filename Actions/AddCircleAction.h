#ifndef ADD_Circle_ACTION_H
#define ADD_Circle_ACTION_H

#include "Action.h"


class AddCircleAction: public Action
{
private:
	Point P1, P2; 
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager *pApp);

	
	virtual void ReadActionParameters();
	
	
	virtual void Execute() ;
	
};

#endif