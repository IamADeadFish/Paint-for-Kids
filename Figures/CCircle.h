#ifndef CCircle_H
#define CCircle_H

#include "CFigure.h"
#include <fstream>

class CCircle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	double radius;
public:
	CCircle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool select (int x, int y, Output* pOut);
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