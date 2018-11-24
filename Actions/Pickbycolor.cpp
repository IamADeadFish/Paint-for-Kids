#include "Pickbycolor.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

Pickbycolor::Pickbycolor(ApplicationManager * pApp):Game(pApp),CntCorrect(0),CntInCorrect(0)
{}

void Pickbycolor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(Display());
}
void Pickbycolor::Execute()
{
	autoload();
	pManager->UpdateInterface();
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int Counter=CountFigList();   //count allfig
	int Count=CountColor();      //count needed fig
	if(Counter!=0&&Count!=0)
	{
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
				//Delete();
				pAct = new DeleteAction(pManager);
				pAct->Execute();
				pManager->UpdateInterface();
				pOut->PrintMessage("Correct");
				CntCorrect++;
				Counter--;
				Count--;
				
			}
			else if(Fig != NULL)
			{
				//Delete(); if user clicked on shape
				pAct = new DeleteAction(pManager);
				pAct->Execute();
				pManager->UpdateInterface();
				pOut->PrintMessage("INCORRECT");
				CntInCorrect++;
				Counter--;
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
CFigure* Pickbycolor::Random()
{
	if(CountFigList()==0)
		return NULL;
	for(int i=0;i<CountFigList();i++)
		if(pManager->CopyFigList()[i]->getisfilled())
			return pManager->CopyFigList()[i];
	return pManager->CopyFigList()[0];
}
int Pickbycolor::Classify(CFigure* F)
{
	if(F==NULL&&CountFigList()==0)         //figlist empty
		return -1;  
	if((dynamic_cast<CLine*>(F))&&CountFigList()!=0)      //figlist is not colored //Choose DrawClr FOR LINE ONLY
	{
		if(F->GetDrawclr()==RED)
			return 1;
		if(F->GetDrawclr()==BLUE)
			return 2;
		if(F->GetDrawclr()==GREEN)
			return 3;
		if(F->GetDrawclr()==WHITE)
			return 4;
		if(F->GetDrawclr()==BLACK)
			return 5;
		if(F->GetDrawclr()==GREY)
			return 6;
	}
	if(F==NULL&&CountFigList()!=0)
		return -2;
	if((F->getfillclr()==RED)&&F->getisfilled())
		return 1;
	if((F->getfillclr()==BLUE)&&F->getisfilled())
		return 2;
	if((F->getfillclr()==GREEN)&&F->getisfilled())
		return 3;
	if((F->getfillclr()==WHITE)&&F->getisfilled())
		return 4;
	if((F->getfillclr()==BLACK)&&F->getisfilled())
		return 5;
	if((F->getfillclr()==GREY)&&F->getisfilled())
		return 6;
	return -2;
}
string Pickbycolor::Display()
{
	switch (Classify(Random()))
	{

	case -1:
			return "Please Draw SomeThing To Play";
			break;
	case -2:
			return "PLease Color AnyFigure To PLay This Mode";
			break;
	case 1:
			return "PLease PickbyColor ::RED ";
			break;
	case 2:
			return "PLease PickbyColor ::BLUE ";
			break;
	case 3:
			return "Please PickbyColor ::GREEN ";
			break;
	case 4:
			return "PLease PickbyColor ::WHITE ";
			break;
	case 5:
		    return "PLease PickbyColor ::BLACK ";
			break;
	case 6:
		    return "PLease PickbyColor ::GREY ";
			break;
	}
}
int Pickbycolor::CountColor()
{
	int COUNTRED=0;
	int COUNTBLUE=0;
	int COUNTGREEN=0;
	int COUNTWHILE=0;
	int COUNTBLACK=0;
	int COUNTGREY=0;
	if(Classify(Random())==-1||(Classify(Random())==-2))
		return 0;
	for(int i=0;i<CountFigList();i++)
	{
		if(Classify(pManager->CopyFigList()[i])==1)
			COUNTRED++;
		else if(Classify(pManager->CopyFigList()[i])==2)
			COUNTBLUE++;
		else if(Classify(pManager->CopyFigList()[i])==3)
			COUNTGREEN++;
		else if(Classify(pManager->CopyFigList()[i])==4)
			COUNTWHILE++;
		else if(Classify(pManager->CopyFigList()[i])==5)
			COUNTBLACK++;
		else if(Classify(pManager->CopyFigList()[i])==6)
			COUNTGREY++;
	}
	if(Classify(Random())==1)
		return COUNTRED;
	if(Classify(Random())==2)
		return COUNTBLUE;
	if(Classify(Random())==3)
		return COUNTGREEN;
	if(Classify(Random())==4)
		return COUNTWHILE;
	if(Classify(Random())==5)
		return COUNTBLACK;
	if(Classify(Random())==6)
		return COUNTGREY;
	
}
