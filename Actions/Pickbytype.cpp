#include "Pickbytype.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

Pickbytype::Pickbytype(ApplicationManager * pApp):Game(pApp),CntCorrect(0),CntInCorrect(0)
{}

void Pickbytype::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(Display());
}
void Pickbytype::Execute()
{
	autoload();
	pManager->UpdateInterface();
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int Counter=CountFigList();
	if(Counter!=0)
	{
		int Count=CountType();
		int Check=Classify(Random());
		while(Counter>0&&Count>0)
		{
			pIn->GetPointClicked(P.x,P.y);
			ACTION=pIn->GetUserAction2(P.x,P.y);
			if(ACTION==PICKTYPE||ACTION==PICKCOLOR||ACTION==PICKTYPECOLOR||ACTION==TO_DRAW||ACTION==EXIT)
				break;
			CFigure * Fig = pManager->GetFigure(P.x, P.y);
			if(Check==Classify(Fig))
			{
				pAct = new DeleteAction(pManager);
				pAct->Execute();
				pManager->UpdateInterface();
				pOut->PrintMessage("Correct");
				CntCorrect++;
				Counter--;
				Count--;
				delete pAct;
				pAct = NULL;
				
			}
			else if(Fig	!=	NULL)
			{

				pAct = new DeleteAction(pManager);
				pAct->Execute();
				pManager->UpdateInterface();

				pOut->PrintMessage("INCORRECT");
				CntInCorrect++;
				Counter--;
				delete pAct;
				pAct = NULL;
			}
			else
			{
				pOut->PrintMessage("INCORRECT");
				CntInCorrect++;
			}
		}
		pOut->PrintMessage("Your Score Is "+to_string(CntCorrect)+" OUT OF" +to_string(CntCorrect+CntInCorrect));
	}
}
CFigure* Pickbytype::Random()
{
	if(CountFigList()!=0)
		return pManager->CopyFigList()[0];
	else 
		return NULL;
}
int Pickbytype::CountType()
{
	int COUNTRECT=0;
	int COUNTCIRC=0;
	int COUNTTRI=0;
	int COUNTLINE=0;
	for(int i=0;i<CountFigList();i++)
	{
		if(Classify(pManager->CopyFigList()[i])==1)
			COUNTRECT++;
		else if(Classify(pManager->CopyFigList()[i])==2)
			COUNTCIRC++;
		else if(Classify(pManager->CopyFigList()[i])==3)
			COUNTTRI++;
		else 
			COUNTLINE++;
	}
	if(Classify(Random())==1)
		return COUNTRECT;
	if(Classify(Random())==2)
		return COUNTCIRC;
	if(Classify(Random())==3)
		return COUNTTRI;
	return COUNTLINE;
}
int Pickbytype::Classify(CFigure* F)
{
	if(F==NULL)                                 //Figlist is empty
		return -1;
	if(dynamic_cast<CRectangle*>(F))
		return 1;
	if(dynamic_cast<CCircle*>(F))
		return 2;
	if(dynamic_cast<CTriangle*>(F))
		return 3;
	if(dynamic_cast<CLine*>(F))
		return 4;
}
string Pickbytype::Display()
{
	switch (Classify(Random()))
	{
	case -1:
		return "PLease Draw AnyShape To PLay";
		break;
	case 1:
		return "PLease PickbyType ::Rectangle";
		break;
	case 2:
		return "Please PickbyType ::Circle";
		break;
	case 3:
		return "Please PickbyType ::Triangle";
		break;
	case 4:
		return "PLease Pickbytype ::Line";
		break;

	}
}
