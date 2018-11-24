#include "Cut.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

Cut::Cut(ApplicationManager *pApp) :Action(pApp)
{}
void Cut::Execute()
{
	ReadActionParameters();
	if (ClipBoardCount > 0) {
		Output* pOut = pManager->GetOutput();

		pOut->PrintMessage("You Cut all the selected figures ");
		pManager->ExecuteAction(DEL);
	}
}
void Cut::ReadActionParameters()
{
	pManager->ClearClipboard();
	pManager->AddToClipboard();
	ClipBoardCount = pManager->GetClipboardCount();
}
Cut::~Cut()
{}
