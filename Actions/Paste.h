#ifndef _PASTE_
#define _PASTE_

#include "Action.h"
#include "..\Figures\CFigure.h"

class Paste :public Action
{
public:
	Paste(ApplicationManager * pApp);
	~Paste();
	virtual void ReadActionParameters();
	virtual void Execute();
private:
	Point Pfirst, Psecond;
	int ClipBoardCount;
	Point GetCenter(CFigure ** F);
	void PasteFig(CFigure ** F);
	void TranslateFig(CFigure ** F);
};
#endif


