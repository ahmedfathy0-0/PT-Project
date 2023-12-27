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

	if (pFig != NULL)
	{
		OldColor = pFig->CGetDrawClr();
		pFig->ChngDrawClr(pOut->getCrntDrawColor());
		NewColor = pFig->CGetDrawClr();
		pManager->deselectall();
	}

}

Action* ChangeDrawcolor::Clone()
{
	return new ChangeDrawcolor(*this);
}

void ChangeDrawcolor::Undo()
{
	if (pFig)
	{
		pFig->ChngDrawClr(OldColor);
		OldColor = NewColor;
		NewColor = pFig->CGetDrawClr();
	}
		pManager->RecordFigure(pFig);
}

void ChangeDrawcolor::Redo()
{
	if (pFig) 
	{
		pFig->ChngDrawClr(OldColor);
		OldColor = NewColor;
		NewColor = pFig->CGetDrawClr();
	}
	pManager->RecordFigure(pFig);
}

bool ChangeDrawcolor::IsUndoable()
{
	return true;
}
