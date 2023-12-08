#include "SelectOneAction.h"
#include "iostream"
using namespace std;

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
	pManager->SetSelectedFigure(pManager->GetFigure(P.x, P.y));
	if (pManager->GetSelectedFigure() != NULL) {
		if (pManager->GetSelectedFigure()->IsSelected()) pManager->GetSelectedFigure()->SetSelected(false);
		else {
			pManager->deselectall();
			pManager->GetSelectedFigure()->SetSelected(true);
			//pManager->GetSelectedFigure()->PrintInfo(pOut);
		}
	}
}