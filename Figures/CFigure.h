#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <sstream>
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info

	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual bool select (int x, int y, Output* pOut)=0;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

    color getfillclr();
	bool getisfilled();
	color GetDrawclr();
	string colortoname(color sample);
	color nametocolor(string sample);
	void SetID (int);
	int GetID();
	virtual void PrintInfo(Output* pOut)=0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual double GetArea()const = 0;
	virtual Point GetCenter()const = 0;
	virtual void TranslateFig(int x, int y) = 0;
	virtual CFigure * CopyFig() = 0;
	virtual void ResizeFig(bool b) = 0;
	virtual void RotateFig() = 0;
	virtual void Save(ofstream &filename) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &filename) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif