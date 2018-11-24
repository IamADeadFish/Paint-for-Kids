
#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include <fstream>

LoadAction::LoadAction(ApplicationManager * pApp):Action(pApp)
{
}
void LoadAction :: Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	ifstream loadedDoc(filename);
	if(loadedDoc.is_open())
	{
		//pOut->ClearDrawArea();
		pOut->PrintMessage("file loaded succesfully");
		pManager->resetcount();
		string c1,c2;
		// arbitrary parameters
		Point p1,p2,p3;
		p1.x=0;p2.x=0;p3.x=0;p1.y=0;p2.y=0;p3.y=0;
		GfxInfo FigureGfxInfo;
		int FigCount;
		loadedDoc >> c1 >>c2 ;
		UI.DrawColor=pManager->nametocolor(c1);
		UI.FillColor=pManager->nametocolor(c2);
		loadedDoc>>FigCount;
		string figtype;
	for (int i=0;i<FigCount;i++)
	{		
			loadedDoc>>figtype;
		if (figtype == "LINE")
		{
			CFigure *R=new CLine(p1,p2,FigureGfxInfo);
			R->Load(loadedDoc);
			pManager->AddFigure(R);
		}
		else if (figtype == "RECTANGLE")
		{
			CFigure *R=new CRectangle(p1,p2,FigureGfxInfo); 
			R->Load(loadedDoc);
			pManager->AddFigure(R);
		}
		else if (figtype == "TRIANGLE")
		{
			CFigure *R=new CTriangle(p1,p2,p3,FigureGfxInfo); 
			R->Load(loadedDoc);
			pManager->AddFigure(R);
		}
		else if (figtype == "CIRCLE")
		{
			CFigure *R=new CCircle(p1,p2,FigureGfxInfo); 
			R->Load(loadedDoc);
			pManager->AddFigure(R);
		}
	}}//for
	else 
	{pOut->PrintMessage("File not found");}
	
	}//func
	void LoadAction :: ReadActionParameters()
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();

		pOut->PrintMessage("enter name of the file you want to load ");
		filename=pIn->GetSrting(pOut);



	}

