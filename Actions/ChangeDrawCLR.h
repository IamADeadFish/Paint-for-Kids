#ifndef _CHANGE_DRAW_CLR
#define _CHANGE_DRAW_CLR

#include "Action.h"
#include "..\Figures\CFigure.h"
class ChangeDrawCLR : public Action
{
	ActionType drawclr;
	int SelFigCount;
	CFigure ** SelFigList;
	color Dclr;
	bool DrawCond;
public:
	ChangeDrawCLR(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif