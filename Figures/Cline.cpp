#include "CLine.h"
#include <fstream>

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	length = sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y));
}
	
void CLine::Save(ofstream &filename)
{
	filename << "LINE \t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t"
		<< Corner2.y << "\t" << colortoname(FigGfxInfo.DrawClr) << endl;
}
void CLine::Load(ifstream &filename)
{
	int ID;
	Point P1, P2, P3;
	string DRAWCLR;
	filename >> ID;
	SetID(ID);
	filename >> P1.x >> P1.y >> P2.x >> P2.y >> DRAWCLR;
	Corner1 = P1;
	Corner2 = P2;
	CFigure::FigGfxInfo.DrawClr = nametocolor(DRAWCLR);
	//Output* pOut;
	//pOut->DrawLine(P1,P2,FigureGfxInfo);
	/*ApplicationManager *Pmanager;
	Pmanager->AddFigure(this);
	*/
}
void CLine::Draw(Output* pOut) const
{
		pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CLine :: select (int a, int b, Output* pOut)
{
	int maxX=0,minX=0,maxY=0,minY=0;
	if (((Corner2.y-Corner1.y)/(Corner2.x-Corner1.x))==((Corner2.y-b)/(Corner2.x-a)))
	{
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
	
	}
	return false;
}
void CLine :: PrintInfo(Output* pOut)
{
	stringstream ss1,ss2,ss3,ss4,ss5;
	ss1<<ID<<endl;
	ss2<<Corner1.x<<endl;
	ss3<<Corner1.y<<endl;
	ss4<<Corner2.x<<endl;
	ss5<<Corner2.y<<endl;
	string s = "You Selected a Line, ID= "+ss1.str()+" Start Point ("+ss2.str()+","+ss3.str()+")"+" End Point ("+ss4.str()+","+ss5.str()+")";
	pOut->PrintMessage(s);
}double CLine::GetArea()const
{
	return 2 * length;
}
Point CLine::GetCenter()const
{
	Point O;
	O.x = (Corner1.x + Corner2.x) / 2;
	O.y = (Corner1.y + Corner2.y) / 2;
	return O;
}
void CLine::TranslateFig(int x, int y)
{
	Corner1.x += x;
	Corner2.x += x;
	Corner1.y += y;
	Corner2.y += y;
}
CFigure * CLine::CopyFig()
{
	CLine * L1 = dynamic_cast <CLine *> (this);
	CLine * L2 = new CLine(L1->Corner1, L1->Corner2, L1->FigGfxInfo);
	return L2;
}
void CLine::ResizeFig(bool b)
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
void CLine::RotateFig()
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
