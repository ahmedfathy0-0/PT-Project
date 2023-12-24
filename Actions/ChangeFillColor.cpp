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
			if (pOut->getCrntFillColor() == pFig->CGetFillClr()) {
				pFig->setisFilled(false);
				pOut->setisFilled(false);
			}
			else
				pFig->ChngFillClr(pOut->getCrntFillColor());
			pManager->deselectall();
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
	pManager->RecordFigure(pFig);
}

void ChangeFillcolor::Redo()
{
	if (pFig) {
		pFig->ChngFillClr(pOut->getCrntFillColor());
	}
	pManager->RecordFigure(pFig);
}
