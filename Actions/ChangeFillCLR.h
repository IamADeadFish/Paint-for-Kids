#ifndef _CHANGE_FILL_CLR
#define _CHANGE_FILL_CLR

#include "Action.h"
#include "..\Figures\CFigure.h"
class ChangeFillCLR : public Action
{
	ActionType fillclr;
	int SelFigCount;
	CFigure ** SelFigList;
	color Fclr;
	bool FillCond;
public:
	ChangeFillCLR(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};


#endif