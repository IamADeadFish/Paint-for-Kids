#include "CFigure.h"


CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}
string CFigure::colortoname(color sample)
{
	if (sample == BLACK)
		return "BLACK";
	else if (sample == WHITE)
		return "WHITE";
	else if (sample == GREY)
		return "GREY";
	else if (sample == GREEN)
		return "GREEN";
	else if (sample == RED)
		return "RED";
	else if (sample == BLUE)
		return "BLUE";
	else
	{/*do nothing*/
	}
}
color CFigure::nametocolor(string sample) {
	if (sample == "BLACK")
		return BLACK;
	else if (sample == "WHITE")
		return WHITE;
	else if (sample == "GREY")
		return GREY;
	else if (sample == "GREEN")
		return GREEN;
	else if (sample == "RED")
		return RED;
	else if (sample == "BLUE")
		return BLUE;
	else
	{/*do nothing*/
	}
}
void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
 color CFigure::getfillclr()
{
	return FigGfxInfo.FillClr;
}
 bool CFigure::getisfilled()
 {
	 return FigGfxInfo.isFilled;
 }
 void CFigure :: SetID (int id)
 {
	 ID=id;
 }
 int CFigure :: GetID ()
 {
	 return ID;
 }
 color CFigure::GetDrawclr()
 {
	 return FigGfxInfo.DrawClr;
 }
