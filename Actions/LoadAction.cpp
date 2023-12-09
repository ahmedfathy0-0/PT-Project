#include "LoadAction.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp) {}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter name of the file you want to load from");
	filename = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	pManager->Clearall();
	ReadActionParameters();
	fIn.open("Saved/" + filename);
	fIn >> type;
	UI.DrawColor = getclr(type);
	fIn >> type;
	UI.FillColor = getclr(type);
	fIn >> NO_OF_FIGS;
	CFigure* myFig = NULL;
	for (int i = 0; i < NO_OF_FIGS; i++)
	{
		fIn >> type;
		if (type == "RECTAN")
			myFig = new CRectangle;
		else if (type == "SQUARE")
			myFig = new CSquare;
		else if (type == "TRIANG")
			myFig = new CTriangle;
		else if (type == "HEXAGN")
			myFig = new CHexagon;
		else if (type == "CIRCLE")
			myFig = new CCircle;
		myFig->Load(fIn);
		pManager->AddFigure(myFig);
	}
}

color LoadAction::getclr(string colour)
{
	if (colour == "BLACK")
		return BLACK;
	else if (colour == "YELLOW")
		return YELLOW;
	else if (colour == "ORANGE")
		return ORANGE;
	else if (colour == "RED")
		return RED;
	else if (colour == "GREEN")
		return GREEN;
	else if (colour == "BLUE")
		return BLUE;
}

