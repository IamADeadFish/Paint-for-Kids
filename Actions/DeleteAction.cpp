#include "DeleteAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Output.h"


DeleteAction :: DeleteAction (ApplicationManager * pApp):Action(pApp)
{}

void DeleteAction :: ReadActionParameters() 
{
	
	SelFigCount=pManager->GetSelFigCount();
	SelFigList=pManager->GetSelFigList();
}

void DeleteAction :: Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	for (int i=0; i<SelFigCount; i++)
	{
		pManager->FigToNULL(SelFigList[i]);
		delete SelFigList[i];
		SelFigList[i]=NULL;
	}
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	pManager->DeleteFigure();
}
