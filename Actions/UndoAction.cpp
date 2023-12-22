#include "UndoAction.h"

UndoAction::UndoAction(ApplicationManager* pApp, Action* A) :Action(pApp)
{
	ReturnedAction = NULL;
}

void UndoAction::ReadActionParameters()
{
	ReturnedAction = pManager->ReturnLastUndoableAction();
}

void UndoAction::Execute()
{
	ReadActionParameters();
	if (ReturnedAction == NULL)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("No actions to undo");
	}
	else {
		ReturnedAction->Undo();
		pManager->AddToRedo(ReturnedAction);
	}
}
Action* UndoAction::Clone()
{
	return new UndoAction(*this);
}

void UndoAction::Undo()
{
}

void UndoAction::Redo()
{
}
