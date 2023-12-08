#include "SelectOneAction.h"

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
	SelectedFig = pManager->GetFigure(P.x, P.y);
	if (SelectedFig != NULL) {
		if (SelectedFig->IsSelected())
			UnSelect();
		else Select();
	}
}

void SelectOneAction::Select() 
{
	SelectedFig->SetSelected(true);
	Output* pOut = pManager->GetOutput();
	//SelectedFig->PrintInfo(pOut);
	SelectedFig->ChngDrawClr(UI.HighlightColor);
}

void SelectOneAction::UnSelect() {
	SelectedFig->SetSelected(false);
	SelectedFig->ChngDrawClr(BLACK);
	SelectedFig = NULL;
}