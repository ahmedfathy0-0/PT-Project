#include "ResizeAction.h"

ResizeAction::ResizeAction(ApplicationManager* pApp) : Action(pApp) {


}

void ResizeAction::ReadActionParameters()
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




void ResizeAction::Execute()
{
	ReadActionParameters();
	bool flag = false;//used to first get checked is in the figure or not after that u can move out the figure
	int IX, IY, ix, iy;
	pIn->isClicked(ix, iy);
	while (true)
	{
		if (pIn->isClicked(IX, IY))
			if (pFig)
			{
				if (pFig->IsInsideFigure(IX, IY)||flag==true)
				{
					NewCenter.x = IX;
					NewCenter.y = IY;
					pFig->Resize(NewCenter);
				}
				Sleep(10);
				pManager->UpdateInterface();
				if (!pIn->isClicked(NewCenter.x, NewCenter.y))
					break;
				flag = true;
			}
	}
	pManager->deselectall();
	pManager->RecordFigure(pFig);
	pOut->ClearStatusBar();
}

Action* ResizeAction::Clone()
{
//	return new ResizeAction(*this);
	return NULL;
}

void ResizeAction::Undo()
{
	if (pFig)
	{
		Point Center = pFig->ReturnOldCenter();
		pFig->Move(Center);
	}
}

void ResizeAction::Redo()
{
	if (pFig)
	{
		Point Center = pFig->ReturnOldCenter();
		pFig->Move(Center);
	}
}

