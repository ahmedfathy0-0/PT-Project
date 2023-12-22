#include "DeleteAction.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp) {}
void DeleteAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pFig = pManager->GetSelectedFigure();
	if (pFig == NULL())
		pOut->PrintMessage("Please select Figure first");
	else
		pOut->PrintMessage("Figure Deleted");
}
void DeleteAction::Execute()
{
	ReadActionParameters();
	//pManager->deletefigure();
	if (pFig != NULL)
	{
		pFig->SetHidden(true);
	}
}

Action* DeleteAction::Clone()
{
	return new DeleteAction(*this);
}

void DeleteAction::Undo()
{
	if (pManager->GetSelectedFigure() != NULL)
	{
		pManager->GetSelectedFigure()->SetHidden(false);
	}
}

void DeleteAction::Redo()
{
	if (pManager->GetSelectedFigure() != NULL)
	{
		pManager->GetSelectedFigure()->SetHidden(true);
	}
}
