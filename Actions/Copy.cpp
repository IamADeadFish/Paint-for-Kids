#include "Copy.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\Output.h"

Copy::Copy(ApplicationManager *pApp) :Action(pApp)
{}
void Copy::Execute()
{
	ReadActionParameters();
	if (ClipBoardCount > 0) {
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("You Copied all the selected figures ");
	}
}
void Copy::ReadActionParameters()
{
	pManager->ClearClipboard();
	pManager->AddToClipboard();
	ClipBoardCount = pManager->GetClipboardCount();
}
Copy::~Copy()
{}