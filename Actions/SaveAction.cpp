
#include "SaveAction.h"

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp) {}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter name of the file you want to save in");
	filename = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	fout.open("Saved/"+filename, ios::trunc);
	fout << getClr(UI.DrawColor) << "     " << getClr(UI.FillColor) << endl;
	fout << pManager->GetFigCount() << endl;
	pManager->SaveAll(fout);
	fout.close();
}
Action* SaveAction::Clone()
{
	return NULL;
}
void SaveAction::Undo()
{
}
void SaveAction::Redo()
{
}
string SaveAction::getClr(color Dclr)
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


