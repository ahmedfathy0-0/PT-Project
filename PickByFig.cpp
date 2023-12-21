#include "PickByFig.h"
#include"Figures/CCircle.h"
#include"Figures/CHexagon.h"
#include"Figures/CRectangle.h"
#include"Figures/CSquare.h"
#include"Figures/CTriangle.h"
#include"Actions/Action.h"
#include"DEFS.h"
#include<cstring>
PickByFig::PickByFig(ApplicationManager* papp) :Action(papp)
{

}

CFigure* PickByFig::RandomizeFig()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("No drawn figures...Please draw some figures first:)");
		return NULL;
	}
	srand(time(0));
	int Random_Index = rand() % (pManager->GetFigCount());
	 ptrRandom = pManager->GetFigByIndex(Random_Index);
		if (ptrRandom->type()==circle)
		{
		pOut->PrintMessage("Pick all the Circles!");
		FigureToPick = circle;
		return ptrRandom;
		}
		if (ptrRandom->type()==hexagon)
		{
			pOut->PrintMessage("Pick all the Hexagons!");
			FigureToPick = hexagon;
			return ptrRandom;
		}
		if (ptrRandom->type()==rectangle)
		{
			pOut->PrintMessage("Pick all the Rectangles!");
			FigureToPick = rectangle;
			return ptrRandom;
		}
		if (ptrRandom->type()==square)
		{
			pOut->PrintMessage("Pick all the Squares!");
			FigureToPick = square;
			return ptrRandom;
		}
		if (ptrRandom->type()==triangle)
		{
			pOut->PrintMessage("Pick all the Triangles!");
			FigureToPick = triangle;
			return ptrRandom;
		}
}



void PickByFig::Execute()
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* Clicked;
	int RightCounter = 0;
	int WrongCounter = 0;
	 RandomizeFig();
	 while (RightCounter<pManager->RandomizedFigCount(ptrRandom))
	 {
		 
		 if (pIn->GetUserAction() == PICKBYFIG)
		 {
			 pManager->UnHideFigures();
			 pManager->UpdateInterface();
			 RightCounter = 0;
			 WrongCounter = 0;
			 RandomizeFig();
		 }
		 
		 
		 switch (ptrRandom->type())
		 {
		 case circle:
			 ReadActionParameters();
			  Clicked = pManager->GetFigure(P.x, P.y);
			 if (Clicked == NULL)
			 {

			 }
			 else if (Clicked->type() == circle)
			 {
				 RightCounter++;
				 Clicked->IsHidden(true);
				 pManager->UpdateInterface();
				 pOut->PrintMessage("Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));
			 }
			 else
			 {
				 WrongCounter++;
				 Clicked->IsHidden(true);
				 pManager->UpdateInterface();
				 pOut->PrintMessage("Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));

			 }
			 break;
		 case hexagon:
			 ReadActionParameters();
			  Clicked = pManager->GetFigure(P.x, P.y);
			 if (Clicked == NULL)
			 {
				 
			 }
			 else if (Clicked->type() == hexagon)
			 {
				 RightCounter++;
				 Clicked->IsHidden(true);
				 pManager->UpdateInterface();
				 pOut->PrintMessage("Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));
			 }
			 else
			 {
				 WrongCounter++;
				 Clicked->IsHidden(true);
				 pManager->UpdateInterface();
				 pOut->PrintMessage("Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));
			 }
			 break;
		 case rectangle:
			 ReadActionParameters();
			  Clicked = pManager->GetFigure(P.x, P.y);
			 if (Clicked == NULL)
			 {
				 
			 }
			 else if (Clicked->type() == rectangle)
			 {
				 RightCounter++;
				 Clicked->IsHidden(true);
				 pManager->UpdateInterface();
				 pOut->PrintMessage("Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));
			 }
			 else
			 {
				 WrongCounter++;
				 Clicked->IsHidden(true);
				 pManager->UpdateInterface();
				 pOut->PrintMessage("Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));
			 }
			 break;
		 case square:
			 ReadActionParameters();
			  Clicked = pManager->GetFigure(P.x, P.y);
			 if (Clicked == NULL)
			 {
				
			 }
			 else if (Clicked->type() == square)
			 {
				 RightCounter++;
				 Clicked->IsHidden(true);
				 pManager->UpdateInterface();
				 pOut->PrintMessage("Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));
			 }
			 else
			 {
				 WrongCounter++;
				 Clicked->IsHidden(true);
				 pManager->UpdateInterface();
				 pOut->PrintMessage("Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));
			 }
			 break;
		 case triangle:
			 ReadActionParameters();
			  Clicked = pManager->GetFigure(P.x, P.y);
			 if (Clicked == NULL)
			 {
				
			 }
			 else if (Clicked->type() == triangle)
			 {
				 RightCounter++;
				 Clicked->IsHidden(true);
				 pManager->UpdateInterface();
				 pOut->PrintMessage("Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));
			 }
			 else
			 {
				 WrongCounter++;
				 Clicked->IsHidden(true);
				 pManager->UpdateInterface();
				 pOut->PrintMessage("Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));
			 }
			 break;
		 }
		  
	 }

	 UI.conDforPicknHide = false;
	 if (pManager->GetFigCount()!=0)
	 {
		 pOut->PrintMessage("SCORE---------->>Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));
	 }
	 

	
}

Action* PickByFig::Clone()
{
	return new PickByFig(*this);
}

void PickByFig::Undo()
{
}

void PickByFig::Redo()
{
}



void PickByFig::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);
}
	
