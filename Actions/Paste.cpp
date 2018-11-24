#include "Paste.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>

Paste::Paste(ApplicationManager * pApp) :Action(pApp)
{}


void Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Please Click on the point you want to paste figures in ");

	pIn->GetPointClicked(Psecond.x, Psecond.y);
	pOut->ClearStatusBar();
}
void Paste::Execute()
{
	CFigure ** Clipboard;
	ReadActionParameters();
	Clipboard = pManager->GetClipboard();
	ClipBoardCount = pManager->GetClipboardCount();
	if (ClipBoardCount > 0) {
		Pfirst = GetCenter(Clipboard);
		TranslateFig(Clipboard);
		PasteFig(Clipboard);
	}
	else {
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("The clipboard is empty  ");
	}
	
}

Paste::~Paste()
{
}
Point Paste::GetCenter(CFigure ** F)
{
	Point p;
	p.x = 0;
	p.y = 0;
	double a = 0;
	for (int i = 0; i < ClipBoardCount; ++i)
		a += F[i]->GetArea();
	for (int i = 0; i < ClipBoardCount; ++i) {
		Point pp = F[i]->GetCenter();
		p.x += pp.x * int(F[i]->GetArea());
	}
	for (int i = 0; i < ClipBoardCount; ++i) {
		Point pp = F[i]->GetCenter();
		p.y += pp.y * int(F[i]->GetArea());
	}
	p.x /= int(a);
	p.y /= int(a);
	return p;
}
void Paste::PasteFig(CFigure ** Clipboard)
{
	for (int i = 0; i < ClipBoardCount; ++i) {
		CFigure * f = Clipboard[i]->CopyFig();
		pManager->AddFigure(f);
	}
}
void Paste::TranslateFig(CFigure ** Clipboard)
{
	int x, y;
	x = Psecond.x - Pfirst.x;
	y = Psecond.y - Pfirst.y;
	for (int i = 0; i < ClipBoardCount; ++i) {
		Clipboard[i]->TranslateFig(x, y);
	}
}
