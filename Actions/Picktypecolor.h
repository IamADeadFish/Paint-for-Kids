#ifndef _Picktypecolor_
#define _Picktypecolor_
#include "..\Figures\CFigure.h"
#include "Game.h"
class Picktypecolor: public Game
{
	int CntCorrect;
	int CntInCorrect;
public:
	Picktypecolor(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	CFigure* Random();
	int CountTypeColor();
	int Classify(CFigure*);
	string Display();
};
#endif