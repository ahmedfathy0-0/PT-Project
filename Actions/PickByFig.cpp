#include "PickByFig.h"
#include"../Figures/CCircle.h"
#include"../Figures/CHexagon.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CSquare.h"
#include"../Figures/CTriangle.h"
#include"../Actions/Action.h"
#include"../DEFS.h"
#include<cstring>

PickByFig::PickByFig(ApplicationManager* papp) :Action(papp)
{
	ptrToPickByFill = NULL;
	ptrToPickByBoth = NULL;
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
		return ptrRandom;
		}
		if (ptrRandom->type()==hexagon)
		{
			pOut->PrintMessage("Pick all the Hexagons!");
			return ptrRandom;
		}
		if (ptrRandom->type()==rectangle)
		{
			pOut->PrintMessage("Pick all the Rectangles!");
			return ptrRandom;
		}
		if (ptrRandom->type()==square)
		{
			pOut->PrintMessage("Pick all the Squares!");
			return ptrRandom;
		}
		if (ptrRandom->type()==triangle)
		{
			pOut->PrintMessage("Pick all the Triangles!");
			return ptrRandom;
		}
}
void PickByFig::Execute()
{	
	pManager->UnHideFigures();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* Clicked;
	int RightCounter = 0;
	int WrongCounter = 0;
	 RandomizeFig();
	 while (RightCounter < pManager->RandomizedFigCount(ptrRandom))
	 {
		 ReadActionParameters();
		 if (P.x <= (UI.MenuItemWidth * 2) && P.x >= (UI.MenuItemWidth * 1) && P.y <= UI.ToolBarHeight && P.y >= 0)
		 {
			 RestartGame();
			 RightCounter = WrongCounter = 0;
		 }
		 else if (P.x <= (UI.MenuItemWidth) && P.x >= 0 && P.y <= UI.ToolBarHeight && P.y >= 0)
		 {
			 ReturnToDrawMidGame();
			 return;
		 }
		 else if (P.x <= (UI.MenuItemWidth * 3) && P.x >= (UI.MenuItemWidth * 2) && P.y <= UI.ToolBarHeight && P.y >= 0)
		 {

			 ptrToPickByFill = new PickByFillClr(pManager);
			 ptrToPickByFill->Execute();
			 break;
		 }
		 else if (P.x <= (UI.MenuItemWidth * 4) && P.x >= (UI.MenuItemWidth * 3) && P.y <= UI.ToolBarHeight && P.y >= 0)
		 {
			 ptrToPickByBoth = new PickByBoth(pManager);
			 ptrToPickByBoth->Execute();
			 break;
		 }
			 Clicked = pManager->GetFigure(P.x, P.y);
			 if (Clicked == NULL)
			 {

			 }
			 else if (ptrRandom->type() == Clicked->type())
			 {
				 RightCase(Clicked, RightCounter, WrongCounter);
			 }
			 else if (ptrRandom->type() != Clicked->type())
			 {
				 WrongCase(Clicked, RightCounter, WrongCounter);
			 }
	 }
	 if (pManager->GetFigCount()!=0&&ptrToPickByFill==NULL&&ptrToPickByBoth==NULL)
	 {
		 pOut->PrintMessage("SCORE---------->>Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));
		 if (!pOut->getSound())
		 {
			 if (RightCounter > WrongCounter)
				 PlaySound(("Sounds\\Win.wav"), NULL, SND_ASYNC);
			 else
				 PlaySound(("Sounds\\Fail.wav"), NULL, SND_ASYNC);
		 }
	 }
	 if (ptrToPickByFill!=NULL)
	 {
		 delete ptrToPickByFill;
	 }
	 if (ptrToPickByBoth != NULL)
	 {
		 delete ptrToPickByBoth;
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
void PickByFig::RightCase(CFigure* Clicked,int& right,int& wrong)
{
	Output* pOut = pManager->GetOutput();
	right++;
	Clicked->IsHidden(true);
	pManager->UpdateInterface();
	pOut->PrintMessage("Right attempts: " + to_string(right) + " Wrong attempts: " + to_string(wrong));
}
void PickByFig::WrongCase(CFigure*clicked, int&right, int&wrong)
{
	Output* pOut = pManager->GetOutput();
	wrong++;
	if (!pOut->getSound())
	PlaySound(("Sounds\\Wrong.wav"), NULL, SND_ASYNC);
	clicked->IsHidden(true);
	pManager->UpdateInterface();
	pOut->PrintMessage("Right attempts: " + to_string(right) + " Wrong attempts: " + to_string(wrong));
}
void PickByFig::RestartGame()
{
	pManager->UnHideFigures();
	pManager->UpdateInterface();
	RandomizeFig();
}
void PickByFig::ReturnToDrawMidGame()
{
	UI.InterfaceMode == MODE_DRAW;
	Output* pOut = pManager->GetOutput();
	if (ptrToPickByFill != NULL)
	{
		delete ptrToPickByFill;
	}
	if (ptrToPickByBoth != NULL)
	{
		delete ptrToPickByBoth;
	}
	pManager->UnHideFigures();
	pManager->UpdateInterface();
	pOut->CreateDrawToolBar();
}
void PickByFig::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);
}
	
