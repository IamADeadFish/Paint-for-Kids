#ifndef _GAME_H
#define _GAME_H

#include "Action.h"
#include "DeleteAction.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
class Game : public Action
{
protected:
	ActionType ACTION;
	Point P;
	Action * pAct;
public:
	Game(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	void Unselect();
	int CountFigList();
	void  autosave();
	void autoload();
};

#endif