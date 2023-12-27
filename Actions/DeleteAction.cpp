#include "DeleteAction.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp) {}
void DeleteAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pFig = pManager->GetSelectedFigure();
	if (pFig == NULL()) //check if there is a selected figure or not
		pOut->PrintMessage("Please select Figure first");
	else
		pOut->PrintMessage("Figure Deleted");
}
void DeleteAction::Execute()
{
	ReadActionParameters();
	pManager->AddToDeleteList(pFig); //for undo
	pManager->deletefigure(pFig); //delete selected figure
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
	pManager->RecordFigure(pFig);

	if (pFig)
	{
		pManager->deletefigure(pFig);
	}
}

bool DeleteAction::IsUndoable()
{
	return true;
}
