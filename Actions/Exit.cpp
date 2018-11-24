#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "Exit.h"

Exit::Exit(ApplicationManager *pApp):Action(pApp)
{}

void Exit::ReadActionParameters()
{}

void Exit::Execute()
{
	pManager->ClearClipboard();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	delete pOut;
	delete pIn;
	pManager->SetpOutToNull();
}
Exit::~Exit()
{}