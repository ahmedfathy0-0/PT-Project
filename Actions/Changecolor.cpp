#include "Changecolor.h"

ChangeDrawcolor::ChangeDrawcolor(ApplicationManager* pApp) : Action(pApp){}

void ChangeDrawcolor::ReadActionParameters()
{
	 pOut = pManager->GetOutput();
	 pIn = pManager->GetInput();
	pFig = pManager->GetSelectedFigure();
}

void ChangeDrawcolor::Execute()
{					
	ReadActionParameters();

	if (pFig!=NULL) {
		pFig->SetSelected(false);
			pFig->ChngDrawClr(pOut->getCrntDrawColor());
			pManager->RecordFigure(pFig);

	}

}

Action* ChangeDrawcolor::Clone()
{
	return new ChangeDrawcolor(*this);
}

void ChangeDrawcolor::Undo()
{

}

void ChangeDrawcolor::Redo()
{
}
