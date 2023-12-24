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
		
			pFig->ChngDrawClr(pOut->getCrntDrawColor());
			pManager->deselectall();

	}

}

Action* ChangeDrawcolor::Clone()
{
	return new ChangeDrawcolor(*this);
}

void ChangeDrawcolor::Undo()
{
	pFig->ChngDrawClr(pOut->getOldDrawColor());
}

void ChangeDrawcolor::Redo()
{
	pFig->ChngDrawClr(pOut->getCrntDrawColor());
}
