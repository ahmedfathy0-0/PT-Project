
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
	fout.open(filename, ios::trunc);
	pManager->SaveAll(fout);
	fout.close();
}


