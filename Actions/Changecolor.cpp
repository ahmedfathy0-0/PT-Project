#include "Changecolor.h"

Changecolor::Changecolor(ApplicationManager* pApp, color c,string nam,int type) : Action(pApp),Color(c),name(nam),Type(type) {}

void Changecolor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pFig = pManager->GetSelectedFigure();
	if (Type == 0) {
		pOut->PrintMessage("The DRAW color Changed to " + name);
	}
	else if (Type == 1) {
		pOut->PrintMessage("The FILL color Changed to " + name);
	}
	else if (Type == 2) {
		pOut->PrintMessage("The DRAW AND FILL color Changed to " + name);

	}

}

void Changecolor::Execute()
{					
	ReadActionParameters();
	if (pFig!=NULL) {
		pFig->SetSelected(false);
		if (Type == 0) {
			pFig->ChngDrawClr(Color);
			
		}
		else if (Type == 1) {
			pFig->ChngFillClr(Color);
		}
		else if (Type == 2) {
			pFig->ChngFillClr(Color);
			pFig->ChngDrawClr(Color);
		}
	}
	pManager->RecordFigure(pFig);


}

Action* Changecolor::Clone()
{
	return new Changecolor(*this);
}

void Changecolor::Undo()
{

}

void Changecolor::Redo()
{
}
