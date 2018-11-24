#ifndef _Pickbycolor_
#define _Pickbycolor_
#include "..\Figures\CFigure.h"
#include "Game.h"
class Pickbycolor: public Game
{
	int CntCorrect;
	int CntInCorrect;
public:
	Pickbycolor(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	CFigure* Random();
	int Classify(CFigure*);
	int CountColor();
	string Display();
};
#endif