
#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	radius = sqrt((P1.x - P2.x)*(P1.x - P2.x) + (P2.y - P1.y)*(P2.y - P1.y));
}
void CCircle::Save(ofstream &filename)
{
	int r = sqrt((Corner1.x - Corner2.x)*(Corner1.x - Corner2.x) + (Corner2.y - Corner1.y)*(Corner2.y - Corner1.y));
	filename << "CIRCLE \t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << r << "\t" << colortoname(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled == true)
		filename << colortoname(FigGfxInfo.FillClr) << endl;
	else
		filename << "NO_FILL" << endl;

}
void CCircle::Load(ifstream &filename)
{
	int ID;
	Point P1, P2;
	int r;
	string DRAWCLR, FILLCLR;
	filename >> ID;
	SetID(ID);
	filename >> P1.x >> P1.y >> r >> DRAWCLR;
	P2.y = P1.y;
	P2.x = P1.x + r;
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
	//pOut->DrawCircle(P1,P2,FigureGfxInfo);
	/*ApplicationManager *Pmanager;
	Pmanager->AddFigure(this);
	*/
}

void CCircle::Draw(Output* pOut) const
{
		pOut->DrawCircle(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CCircle :: select (int a, int b, Output* pOut)
{
	int d1,d2;
	d1=(Corner2.x-Corner1.x)*(Corner2.x-Corner1.x)+(Corner2.y-Corner1.y)*(Corner2.y-Corner1.y);
	d2=(a-Corner1.x)*(a-Corner1.x)+(b-Corner1.y)*(b-Corner1.y);
	if (d2<=d1)
	{
		SetSelected (!IsSelected());
		if (IsSelected())
			PrintInfo (pOut);
		return true;
	}
	return false;
}
void CCircle :: PrintInfo(Output* pOut)
{
	stringstream ss1,ss2,ss3,ss4;
	ss1<<ID<<endl;
	ss2<<Corner1.x<<endl;
	ss3<<Corner1.y<<endl;
	int d1=sqrt((Corner2.x-Corner1.x)*(Corner2.x-Corner1.x)+(Corner2.y-Corner1.y)*(Corner2.y-Corner1.y));
	ss4<<d1<<endl;
	string s = "You Selected a Circle, ID= "+ss1.str()+" Start Point ("+ss2.str()+","+ss3.str()+")"+" Radius = "+ss4.str();
	pOut->PrintMessage(s);
}
double CCircle::GetArea()const
{
	return 22 * radius * radius / 7;
}
Point CCircle::GetCenter()const
{
	return Corner1;
}
void CCircle::TranslateFig(int x, int y)
{
	Corner1.x += x;
	Corner2.x += x;
	Corner1.y += y;
	Corner2.y += y;
}
CFigure * CCircle::CopyFig()
{
	CCircle * C1 = dynamic_cast <CCircle *>(this);
	CCircle * C2 = new CCircle(C1->Corner1, C1->Corner2, C1->FigGfxInfo);
	return C2;
}
void CCircle::ResizeFig(bool b)
{
	Corner2.x = Corner1.x + int (radius);
	Corner2.y = Corner1.y;
	if (b) {
		Corner2.x += int(radius);
	}
	else {
		Corner2.x -= int(radius) / 2;
	}
	radius = abs(Corner1.x - Corner2.x);
}
void CCircle::RotateFig()
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