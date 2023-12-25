#include "ClearAll.h"

ClearAll::ClearAll(ApplicationManager* pApp) : Action(pApp) {}
void ClearAll::ReadActionParameters(){}
void ClearAll::Execute()
{
	pManager->Clearall();
	ClearRecord.open("Last Record", ios::trunc);
	ClearRecord.close();
	pManager->ClearRedoList();
	pManager->ClearUndoList();
	UI.DrawColor = BLUE;
	UI.FillColor = GREEN;
	UI.ISFILLED = false;
	UI.HexagonSize = 100;
	UI.SqrSize = 160;
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
