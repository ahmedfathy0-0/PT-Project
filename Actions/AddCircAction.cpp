#include "AddCircAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{

}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (!pOut->getSound())
	{
		PlaySound(("Sounds\\Circle.wav"), NULL, SND_ASYNC);
	}

	pOut->PrintMessage("New Circle: Click at the Center");

	//Read the Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("New Circle: Click at a Point on the Circle ");

	//Read the Point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.isFilled = pOut->getisFilled();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();
	pOut->PrintMessage("You draw a new Circle ;)");
}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Circle with the parameters read from the user
	C = new CCircle(P1,P2, RectGfxInfo);

	//Add the Circle to the list of figures
	C->IsHidden(false);
	pManager->AddFigure(C);


}

Action* AddCircAction::Clone()
{
	return new AddCircAction(*this);
}

void AddCircAction::Undo()
{
	pManager->RecordFigure(C);
	pManager->deletefigure(C);
}

void AddCircAction::Redo()
{
	pManager->AddFigure(C);
	//pManager->RecordFigure(C);
}

bool AddCircAction::IsUndoable()
{
	return true;
}
