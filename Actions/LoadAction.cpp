#include "LoadAction.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp) {}

void LoadAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMessage("Enter name of the file you want to load from");
	filename = pIn->GetString(pOut);
	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	ReadActionParameters();
	pManager->ResetConstants();//reset Sizes of Hexagon and Square
	fIn.open("Saved/" + filename);
	if (fIn.is_open())
	{
		pManager->Clearall(); //clear before loading
		pOut->PrintMessage("The File  '" + filename + "'  is Opened");
		fIn >> type;
		UI.DrawColor = getclr(type);
		fIn >> fillcolor;
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
		if (fillcolor != "NO_FILL")
		{
			UI.ISFILLED = true;
			UI.FillColor = getclr(fillcolor);
		}
		else
		{
			UI.ISFILLED = false;
			UI.FillColor = GREEN;
		}
	}
	else
		pOut->PrintMessage("File Not Found, Please type Name of File again");
	pManager->ClearRedoList();
	pManager->ClearUndoList();
	pManager->ClearDeleteList();
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

Action* LoadAction::Clone()
{
	return NULL;
}

void LoadAction::Undo()
{

}

void LoadAction::Redo()
{
}

bool LoadAction::IsUndoable()
{
	return false;
}

