#include "SwitchToPlayAction.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp) :Action(pApp)
{
	UI.InterfaceMode == MODE_PLAY;
}

void SwitchToPlayAction::ReadActionParameters()
{

}

void SwitchToPlayAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
	pOut->CreatePlayToolBar();
}

Action* SwitchToPlayAction::Clone()
{
	return new SwitchToPlayAction(*this);
}

void SwitchToPlayAction::Undo()
{
}

void SwitchToPlayAction::Redo()
{
}
