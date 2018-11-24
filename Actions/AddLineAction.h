#ifndef ADD_LINE_ACTION_H
#define ADD_LINE_ACTION_H

#include "Action.h"


class AddLineAction: public Action
{
private:
	Point P1, P2; 
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);

	
	virtual void ReadActionParameters();
	
	
	virtual void Execute() ;
	
};

#endif