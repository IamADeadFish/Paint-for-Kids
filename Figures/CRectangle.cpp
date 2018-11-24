#include "CRectangle.h"
#include <fstream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
void CRectangle::Save(ofstream &filename)
{
	filename << "RECTANGLE \t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t"
		<< Corner2.y << "\t" << colortoname(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
		filename << colortoname(FigGfxInfo.FillClr) << endl;
	else
		filename << "NO_FILL" << endl;

}
void CRectangle::Load(ifstream &filename)
{
	int ID;
	Point P1, P2, P3;
	string DRAWCLR, FILLCLR;
	filename >> ID;
	SetID(ID);
	filename >> P1.x >> P1.y >> P2.x >> P2.y >> DRAWCLR;
	Corner1 = P1;
	Corner2 = P2;
	CFigure::FigGfxInfo.DrawClr = nametocolor(DRAWCLR);
	filename >> FILLCLR;
	if (FILLCLR == "NO_FILL")
		CFigure::FigGfxInfo.isFilled = false;
	else
	{
		CFigure::FigGfxInfo.FillClr = nametocolor(FILLCLR);
		CFigure::FigGfxInfo.isFilled = true;
	}
	//Output* pOut;
	//pOut->DrawRect(P1,P2,FigureGfxInfo);
	/*ApplicationManager *Pmanager;
	Pmanager->AddFigure(this);
	*/
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle :: select (int a, int b, Output* pOut)
{
	int maxX=0,minX=0,maxY=0,minY=0;
	if (Corner1.x >Corner2.x)
	{
		maxX=Corner1.x;
		minX=Corner2.x;
	}
	else
	{
		maxX=Corner2.x;
		minX=Corner1.x;
	}
	if (Corner1.y >Corner2.y)
	{
		maxY=Corner1.y;
		minY=Corner2.y;
	}
	else
	{
		maxY=Corner2.y;
		minY=Corner1.y;
	}
	if (a>=minX && a<=maxX && b>=minY && b<=maxY)
	{
		SetSelected (!IsSelected());
		if (IsSelected())
			PrintInfo (pOut);
		return true;
	}
	return false;
}
void CRectangle :: PrintInfo(Output* pOut)
{
	stringstream ss1,ss2,ss3;
	ss1<<ID<<endl;
	ss2<<abs(Corner1.x-Corner2.x)<<endl;
	ss3<<abs(Corner1.y-Corner2.y)<<endl;
	string s = "You Selected a Rectangle, ID= "+ss1.str()+" Length = "+ss2.str()+" , Width = "+ss3.str();
	pOut->PrintMessage(s);
}double CRectangle::GetArea()const
{
	return abs((Corner2.x - Corner1.x) * (Corner2.y - Corner1.y));
}
Point CRectangle::GetCenter()const
{
	Point O;
	O.x = 0;
	O.x = (Corner1.x + Corner2.x) / 2;
	O.y = (Corner1.y + Corner2.y) / 2;
	return O;
}
void CRectangle::TranslateFig(int x, int y)
{
	Corner1.x += x;
	Corner2.x += x;
	Corner1.y += y;
	Corner2.y += y;
}
CFigure * CRectangle::CopyFig()
{
	CRectangle * R1 = dynamic_cast <CRectangle *>(this);
	CRectangle * R2 = new CRectangle(R1->Corner1, R1->Corner2, R1->FigGfxInfo);
	return R2;
}
void CRectangle::ResizeFig(bool b)
{
	Point p;
	p = GetCenter();
	int x1, x2, y1, y2;
	x1 = Corner1.x - p.x;
	y1 = Corner1.y - p.y;
	x2 = Corner2.x - p.x;
	y2 = Corner2.y - p.y;
	if (b) {
		Corner1.x += x1;
		Corner2.x += x2;
		Corner1.y += y1;
		Corner2.y += y2;
	}
	else
	{
		x1 /= 2;   x2 /= 2;         y1 /= 2;   y2 /= 2;  
		Corner1.x -= x1;
		Corner2.x -= x2;
		Corner1.y -= y1;
		Corner2.y -= y2;
	}
}
void CRectangle::RotateFig()
{
	Point p;
	p = GetCenter();
	int x1, x2, y1, y2;
	x1 = Corner1.x - p.x;
	y1 = Corner1.y - p.y;
	x2 = Corner2.x - p.x;
	y2 = Corner2.y - p.y;
	Corner1.x = p.x - y1;
	Corner1.y = p.y + x1;
	Corner2.x = p.x - y2;
	Corner2.y = p.y + x2;
}
