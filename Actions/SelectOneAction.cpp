#include "SelectOneAction.h"
#include "iostream"
using namespace std;
#include "..\Figures\CFigure.h"
SelectOneAction::SelectOneAction(ApplicationManager* pApp) :Action(pApp) {

}
void SelectOneAction::ReadActionParameters() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Action: Select One Action, Click anywhere to Higlight a figure and print its info");
	pIn->GetPointClicked(P.x, P.y);
	pOut->ClearStatusBar();

}

void SelectOneAction::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure* pFig = pManager->GetFigure(P.x, P.y);
	if (pFig != NULL) {
		if (pFig->IsSelected()) { pFig->SetSelected(false); }
		else {
			pManager->deselectall();
			pFig->SetSelected(true);
			pManager->SetSelectedFigure(pFig);
			pManager->GetSelectedFigure()->PrintInfo(pOut);
		}
	}
}

Action* SelectOneAction::Clone()
{
	return new SelectOneAction(*this);
}

void SelectOneAction::Undo()
{
}

void SelectOneAction::Redo()
{
}
