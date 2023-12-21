#include "DeleteAction.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp) {}
void DeleteAction::ReadActionParameters(){}
void DeleteAction::Execute()
{
	//pManager->deletefigure();
	if (pManager->GetSelectedFigure() != NULL)
	{
		pManager->GetSelectedFigure()->SetHidden(true);
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
