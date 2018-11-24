#include "Game.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include<fstream>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "Pickbytype.h"

#include<fstream>

Game :: Game (ApplicationManager * pApp):Action(pApp)
{}

void Game::autoload() {
	Output* pOut = pManager->GetOutput();
	ifstream loadedDoc("autosave.txt");
	if (loadedDoc.is_open())
	{
		pOut->ClearDrawArea();
		pManager->resetcount();
		string c1, c2;
		// arbitrary parameters
		Point p1, p2, p3;
		p1.x = 0; p2.x = 0; p3.x = 0; p1.y = 0; p2.y = 0; p3.y = 0;
		GfxInfo FigureGfxInfo;
		int FigCount;
		loadedDoc >> c1 >> c2;
		UI.DrawColor = pManager->nametocolor(c1);
		UI.FillColor = pManager->nametocolor(c2);
		loadedDoc >> FigCount;
		string figtype;
		for (int i = 0; i<FigCount; i++)
		{
			loadedDoc >> figtype;
			if (figtype == "LINE")
			{
				CFigure *R = new CLine(p1, p2, FigureGfxInfo);
				R->Load(loadedDoc);
				pManager->AddFigure(R);
			}
			else if (figtype == "RECTANGLE")
			{
				CFigure *R = new CRectangle(p1, p2, FigureGfxInfo);
				R->Load(loadedDoc);
				pManager->AddFigure(R);
			}
			else if (figtype == "TRIANGLE")
			{
				CFigure *R = new CTriangle(p1, p2, p3, FigureGfxInfo);
				R->Load(loadedDoc);
				pManager->AddFigure(R);
			}
			else if (figtype == "CIRCLE")
			{
				CFigure *R = new CCircle(p1, p2, FigureGfxInfo);
				R->Load(loadedDoc);
				pManager->AddFigure(R);
			}
		}
	}//for
}//func
void Game :: ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("Please Click on the Game you want to play");
	pOut->ClearStatusBar();
}

void Game :: Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	autosave();
	Unselect();
	
}
void Game::Unselect() // to ensure that all figures are unselected to safely use getfigure function
/*{
	for(int i=0;i<200;i++)
		if(pManager->CopyFigList()[i]!=NULL) //means that fig is empty  or contains elements
			if(pManager->CopyFigList()[i]->IsSelected())
				pManager->CopyFigList()[i]->SetSelected(false);
			else break;
}*/
{
	for (int i = 0; i < pManager->GetSelFigCount(); i++)
	{
		pManager->GetSelFigList()[i]->SetSelected(false);
		pManager->GetSelFigList()[i] = NULL;
	}
	pManager->SetSelFigCount(0);
}

	void Game::autosave()
{
	ofstream savedDoc("autosave.txt");
	savedDoc << pManager->colortoname(UI.DrawColor) << '\t' << pManager->colortoname(UI.FillColor) << endl;
	pManager->saveAll(savedDoc);
	savedDoc.close();
}
int Game::CountFigList()
{
	int C=0;
	for(int i=0;i<200;i++)
		if(pManager->CopyFigList()[i]!=NULL)
			C++;
		else
			return C;
	return C;
}