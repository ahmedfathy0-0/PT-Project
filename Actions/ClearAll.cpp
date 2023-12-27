#include "ClearAll.h"

ClearAll::ClearAll(ApplicationManager* pApp) : Action(pApp) {}
void ClearAll::ReadActionParameters(){}
void ClearAll::Execute()
{
	if (pManager->getIsRecording()) //check if recording is started or not to stop it
		pManager->StopRecord();
	ClearRecord.open("Last Record", ios::trunc); //clear recording
	ClearRecord.close();
	pManager->Clearall(); //clear all figures
	pManager->ClearRedoList(); //clear redo history
	pManager->ClearUndoList(); //clear undo history
	pManager->ResetConstants(); //reset UI constants

}

Action* ClearAll::Clone()
{
	return nullptr;
}

void ClearAll::Undo()
{
}

void ClearAll::Redo()
{
}
