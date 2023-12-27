#include "AddTrgAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTrgAction::AddTrgAction(ApplicationManager* pApp) :Action(pApp)
{

}

void AddTrgAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (!pOut->getSound())
		PlaySound("Sounds\\Triangle.wav", NULL, SND_ASYNC);

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);


	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.isFilled = pOut->getisFilled();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();
	pOut->PrintMessage("You draw a new Triangle ;)");

}

//Execute the action
void AddTrgAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Triangle with the parameters read from the user
	T = new CTriangle(P1,P2, P3, RectGfxInfo);

	//Add the Triangle to the list of figures
	T->IsHidden(false);
	pManager->AddFigure(T);






}


Action* AddTrgAction::Clone()
{
	return new AddTrgAction(*this);
}

void AddTrgAction::Undo()
{
	pManager->RecordFigure(T);
	pManager->deletefigure(T);

}

void AddTrgAction::Redo()
{
	pManager->AddFigure(T);
//	pManager->RecordFigure(T);

}

bool AddTrgAction::IsUndoable()
{
	return true;
}
