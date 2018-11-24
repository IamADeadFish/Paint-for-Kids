#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H



#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int SelFigCount;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	bool FillCond;
	CFigure* SelectedFig[MaxFigCount]; //Pointer to the selected figure

	CFigure* Clipboard[MaxFigCount];   //Pointer to the copied/cut figure
	int ClipBoardCount;
	
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	CFigure  ** GetSelFigList();
	void FigToNULL (CFigure * );
	int GetSelFigCount();
	void SetSelFigCount(int n);
	void SetFillCond (bool);
	string colortoname(color sample);
	color nametocolor(string sample);
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) ; //Search for a figure given a point inside the figure
	void DeleteFigure();

	//Play Mode
	CFigure** CopyFigList(); 


	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	int GetClipboardCount();
	void saveAll(ofstream &filename);
	void resetcount();
	CFigure ** GetClipboard();
	void AddToClipboard();
	void ClearClipboard();
	void SetpOutToNull();
};

#endif