#include "Select.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Select :: Select (ApplicationManager * pApp):Action(pApp)
{}

void Select :: ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please Click on the shape you want to select");

	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();
}
void Select :: Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	CFigure * R = pManager->GetFigure (P.x , P.y);
}
