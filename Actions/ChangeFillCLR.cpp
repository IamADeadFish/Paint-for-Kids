#include "ChangeFillCLR.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeFillCLR::ChangeFillCLR(ApplicationManager * pApp) :Action(pApp)
{
	FillCond = true;
}

void ChangeFillCLR::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Click on the Color you want to Fill with");
	fillclr = pManager->GetUserAction();
	pOut->ClearStatusBar();
	SelFigCount = pManager->GetSelFigCount();
	SelFigList = pManager->GetSelFigList();
}

void ChangeFillCLR::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	switch (fillclr)
	{
	case DRAW_RED:
		Fclr = RED;
		break;

	case DRAW_WHITE:
		Fclr = WHITE;
		break;

	case DRAW_BLUE:
		Fclr = BLUE;
		break;

	case DRAW_GREY:
		Fclr = GREY;
		break;

	case DRAW_GREEN:
		Fclr = GREEN;
		break;

	case DRAW_BLACK:
		Fclr = BLACK;
		break;

	default:
		FillCond = false;
		break;
	}
	if (FillCond)
	{
		if (SelFigCount == 0)
		{
			pManager->SetFillCond(true);
			UI.FillColor = Fclr;
		}
		else
			for (int i = 0; i<SelFigCount; i++)
				SelFigList[i]->ChngFillClr(Fclr);
	}
}


