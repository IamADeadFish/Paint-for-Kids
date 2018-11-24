#ifndef _Pickbytype_
#define _Pickbytype_
#include "..\Figures\CFigure.h"
#include "Game.h"
class Pickbytype: public Game
{
	int CntCorrect;
	int CntInCorrect;
	public:
	Pickbytype(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	CFigure* Random();
	int CountType();
	int Classify(CFigure*);
	string Display();
};
#endif