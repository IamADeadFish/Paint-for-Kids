#include "Pickbytype.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "Picktypecolor.h"

Picktypecolor::Picktypecolor(ApplicationManager * pApp):Game(pApp),CntCorrect(0),CntInCorrect(0)
{}
void Picktypecolor::Execute()
{
	autoload();
	pManager->UpdateInterface();
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int Counter=CountFigList();
	int Count=CountTypeColor();
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
				// if user clicked on shape
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

void Picktypecolor::ReadActionParameters()
{
		//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(Display());
}

int Picktypecolor::CountTypeColor()
{
	int COUNTREDREC=0;
	int COUNTREDCIRC=0;
	int COUNTREDTRI=0;
	int COUNTBLUEREC=0;
	int COUNTBLUECIRC=0;
	int COUNTBLUETRI=0;
	int COUNTGREENREC=0;
	int COUNTGREENCIRC=0;
	int COUNTGREENTRI=0;
	int COUNTWHITEREC=0;
	int COUNTWHITECIRC=0;
	int COUNTWHITETRI=0;
	int COUNTBLACKREC=0;
	int COUNTBLACKCIRC=0;
	int COUNTBLACKTRI=0;
	int COUNTGREYREC=0;
	int COUNTGREYCIRC=0;
	int COUNTGREYTRI=0;
	int COUNTREDLINE=0;
	int COUNTBLUELINE=0;
	int COUNTGREENLINE=0;
	int COUNTWHITELINE=0;
	int COUNTGREYLINE=0;
	int COUNTBLACKLINE=0;
	if(Classify(Random())==-1||(Classify(Random())==-2))
		return 0;
	for(int i=0;i<CountFigList();i++)
	{
		if(Classify(pManager->CopyFigList()[i])==1)
			COUNTREDREC++;
		else if(Classify(pManager->CopyFigList()[i])==2)
			COUNTREDCIRC++;
		else if(Classify(pManager->CopyFigList()[i])==3)
			COUNTREDTRI++;
		else if(Classify(pManager->CopyFigList()[i])==4)
			COUNTBLUEREC++;
		else if(Classify(pManager->CopyFigList()[i])==5)
			COUNTBLUECIRC++;
		else if(Classify(pManager->CopyFigList()[i])==6)
			COUNTBLUETRI++;
		else if(Classify(pManager->CopyFigList()[i])==7)
			COUNTGREENREC++;
		else if(Classify(pManager->CopyFigList()[i])==8)
			COUNTGREENCIRC++;
		else if(Classify(pManager->CopyFigList()[i])==9)
			COUNTGREENTRI++;
		else if(Classify(pManager->CopyFigList()[i])==10)
			COUNTWHITEREC++;
		else if(Classify(pManager->CopyFigList()[i])==11)
			COUNTWHITECIRC++;
		else if(Classify(pManager->CopyFigList()[i])==12)
			COUNTWHITETRI++;
		else if(Classify(pManager->CopyFigList()[i])==13)
			COUNTBLACKREC++;
		else if(Classify(pManager->CopyFigList()[i])==14)
			COUNTBLACKCIRC++;
		else if(Classify(pManager->CopyFigList()[i])==15)
			COUNTBLACKTRI++;
		else if(Classify(pManager->CopyFigList()[i])==16)
			COUNTGREYREC++;
		else if(Classify(pManager->CopyFigList()[i])==17)
			COUNTGREYCIRC++;
		else if(Classify(pManager->CopyFigList()[i])==18)
			COUNTGREYTRI++;
		else if(Classify(pManager->CopyFigList()[i])==19)
			COUNTREDLINE++;
		else if(Classify(pManager->CopyFigList()[i])==20)
			COUNTBLUELINE++;
		else if(Classify(pManager->CopyFigList()[i])==21)
			COUNTGREENLINE++;
		else if(Classify(pManager->CopyFigList()[i])==22)
			COUNTWHITELINE++;
		else if(Classify(pManager->CopyFigList()[i])==23)
			COUNTBLACKLINE++;
		else if(Classify(pManager->CopyFigList()[i])==24)
			COUNTGREYLINE++;

	}
	if(Classify(Random())==1)
		return COUNTREDREC;
	if(Classify(Random())==2)
		return COUNTREDCIRC;
	if(Classify(Random())==3)
		return COUNTREDTRI;
	if(Classify(Random())==4)
		return COUNTBLUEREC;
	if(Classify(Random())==5)
		return COUNTBLUECIRC;
	if(Classify(Random())==6)
		return COUNTBLUETRI;
	if(Classify(Random())==7)
		return COUNTGREENREC;
	if(Classify(Random())==8)
		return COUNTGREENCIRC;
	if(Classify(Random())==9)
		return COUNTGREENTRI;
	if(Classify(Random())==10)
		return COUNTWHITEREC;
	if(Classify(Random())==11)
		return COUNTWHITECIRC;
	if(Classify(Random())==12)
		return COUNTWHITETRI;
	if(Classify(Random())==13)
		return COUNTBLACKREC;
	if(Classify(Random())==14)
		return COUNTBLACKCIRC;
	if(Classify(Random())==15)
		return COUNTBLACKTRI;
	if(Classify(Random())==16)
		return COUNTGREYREC;
	if(Classify(Random())==17)
		return COUNTGREYCIRC;
	if(Classify(Random())==18)
		return COUNTGREYTRI;
	if(Classify(Random())==19)
		return COUNTREDLINE;
	if(Classify(Random())==20)
		return COUNTBLUELINE;
	if(Classify(Random())==21)
		return COUNTGREENLINE;
	if(Classify(Random())==22)
		return COUNTWHITELINE;
	if(Classify(Random())==23)
		return COUNTBLACKLINE;
	if(Classify(Random())==24)
		return COUNTGREYLINE;

}
string Picktypecolor::Display()
{
	switch (Classify(Random()))
	{
	case -1:
		return "Please Draw Something To PLay This Mode"; //empty
		break;
	case -2:
		return "PLease Color Any Shape To Play this Mode ";
		break;
	case 1:
		return "PLease PickbyTypeaAndColor ::Red Rectangle";
		break;
	case 2:
		return "PLease PickbyTypeaAndColor ::Red Circle";
		break;
	case 3:
		return "Please PickbyTypeaAndColor ::Red Triangle" ;
		break;
	case 4:
		return "PLease PickbyTypeaAndColor ::BLUE Rectangle ";
		break;
	case 5:
		return "PLease PickbyTypeaAndColor ::BLUE Circle ";
		break;
	case 6:
		return "PLease PickbyTypeaAndColor ::BLUE Triangle ";
		break;
	case 7:
		return "PLease PickbyTypeaAndColor ::GREEN Rectangle ";
		break;
	case 8:
		return "PLease PickbyTypeaAndColor ::GREEN Circle ";
		break;
	case 9:
		return "PLease PickbyTypeaAndColor ::GREEN Triangle ";
		break;
	case 10:
		return "PLease PickbyTypeaAndColor ::WHITE Rectangle ";
		break;
	case 11:
		return "PLease PickbyTypeaAndColor ::WHITE Circle ";
		break;
	case 12:
		return "PLease PickbyTypeaAndColor ::WHITE Triangle ";
		break;
	case 13:
		return "PLease PickbyTypeaAndColor ::BLACK Rectangle ";
		break;
	case 14:
		return "PLease PickbyTypeaAndColor ::BLACK Circle ";
		break;
	case 15:
		return "PLease PickbyTypeaAndColor ::BLACK Triangle ";
		break;
	case 16:
		return "PLease PickbyTypeaAndColor ::GREY Rectangle ";
		break;
	case 17:
		return "PLease PickbyTypeaAndColor ::GREY Circle ";
		break;
	case 18:
		return "PLease PickbyTypeaAndColor ::GREY Triangle ";
		break;
	case 19:
		return "PLease PickbyTypeaAndColor ::RED LINE ";
		break;
	case 20:
		return "PLease PickbyTypeaAndColor ::BLUE LINE ";
		break;
	case 21:
		return "PLease PickbyTypeaAndColor ::GREEN LINE ";
		break;
	case 22:
		return "PLease PickbyTypeaAndColor ::WHITE LINE ";
		break;
	case 23:
		return "PLease PickbyTypeaAndColor ::BLACK LINE ";
		break;
	case 24:
		return "PLease PickbyTypeaAndColor ::GREY LINE ";
		break;
	}
}
CFigure* Picktypecolor::Random()
{
	if(CountFigList()==0)
		return NULL; // figlis is empty
	for(int i=0;i<CountFigList();i++)
		if(pManager->CopyFigList()[i]->getisfilled())
			return pManager->CopyFigList()[i];
	return pManager->CopyFigList()[0];  // all figures are uncolored(NON-FILLED)
}
int Picktypecolor::Classify(CFigure* F)
{
	if(F==NULL&&CountFigList()==0)
		return -1;                         //figlist empty
	if((dynamic_cast<CLine*>(F))&&CountFigList()!=0)  //figlist is not colored //Choose DrawClr FOR LINE ONLY
	{
		if(F->GetDrawclr()==RED)
			return 19;
		if(F->GetDrawclr()==BLUE)
			return 20;
		if(F->GetDrawclr()==GREEN)
			return 21;
		if(F->GetDrawclr()==WHITE)
			return 22;
		if(F->GetDrawclr()==BLACK)
			return 23;
		if(F->GetDrawclr()==GREY)
			return 24;
	}
	if(F==NULL&&CountFigList()!=0)
		return -2;                
	if(((F->getfillclr())==RED)&&F->getisfilled())
	{

		if(dynamic_cast<CRectangle*>(F))
			return 1;
		if(dynamic_cast<CCircle*>(F))
			return 2;
		if(dynamic_cast<CTriangle*>(F))
			return 3;
	}
	if(((F->getfillclr())==BLUE)&&F->getisfilled())
	{
		if(dynamic_cast<CRectangle*>(F))
			return 4;
		if(dynamic_cast<CCircle*>(F))
			return 5;
		if(dynamic_cast<CTriangle*>(F))
			return 6;
	}
	if(((F->getfillclr())==GREEN)&&F->getisfilled())
	{
		if(dynamic_cast<CRectangle*>(F))
			return 7;
		if(dynamic_cast<CCircle*>(F))
			return 8;
		if(dynamic_cast<CTriangle*>(F))
			return 9;
	}
	if(((F->getfillclr())==WHITE)&&F->getisfilled())
	{
		if(dynamic_cast<CRectangle*>(F))
			return 10;
		if(dynamic_cast<CCircle*>(F))
			return 11;
		if(dynamic_cast<CTriangle*>(F))
			return 12;
	}
	if(((F->getfillclr())==BLACK)&&F->getisfilled())
	{
		if(dynamic_cast<CRectangle*>(F))
			return 13;
		if(dynamic_cast<CCircle*>(F))
			return 14;
		if(dynamic_cast<CTriangle*>(F))
			return 15;
	}
	if(((F->getfillclr())==GREY)&&F->getisfilled())
	{
		if(dynamic_cast<CRectangle*>(F))
			return 16;
		if(dynamic_cast<CCircle*>(F))
			return 17;
		if(dynamic_cast<CTriangle*>(F))
			return 18;
	}
	return -2;

}