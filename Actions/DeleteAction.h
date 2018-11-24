#ifndef _DELETE_ACTION
#define _DELETE_ACTION

#include "Action.h"
#include "..\Figures\CFigure.h"
class DeleteAction : public Action
{
	CFigure ** SelFigList;
	int SelFigCount;
	public:
	DeleteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};

#endif