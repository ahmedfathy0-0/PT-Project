#include "RedoAction.h"

RedoAction::RedoAction(ApplicationManager* pApp, Action* A) :Action(pApp)
{
	ReturnedAction = NULL;
}

void RedoAction::ReadActionParameters()
{
	ReturnedAction = pManager->ReturnLastRedoableAction();
}

void RedoAction::Execute()
{
	ReadActionParameters();
	if (ReturnedAction == NULL)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No actions to redo");
	}
	else {
		ReturnedAction->Redo();
		pManager->AddAction(ReturnedAction);
		delete ReturnedAction;
		ReturnedAction = NULL;
	}
}

Action* RedoAction::Clone()
{
	return new RedoAction(*this);
}

void RedoAction::Undo()
{
}

void RedoAction::Redo()
{
}
