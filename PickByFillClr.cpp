#include "PickByFillClr.h"
PickByFillClr::PickByFillClr(ApplicationManager* pApp) :Action(pApp)
{

}

CFigure* PickByFillClr::RandomizeClr()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("No drawn figures...Please draw some figures first:)");
		return NULL;
	}
	if (!(pManager->CheckForFillColor()))
	{
		pOut->PrintMessage("No colored figures...Please draw some colored figures first:)");
	}
	srand(time(0));
	int RandomIndex = rand() % (pManager->GetFigCount());
	ptrRandom = pManager->GetFigByIndex(RandomIndex);
}

void PickByFillClr::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* Clicked;
	int RightCounter = 0;
	int WrongCounter = 0;
	RandomizeClr();
	while (RightCounter < (pManager->RandomizedFillClrCount(ptrRandom)))
	{


	}

}

void PickByFillClr::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);
}
