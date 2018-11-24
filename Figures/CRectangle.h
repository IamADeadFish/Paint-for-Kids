#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool select (int x, int y, Output* pOut);
	void PrintInfo(Output* pOut);
	virtual double GetArea()const;
	virtual Point GetCenter()const;
	virtual void TranslateFig(int x, int y);
	virtual CFigure * CopyFig();
	virtual void ResizeFig(bool b);
	void RotateFig();
	virtual void Save(ofstream &filename);
	virtual void Load(ifstream &filename);
};

#endif