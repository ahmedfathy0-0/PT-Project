#include "MoveFigureByDrag.h"

MoveDragAction::MoveDragAction(ApplicationManager* pApp) : Action(pApp) {


}

void MoveDragAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pFig = pManager->GetSelectedFigure();

	if (pFig == NULL)
		pOut->PrintMessage("Please select Figure first");
	else if (pFig) {
		pOut->PrintMessage("Click on The Figure and Drag");
		//pIn->GetPointClicked(NewCenter.x, NewCenter.y);
	}
	}




void MoveDragAction::Execute()
{
	ReadActionParameters();
	int IX, IY,ix,iy;
	pIn->isClicked(ix, iy);
	while (true)
	{
		if (pIn->isClicked(IX, IY))
			if (pFig)
			{
				if (pFig->IsInsideFigure(IX, IY))
				{
					NewCenter.x = IX;
					NewCenter.y = IY;
					pFig->Move(NewCenter);
				}
				Sleep(10);
				pManager->UpdateInterface();
				if (!pIn->isClicked(NewCenter.x, NewCenter.y))
					break;
			}
	}
	pManager->deselectall();
	pManager->RecordFigure(pFig);
	pOut->ClearStatusBar();
	}

Action* MoveDragAction::Clone()
{
	return new MoveDragAction(*this);
}

void MoveDragAction::Undo()
{
	if (pFig)
	{
		Point Center = pFig->ReturnOldCenter();
		pFig->Move(Center);
	}
}

void MoveDragAction::Redo()
{
	if (pFig)
	{
		Point Center = pFig->ReturnOldCenter();
		pFig->Move(Center);
	}
}

