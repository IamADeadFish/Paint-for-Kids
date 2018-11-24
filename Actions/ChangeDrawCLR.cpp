#include "ChangeDrawCLR.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeDrawCLR::ChangeDrawCLR(ApplicationManager * pApp) :Action(pApp)
{
	DrawCond = true;
}

void ChangeDrawCLR::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Click on the Color you want to Draw with");
	drawclr = pManager->GetUserAction();
	pOut->ClearStatusBar();
	SelFigCount = pManager->GetSelFigCount();
	SelFigList = pManager->GetSelFigList();
}

void ChangeDrawCLR::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	switch (drawclr)
	{
	case DRAW_RED:
		Dclr = RED;
		break;

	case DRAW_WHITE:
		Dclr = WHITE;
		break;

	case DRAW_BLUE:
		Dclr = BLUE;
		break;

	case DRAW_GREY:
		Dclr = GREY;
		break;

	case DRAW_GREEN:
		Dclr = GREEN;
		break;

	case DRAW_BLACK:
		Dclr = BLACK;
		break;

	default:
		DrawCond = false;
		break;
	}
	if (DrawCond)
	{
		if (SelFigCount == 0)
			UI.DrawColor = Dclr;
		else
			for (int i = 0; i<SelFigCount; i++)
				SelFigList[i]->ChngDrawClr(Dclr);
	}
}
