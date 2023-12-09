#include "ClearAll.h"

ClearAll::ClearAll(ApplicationManager* pApp) : Action(pApp) {}
void ClearAll::ReadActionParameters(){}
void ClearAll::Execute()
{
	pManager->Clearall();
	UI.DrawColor = BLUE;
	UI.FillColor = GREEN;
	UI.ISFILLED = false;
}
