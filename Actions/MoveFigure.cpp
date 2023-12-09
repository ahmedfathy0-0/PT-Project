#include "MoveFigure.h"

MoveAction::MoveAction(ApplicationManager* pApp) : Action(pApp) {}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on Where You Want to Move");

	pIn->GetPointClicked(NewCenter.x, NewCenter.y);
	pOut->ClearStatusBar();
}

void MoveAction::Execute()
{
	ReadActionParameters();
	pManager->movefigure(NewCenter);
}
