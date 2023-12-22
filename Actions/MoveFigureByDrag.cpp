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
		bool MoveCondition = false; 
		/*
		used to first get checked is in the figure or not
		after you can move out the figure
		*/
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
				if (pFig->IsInsideFigure(IX, IY)||MoveCondition)
				{
					NewCenter.x = IX + C.x - ix;
					NewCenter.y = IY + C.y - iy;
					pManager->UpdateBuffer(true);
					pOut->CreateDrawToolBar();
					pManager->UpdateInterface();
					pFig->Move(NewCenter);
				}
				Sleep(1);
				
				if (!pIn->isClicked(NewCenter.x, NewCenter.y))
					break;
				MoveCondition = true;
			}
		}
		pManager->UpdateBuffer(false);
		pManager->RecordFigure(pFig);
		pManager->deselectall();
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

