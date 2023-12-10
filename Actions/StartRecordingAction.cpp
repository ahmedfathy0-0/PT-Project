
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
	fout.open(filename, ios::trunc);
	fout << getClr(UI.DrawColor) << "     " << getClr(UI.FillColor) << endl;
	fout << pManager->GetFigCount() << endl;
	pManager->StartRecord(filename);
	fout.close();
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

