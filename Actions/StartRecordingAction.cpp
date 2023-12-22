
#include "StartRecordingAction.h"

StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) : Action(pApp) {}

void StartRecordingAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	filename = "Last Record";
	pOut->ClearStatusBar();
}

void StartRecordingAction::Execute()
{
	ReadActionParameters();
	pManager->StartRecord(filename);

}
Action* StartRecordingAction::Clone()
{
	return NULL;
}
void StartRecordingAction::Undo()
{
}
void StartRecordingAction::Redo()
{
}
string StartRecordingAction::getClr(color Dclr)
{
	if (Dclr == BLACK)
		return "BLACK";
	else if (Dclr == YELLOW)
		return "YELLOW";
	else if (Dclr == ORANGE)
		return "ORANGE";
	else if (Dclr == RED)
		return "RED";
	else if (Dclr == GREEN)
		return "GREEN";
	else if (Dclr == BLUE)
		return "BLUE";
}


