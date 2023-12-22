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
	if (pFig)
	{
		int IX, IY, ix, iy;
		Point C = pFig->ReturnCenter();
		while (true)
		{
			if (pIn->isClicked(IX, IY))
			{
				pIn->isClicked(ix, iy);
				break;
			}
		}
		while (pIn->isClicked(IX, IY))
		{
			if (pFig)
			{
				if (pFig->IsInsideFigure(IX, IY))
				{
					NewCenter.x = IX + C.x - ix;
					NewCenter.y = IY + C.y - iy;
					pFig->Move(NewCenter);
				}
				Sleep(1);
				pManager->UpdateInterface();
				if (!pIn->isClicked(NewCenter.x, NewCenter.y))
					break;
			}
		}
		pManager->deselectall();
		pManager->RecordFigure(pFig);
		pOut->ClearStatusBar();
	}
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

