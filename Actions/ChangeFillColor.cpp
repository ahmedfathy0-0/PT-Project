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
			if (pOut->getCrntFillColor() == pFig->CGetFillClr()) {
				pFig->setisFilled(false);
				pOut->setisFilled(false);
			}
			else
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
	pFig->ChngFillClr(pOut->getOldFillColor());
}

void ChangeFillcolor::Redo()
{
	pFig->ChngFillClr(pOut->getCrntFillColor());
}
