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

Action* Changecolor::Clone()
{
	return new Changecolor(*this);
}

void Changecolor::Undo()
{

}

void Changecolor::Redo()
{
}
