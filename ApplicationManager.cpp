#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\Select.h"
#include "Actions\ChangeDrawCLR.h"
#include "Actions\ChangeFillCLR.h"
#include "Figures\CCircle.h"
#include "Figures\CLine.h"
#include "Figures\CRectangle.h"
#include "Figures\CTriangle.h"	
#include "Actions\DeleteAction.h"
#include "Actions\Pickbytype.h"
#include "Actions\Pickbycolor.h"
#include "Actions\Picktypecolor.h"
#include "Actions\saveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\Game.h"
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Paste.h"
#include "Actions\ToDrawMode.h"
#include "Actions\Rotate.h"
#include "Actions\Resize.h"
#include "Actions\Exit.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	SelFigCount=0;	
	ClipBoardCount = 0;
	FillCond = false;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
	{
		FigList[i] = NULL;
		SelectedFig[i]=NULL;
		Clipboard[i] = NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;
			///create AddLineAction here

		case DRAW_CIRC:
			pAct = new AddCircleAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case SELECT:
			pAct = new Select(this);
			break;

		case COPY:
			pAct = new Copy(this);
			break;
		case SAVE:
			pAct = new saveAction(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;

		case PASTE:
			pAct = new Paste(this);
			break;

		case DEL:
			pAct = new DeleteAction(this);
			break;

		case CHNG_DRAW_CLR :
			pAct = new ChangeDrawCLR (this);
			break;

		case CHNG_FILL_CLR :
			pAct = new ChangeFillCLR (this);
			break;
		case TO_PLAY :
			pAct = new Game (this);
			break;

		case PICKTYPE:
			pAct=new Pickbytype(this);
			break;

		case PICKCOLOR:
			pAct=new Pickbycolor(this);
			break;

		case PICKTYPECOLOR:
			pAct=new Picktypecolor(this);
			break;
		case TO_DRAW:
			pAct=new ToDrawMode(this);
			break;

		case ROTATE:
			pAct = new Rotate(this);
			break;

		case RESIZE_BIG:
			pAct = new Resize(this, true);
			break;

		case RESIZE_SMALL:
			pAct = new Resize(this, false);
			break;

		case EXIT:
			pAct = new Exit(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
	{
		FigList[FigCount] = pFig;	
		pFig->SetID(++FigCount);
	}
		
	if (FillCond)
		pFig->ChngFillClr(UI.FillColor);
}
void ApplicationManager :: SetFillCond (bool b)
{
	FillCond = b;
}
void ApplicationManager::saveAll(ofstream &filename)
{
	filename << FigCount << endl;
	for (int i = 0; i<FigCount; i++)
	{
		FigList[i]->Save(filename);
	}
}
void ApplicationManager::resetcount()
{
	pOut->ClearDrawArea();
	//pOut->PrintMessage("file loaded succesfully");
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) 
{
		for (int i=FigCount-1; i>=0; i--)
	{
		if (FigList[i]->select(x,y,pOut))
		{
			if (FigList[i]->IsSelected())
			{
				SelectedFig[SelFigCount]=FigList[i];
				return SelectedFig[SelFigCount++];
			}
				
			else
			{
				for (int j=0; j<SelFigCount; j++)
				{
					if (FigList[i]==SelectedFig[j])
					{
						SelectedFig[j]=NULL;
						SelectedFig[j]=SelectedFig[--SelFigCount];
						return NULL;
					}
				}
			}
		}
		}
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	return NULL;
}
CFigure ** ApplicationManager::GetClipboard()
{
	return Clipboard;
}
int ApplicationManager::GetClipboardCount()
{
	return ClipBoardCount;
}
void ApplicationManager::ClearClipboard()
{
	for (int i = 0; i < ClipBoardCount; ++i) {
		delete Clipboard[i];
		Clipboard[i] = NULL;
	}
	ClipBoardCount = 0;
}
void ApplicationManager::AddToClipboard()
{
	ClipBoardCount = SelFigCount;
	for (int i = 0; i < SelFigCount; ++i) {
		Clipboard[i] = SelectedFig[i]->CopyFig();
	}
}

void ApplicationManager :: FigToNULL (CFigure* pFig)
{
	for (int i=0; i<FigCount; i++)
		if (FigList[i]==pFig)
			FigList[i]=NULL;
}
void ApplicationManager :: DeleteFigure ()
{ 
	int b = FigCount - 1;
	for (int i=0; i<b; i++)
	{
		if (FigList[i]==NULL)
		{
			for (int j=i; j<FigCount-1; j++)
			{
				FigList[j]=FigList[j+1];
			}
			FigList[FigCount - 1]=NULL;
			--b;
		}
		if (FigList[i] != NULL)
			FigList[i]->SetID(i + 1);
		else
			--i;
	}
	FigCount-=SelFigCount;
	SelFigCount=0;
}

CFigure ** ApplicationManager :: GetSelFigList ()
{
	return SelectedFig;
}
int ApplicationManager :: GetSelFigCount ()
{
	return SelFigCount ;
}
void ApplicationManager :: SetSelFigCount(int n)
{
	SelFigCount = n;
}
//Play mode
CFigure**ApplicationManager::CopyFigList()
{
	return FigList;
}
string ApplicationManager::colortoname(color sample)
{
	if (sample == BLACK)
		return "BLACK";
	else if (sample == WHITE)
		return "WHITE";
	else if (sample == GREY)
		return "GREY";
	else if (sample == GREEN)
		return "GREEN";
	else if (sample == RED)
		return "RED";
	else if (sample == BLUE)
		return "BLUE";
	else
	{/*do nothing*/
	}
}
color ApplicationManager::nametocolor(string sample) {
	if (sample == "BLACK")
		return BLACK;
	else if (sample == "WHITE")
		return WHITE;
	else if (sample == "GREY")
		return GREY;
	else if (sample == "GREEN")
		return GREEN;
	else if (sample == "RED")
		return RED;
	else if (sample == "BLUE")
		return BLUE;
	else
	{/*do nothing*/
	}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	if (pOut != NULL){
		for(int i=0; i<FigCount; i++)
			FigList[i]->Draw(pOut);
	 
			if (UI.InterfaceMode == MODE_DRAW)
				pOut->CreateDrawToolBar();
			else
				pOut->CreatePlayToolBar();
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

void ApplicationManager::SetpOutToNull()
{
	pOut = NULL;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	
}
