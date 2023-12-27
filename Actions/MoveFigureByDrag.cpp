#include "MoveFigureByDrag.h"

MoveDragAction::MoveDragAction(ApplicationManager* pApp) : Action(pApp) {


}

void MoveDragAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pFig = pManager->GetSelectedFigure();
}




void MoveDragAction::Execute()
{
	ReadActionParameters();
	if (pFig == NULL) //check if there is a selected figure or not
		pOut->PrintMessage("Please select Figure first");
	else
	{
		pOut->PrintMessage("Click on The Figure and Drag");
		bool MoveCondition = false;
		/*
		used to first get checked is in the figure or not
		after you can move out the figure
		*/
		int IX, IY; //IX,IY is the last point the mouse point at when clicked
		int ix, iy; //ix,iy is the first point the mouse point at when clicked
		C = pFig->ReturnCenter(); //get center for calculations of new center
		while (true) //get the first click
		{
			if (pIn->isClicked(ix, iy))
				break;
		}
		if (!pFig->IsInsideFigure(ix, iy)) //checks if the point you drag from is inside the shape
			pOut->PrintMessage("Please select point on the figure");
		else
			while (pIn->isClicked(IX, IY))
			{
				if (pFig)
				{
					if (pFig->IsInsideFigure(IX, IY) || MoveCondition)
					{
						NewCenter.x = IX + C.x - ix;
						NewCenter.y = IY + C.y - iy;
						pManager->UpdateBuffer(true);
						pManager->UpdateInterface();
						pFig->Move(NewCenter);
					}
					MoveCondition = true;
					if (!pIn->isClicked(NewCenter.x, NewCenter.y))
						break;
				}
			}
		pManager->UpdateBuffer(false);
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
		pFig->Move(C);
	}
	pManager->RecordFigure(pFig);

}

void MoveDragAction::Redo()
{
	if (pFig)
	{
		pFig->Move(NewCenter);
	}
	pManager->RecordFigure(pFig);

}

bool MoveDragAction::IsUndoable()
{
	return true;
}

