#include "SwitchToPlayAction.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp) :Action(pApp)
{

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
