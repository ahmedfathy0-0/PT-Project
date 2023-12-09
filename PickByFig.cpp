#include "PickByFig.h"
#include"Figures/CCircle.h"
#include"Figures/CHexagon.h"
#include"Figures/CRectangle.h"
#include"Figures/CSquare.h"
#include"Figures/CTriangle.h"
#include"Actions/Action.h"
PickByFig::PickByFig(ApplicationManager* papp) :Action(papp)
{

}

CFigure* PickByFig::Randomize()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("No drawn figures...Please draw some figures first:)");
		return NULL;
	}
	srand(time(0));
	int Random_Index = rand() % ((pManager->GetFigCount() + 1));
	CFigure* ptrRandom = pManager->GetFigByIndex(Random_Index);
		if (dynamic_cast<CCircle*>(ptrRandom))
		{
		pOut->PrintMessage("Pick all the Circles!");
		return ptrRandom;
		}
		if (dynamic_cast<CHexagon*>(ptrRandom))
		{
			pOut->PrintMessage("Pick all the Hexagons!");
			return ptrRandom;
		}
		if (dynamic_cast<CRectangle*>(ptrRandom))
		{
			pOut->PrintMessage("Pick all the Rectangles!");
			return ptrRandom;
		}
		if (dynamic_cast<CSquare*>(ptrRandom))
		{
			pOut->PrintMessage("Pick all the Squares!");
			return ptrRandom;
		}
		if (dynamic_cast<CTriangle*>(ptrRandom))
		{
			pOut->PrintMessage("Pick all the Triangles!");
			return ptrRandom;
		}
}
void PickByFig::Execute()
{
	Randomize();
}
void PickByFig::ReadActionParameters()
{

}
	
