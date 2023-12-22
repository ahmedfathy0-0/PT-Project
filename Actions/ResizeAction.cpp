#include "ResizeAction.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;


ResizeAction::ResizeAction(ApplicationManager* pApp) :Action(pApp)
{

}

void ResizeAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	pFig = pManager->GetSelectedFigure();

}

//Execute the action
void ResizeAction::Execute()
{
	cout << pIn->GetMouseClicked(P1.x, P1.y) << endl;


	ReadActionParameters();
	if (pFig != NULL) {
		while (pIn->GetMouseClicked(P1.x, P1.y) == LEFT_CLICK) {
			cout << pIn->GetMouseClicked(P1.x, P1.y) << endl;
	      	if (pFig->IsInsideFigure(P1.x, P1.y)) {
			    pFig->Resize(P1);
				pManager->UpdateInterface();
			}
		}
	}
}
