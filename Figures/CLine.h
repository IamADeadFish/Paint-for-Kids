#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	double length;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool select (int , int , Output* pOut);
	void PrintInfo(Output* pOut);
	double GetArea()const;
	Point GetCenter()const;
	void TranslateFig(int x, int y);
	CFigure * CopyFig();
	virtual void ResizeFig(bool b);
	void RotateFig();
	virtual void Save(ofstream &filename);
	virtual void Load(ifstream &filename);
};

#endif