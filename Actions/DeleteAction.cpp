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
	pManager->deletefigure(pFig);
	pManager->AddToDeleteList(pFig);
}

Action* DeleteAction::Clone()
{
	return new DeleteAction(*this);
}

void DeleteAction::Undo()
{
	if (pFig)
	{
		pManager->AddFigure(pFig);
	}
	pManager->RecordFigure(pFig);

}

void DeleteAction::Redo()
{
	if (pFig)
	{
		pManager->deletefigure(pFig);
	}
	pManager->RecordFigure(pFig);
}
