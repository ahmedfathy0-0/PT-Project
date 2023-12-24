#include "AddSqrAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSqrAction::AddSqrAction(ApplicationManager* pApp, bool sound) :Action(pApp), Sound(sound)
{

}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (Sound)
		PlaySound("Sounds\\Square.wav", NULL, SND_ASYNC);

	pOut->PrintMessage("New Square: Click at The Center");

	//Read Centre and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.isFilled = pOut->getisFilled();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();
	pOut->PrintMessage("You draw a new Square ;)");

}

//Execute the action
void AddSqrAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Square with the parameters read from the user
	S = new CSquare(P1, RectGfxInfo);

	//Add the Square to the list of figures
	S->IsHidden(false);
	pManager->AddFigure(S);




}

Action* AddSqrAction::Clone()
{
	return new AddSqrAction(*this);
}

void AddSqrAction::Undo()
{
	S->IsHidden(true);
	pManager->RecordFigure(S);

}

void AddSqrAction::Redo()
{
	S->IsHidden(false);
	pManager->RecordFigure(S);

}
