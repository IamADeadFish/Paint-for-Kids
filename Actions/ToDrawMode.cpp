#include "ToDrawMode.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

ToDrawMode::ToDrawMode(ApplicationManager * pApp):Game(pApp)
{}
void ToDrawMode::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
}
void ToDrawMode::Execute()
{
	ReadActionParameters();
	autoload();
	pManager->UpdateInterface();
}