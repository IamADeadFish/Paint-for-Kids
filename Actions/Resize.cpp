#include "Resize.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\Output.h"

Resize::Resize(ApplicationManager *pApp, bool b) :Action(pApp)
{
	ResizeBig = b;
}

void Resize::ReadActionParameters()
{}

void Resize::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	CFigure ** F = pManager->GetSelFigList();
	for (int i = 0; i < pManager->GetSelFigCount(); ++i)
		F[i]->ResizeFig(ResizeBig);
}
Resize::~Resize()
{}