#include "ChangeFillColor.h"

ChangeFillcolor::ChangeFillcolor(ApplicationManager* pApp) : Action(pApp) {}

void ChangeFillcolor::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pFig = pManager->GetSelectedFigure();
}

void ChangeFillcolor::Execute()
{
	ReadActionParameters();

	if (pFig != NULL) {
	     	pFig->SetSelected(false);
			pFig->ChngFillClr(pOut->getCrntFillColor());
			pManager->RecordFigure(pFig);
	}

}

Action* ChangeFillcolor::Clone()
{
	return new ChangeFillcolor(*this);
}

void ChangeFillcolor::Undo()
{
	if (pFig)
	{
		pFig->ChngFillClr(pOut->getOldFillColor());
		if (pOut->getOldFillColor() == GHOSTWHITE)
		{
			pFig->SetIsFilled(false);
		}
	}
}

void ChangeFillcolor::Redo()
{
	if (pFig) {
		pFig->ChngFillClr(pOut->getCrntFillColor());
	}
}
