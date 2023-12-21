#include "PickAndHideAction.h"
PickAndHideAction::PickAndHideAction(ApplicationManager* pApp) :Action(pApp)
{

}

void PickAndHideAction::ReadActionParameters()
{

}

void PickAndHideAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Action:Pick and Hide. Choose an Option");
	pOut->CreatePickAndHideToolbar();
	UI.conDforPicknHide = true;
}

Action* PickAndHideAction::Clone()
{
	return new PickAndHideAction(*this);
}

void PickAndHideAction::Undo()
{
}

void PickAndHideAction::Redo()
{
}

