#include "SwitchToDrawAction.h"
SwitchToDrawAction::SwitchToDrawAction(ApplicationManager* pApp) :Action(pApp)
{
	UI.InterfaceMode == MODE_DRAW;
}

void SwitchToDrawAction::ReadActionParameters()
{

}
void SwitchToDrawAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
	pOut->CreateDrawToolBar();
	UI.InterfaceMode == MODE_DRAW;
	pManager->UnHideFigures();
}
Action* SwitchToDrawAction::Clone()
{
	return new SwitchToDrawAction(*this);
}

void SwitchToDrawAction::Undo()
{
}

void SwitchToDrawAction::Redo()
{
}
