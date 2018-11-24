#ifndef _ToDrawMode_
#define _ToDrawMode_
#include "Game.h"
class ToDrawMode:public Game
{
public:
	ToDrawMode(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif