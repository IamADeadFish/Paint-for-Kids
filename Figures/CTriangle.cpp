#include "CTriangle.h"
#include <fstream>
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
	
void CTriangle::Save(ofstream &filename)
{
	filename << "TRIANGLE \t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t"
		<< Corner2.y << "\t" << Corner3.x << "\t" << Corner3.y << "\t"
		<< colortoname(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
		filename << colortoname(FigGfxInfo.FillClr) << endl;
	else
		filename << "NO_FILL" << endl;
}
void CTriangle::Load(ifstream &filename)
{
	int ID;
	Point P1, P2, P3;
	string DRAWCLR, FILLCLR;
	filename >> ID;
	SetID(ID);
	filename >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y >> DRAWCLR;
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
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
	//pOut->DrawTriangle(P1,P2,P3,FigureGfxInfo);
	//ApplicationManager *Pmanager;
	//Pmanager->pOut->DrawTriangle(P1,P2,P3,FigureGfxInfo);

}
void CTriangle::Draw(Output* pOut) const
{

	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
double CTriangle :: CalcArea (int x1, int x2, int x3, int y1, int y2, int y3)const
{
	double Area = abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1-y2))/2.0;
	return Area;
}
bool CTriangle :: select (int a, int b, Output* pOut)
{
	double A,a1,a2,a3;
	A=CalcArea(Corner1.x,Corner2.x,Corner3.x,Corner1.y,Corner2.y,Corner3.y);
	a1=CalcArea(a,Corner2.x,Corner3.x,b,Corner2.y,Corner3.y);
	a2=CalcArea(Corner1.x,a,Corner3.x,Corner1.y,b,Corner3.y);
	a3=CalcArea(Corner1.x,Corner2.x,a,Corner1.y,Corner2.y,b);
	if (A==a1+a2+a3)
	{
		SetSelected (!IsSelected());
		if (IsSelected())
			PrintInfo (pOut);
		return true;
	}
	return false;
}
void CTriangle :: PrintInfo(Output* pOut)
{
	stringstream ss1,ss2,ss3,ss4,ss5,ss6,ss7;
	ss1<<ID<<endl;
	ss2<<Corner1.x<<endl;
	ss3<<Corner1.y<<endl;
	ss4<<Corner2.x<<endl;
	ss5<<Corner2.y<<endl;
	ss6<<Corner3.x<<endl;
	ss7<<Corner3.y<<endl;
	string s = "You Selected a Triangle, ID= "+ss1.str()+" Vertex1 ("+ss2.str()+","+ss3.str()+")"+" Vertex2 ("+ss4.str()+","+ss5.str()+")"+" Vertex3 ("+ss6.str()+","+ss7.str()+")";
	pOut->PrintMessage(s);
}Point CTriangle::GetCenter()const
{
	Point O;
	O.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	O.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return O;
}
double CTriangle::GetArea()const
{
	double A;
	A = CalcArea(Corner1.x, Corner2.x, Corner3.x, Corner1.y, Corner2.y, Corner3.y);
	return A;
	// I deleted area from private data members and made calcarea const
}
void CTriangle::TranslateFig(int x, int y)
{
	Corner1.x += x;
	Corner2.x += x;
	Corner3.x += x;
	Corner1.y += y;
	Corner2.y += y;
	Corner3.y += y;

}
CFigure * CTriangle::CopyFig()
{
	CTriangle * T1 = dynamic_cast <CTriangle *> (this);
	CTriangle * T2 = new CTriangle(T1->Corner1, T1->Corner2, T1->Corner3, T1->FigGfxInfo);
	return T2;
}
void CTriangle::ResizeFig(bool b)
{
	Point p;
	p = GetCenter();
	int x1, x2, x3, y1, y2, y3;
	x1 = Corner1.x - p.x;
	y1 = Corner1.y - p.y;
	x2 = Corner2.x - p.x;
	y2 = Corner2.y - p.y;
	x3 = Corner3.x - p.x;
	y3 = Corner3.y - p.y;
	if (b) {
		Corner1.x += x1;
		Corner2.x += x2;
		Corner1.y += y1;
		Corner2.y += y2;
		Corner3.x += x3;
		Corner3.y += y3;
	}
	else
	{
		x1 /= 2;   x2 /= 2;  x3 /= 2;        y1 /= 2;   y2 /= 2;  y3 /= 2;
		Corner1.x -= x1;
		Corner2.x -= x2;
		Corner3.x -= x3;
		Corner1.y -= y1;
		Corner2.y -= y2;
		Corner3.y -= y3;
	}
}
void CTriangle::RotateFig()
{
	Point p;
	p = GetCenter();
	int x1, x2, x3, y1, y2, y3;
	x1 = Corner1.x - p.x;
	y1 = Corner1.y - p.y;
	x2 = Corner2.x - p.x;
	y2 = Corner2.y - p.y;
	x3 = Corner3.x - p.x;
	y3 = Corner3.y - p.y;
	Corner1.x = p.x - y1;
	Corner1.y = p.y + x1;
	Corner2.x = p.x - y2;
	Corner2.y = p.y + x2;
	Corner3.x = p.x - y3;
	Corner3.y = p.y + x3;
}

