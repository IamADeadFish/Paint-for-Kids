#include "Rotate.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\Output.h"


Rotate::Rotate(ApplicationManager *pApp):Action(pApp)
{}

void Rotate::ReadActionParameters()
{}

void Rotate::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	CFigure ** F = pManager->GetSelFigList();
	for (int i = 0; i < pManager->GetSelFigCount(); ++i)
		F[i]->RotateFig();
}
Rotate::~Rotate()
{}