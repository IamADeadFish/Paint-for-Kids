#ifndef _CTRIANGLE_H
#define _CTRIANGLE_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool select (int x, int y, Output* pOut);
	double CalcArea (int x1, int x2, int x3, int y1, int y2, int y3)const;
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