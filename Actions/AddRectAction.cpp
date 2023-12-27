#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddRectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (!pOut->getSound())
		PlaySound("Sounds\\Rectangle.wav", NULL, SND_ASYNC);

	pOut->PrintMessage("New Rectangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.isFilled = pOut->getisFilled();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();
	pOut->PrintMessage("You draw a new Rectangle ;)");

}

//Execute the action
void AddRectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	R = new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	R->IsHidden(false);
	pManager->AddFigure(R);


}

Action* AddRectAction::Clone()
{
	return new AddRectAction(*this);
}

void AddRectAction::Undo()
{
	pManager->RecordFigure(R);
	pManager->deletefigure(R);

}

void AddRectAction::Redo()
{
	pManager->AddFigure(R);
	//pManager->RecordFigure(R);
}

bool AddRectAction::IsUndoable()
{
	return true;
}
