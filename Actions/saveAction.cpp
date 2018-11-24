#include "saveAction.h"
#include "..\ApplicationManager.h"
#include <fstream>

saveAction::saveAction(ApplicationManager * pApp):Action(pApp)
{
}
void saveAction :: Execute()
{
Output* pOut = pManager->GetOutput();
ReadActionParameters();
ofstream savedDoc(filename);
savedDoc<< pManager->colortoname(UI.DrawColor) <<'\t'<<pManager->colortoname(UI.FillColor)<<endl;
pManager->saveAll(savedDoc);
pOut->PrintMessage("file saved ");
savedDoc.close();
}
void saveAction :: ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("enter name of the file to save in ");
	filename=pIn->GetSrting(pOut);

	

}
saveAction::~saveAction(void)
{
}
