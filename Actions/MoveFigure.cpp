#include "MoveFigure.h"

MoveAction::MoveAction(ApplicationManager* pApp) : Action(pApp) {


}

void MoveAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pFig = pManager->GetSelectedFigure();

		if (pFig) {
			pOut->PrintMessage("Click on Where You Want to Move");
			pIn->GetPointClicked(NewCenter.x, NewCenter.y);
		}
		else
			pOut->PrintMessage("Please select Figure first");
	}




void MoveAction::Execute()
{

	ReadActionParameters();
	if(pFig)
	    pFig->Move(NewCenter);
	pManager->deselectall();
	pOut->ClearStatusBar();
	}
Action* MoveAction::Clone()
{
	return new MoveAction(*this);
}

void MoveAction::Undo()
{
	if (pFig)
	{
		Point Center = pFig->ReturnOldCenter();
		pFig->Move(Center);
	}
	pManager->RecordFigure(pFig);

}

void MoveAction::Redo()
{
	if (pFig)
	{
		Point Center = pFig->ReturnOldCenter();
		pFig->Move(Center);
	}
	pManager->RecordFigure(pFig);

}

