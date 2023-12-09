#include "DeleteAction.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp) {}
void DeleteAction::ReadActionParameters(){}
void DeleteAction::Execute()
{
	pManager->deletefigure();
}
