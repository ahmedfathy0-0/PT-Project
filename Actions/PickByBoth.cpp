#include "PickByBoth.h"
#include "PickByFillClr.h"
#include "PickByFig.h"
#include"../Figures/CCircle.h"
#include"../Figures/CHexagon.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CSquare.h"
#include"../Figures/CTriangle.h"
#include"../Actions/Action.h"
#include"../DEFS.h"
#include<cstring>
PickByBoth::PickByBoth(ApplicationManager* pApp) :Action(pApp)
{
	ptrToPickByFig = NULL;
	ptrToPickByFill = NULL;
}
void PickByBoth::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);
}
CFigure* PickByBoth::Randomize()
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
		return NULL;
	}
	srand(time(0));
	int RandomIndex = rand() % (pManager->GetFigCount());
	ptrRandom = pManager->GetFigByIndex(RandomIndex);
	if (ptrRandom->isfilled() == false)
	{
		RandomIndex = rand() % (pManager->GetFigCount());
		ptrRandom = pManager->GetFigByIndex(RandomIndex);
	}
	if (ptrRandom->type() == circle)
	{
		if (ptrRandom->GetFillClr() == Red)
		{
			pOut->PrintMessage("Pick all the red circles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Blue)
		{
			pOut->PrintMessage("Pick all the blue circles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Green)
		{
			pOut->PrintMessage("Pick all the green circles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Yellow)
		{
			pOut->PrintMessage("Pick all the yellow circles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Orange)
		{
			pOut->PrintMessage("Pick all the orange circles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Black)
		{
			pOut->PrintMessage("Pick all the black circles!");
			return ptrRandom;
		}
	}
	if (ptrRandom->type() == hexagon)
	{
		if (ptrRandom->GetFillClr() == Red)
		{
			pOut->PrintMessage("Pick all the red hexagons!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Blue)
		{
			pOut->PrintMessage("Pick all the blue hexagons!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Green)
		{
			pOut->PrintMessage("Pick all the green hexagons!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Yellow)
		{
			pOut->PrintMessage("Pick all the yellow hexagons!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Orange)
		{
			pOut->PrintMessage("Pick all the orange hexagons!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Black)
		{
			pOut->PrintMessage("Pick all the black hexagons!");
			return ptrRandom;
		}
	}
	if (ptrRandom->type() == rectangle)
	{
		if (ptrRandom->GetFillClr() == Red)
		{
			pOut->PrintMessage("Pick all the red rectangles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Blue)
		{
			pOut->PrintMessage("Pick all the blue rectangles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Green)
		{
			pOut->PrintMessage("Pick all the green rectangles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Yellow)
		{
			pOut->PrintMessage("Pick all the yellow rectangles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Orange)
		{
			pOut->PrintMessage("Pick all the orange rectangles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Black)
		{
			pOut->PrintMessage("Pick all the black rectangles!");
			return ptrRandom;
		}
	}
	if (ptrRandom->type() == square)
	{
		if (ptrRandom->GetFillClr() == Red)
		{
			pOut->PrintMessage("Pick all the red squares!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Blue)
		{
			pOut->PrintMessage("Pick all the blue squares!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Green)
		{
			pOut->PrintMessage("Pick all the green squares!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Yellow)
		{
			pOut->PrintMessage("Pick all the yellow squares!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Orange)
		{
			pOut->PrintMessage("Pick all the orange squares!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Black)
		{
			pOut->PrintMessage("Pick all the black squares!");
			return ptrRandom;
		}
	}
	if (ptrRandom->type() == triangle)
	{
		if (ptrRandom->GetFillClr() == Red)
		{
			pOut->PrintMessage("Pick all the red triangles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Blue)
		{
			pOut->PrintMessage("Pick all the blue triangles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Green)
		{
			pOut->PrintMessage("Pick all the green triangles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Yellow)
		{
			pOut->PrintMessage("Pick all the yellow triangles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Orange)
		{
			pOut->PrintMessage("Pick all the orange triangles!");
			return ptrRandom;
		}
		if (ptrRandom->GetFillClr() == Black)
		{
			pOut->PrintMessage("Pick all the black triangles!");
			return ptrRandom;
		}
	}
}
void PickByBoth::RightCase(CFigure*Clicked, int&right, int&wrong)
{
	Output* pOut = pManager->GetOutput();
	right++;
	Clicked->IsHidden(true);
	pManager->UpdateInterface();
	pOut->PrintMessage("Right attempts: " + to_string(right) + " Wrong attempts: " + to_string(wrong));
}
void PickByBoth::WrongCase(CFigure* Clicked, int& right, int& wrong)
{
	Output* pOut = pManager->GetOutput();
	wrong++;
	if (!pOut->getSound())
	PlaySound(("Sounds\\Wrong.wav"), NULL, SND_ASYNC);
	Clicked->IsHidden(true);
	pManager->UpdateInterface();
	pOut->PrintMessage("Right attempts: " + to_string(right) + " Wrong attempts: " + to_string(wrong));
}
void PickByBoth::RestartGame()
{
	pManager->UnHideFigures();
	pManager->UpdateInterface();
	Randomize();
}
void PickByBoth::ReturnToDrawMidGame()
{
	UI.InterfaceMode = MODE_DRAW;
	Output* pOut = pManager->GetOutput();
	if (ptrToPickByFig != NULL)
	{
		delete ptrToPickByFig;
	}
	if (ptrToPickByFill != NULL)
	{
		delete ptrToPickByFill;
	}
	pManager->UnHideFigures();
	pManager->UpdateInterface();
	pOut->CreateDrawToolBar();
}
Action* PickByBoth::Clone()
{
	return new PickByBoth(*this);
}
void PickByBoth::Undo()
{
}
void PickByBoth::Redo()
{
}
void PickByBoth::Execute()
{
	pManager->UnHideFigures();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* Clicked;
	int RightCounter = 0;
	int WrongCounter = 0;
	Randomize();
	while (RightCounter < pManager->RandomizedPickByBothCount(ptrRandom))
	{
		ReadActionParameters();
		if (P.x <= (UI.MenuItemWidth * 4) && P.x >= (UI.MenuItemWidth * 3) && P.y <= UI.ToolBarHeight && P.y >= 0)
		{
			RestartGame();
			RightCounter = WrongCounter = 0;
		}
		else if (P.x <= (UI.MenuItemWidth) && P.x >= 0 && P.y <= UI.ToolBarHeight && P.y >= 0)
		{
			ReturnToDrawMidGame();
			return;
		}
		else if (P.x <= (UI.MenuItemWidth * 2) && P.x >= (UI.MenuItemWidth * 1) && P.y <= UI.ToolBarHeight && P.y >= 0)
		{
			pManager->UnHideFigures();
			pManager->UpdateInterface();
			ptrToPickByFig = new PickByFig(pManager);
			ptrToPickByFig->Execute();
			break;
		}
		else if (P.x <= (UI.MenuItemWidth * 3) && P.x >= (UI.MenuItemWidth * 2) && P.y <= UI.ToolBarHeight && P.y >= 0)
		{
			pManager->UnHideFigures();
			pManager->UpdateInterface();
			ptrToPickByFill = new PickByFillClr(pManager);
			ptrToPickByFill->Execute();
			break;
		}
		Clicked = pManager->GetFigure(P.x, P.y);
		if (Clicked == NULL)
		{

		}
		else if (ptrRandom->GetFillClr() == Clicked->GetFillClr() && ptrRandom->type() == Clicked->type())
		{
			RightCase(Clicked, RightCounter, WrongCounter);
		}
		else if (ptrRandom->GetFillClr() != Clicked->GetFillClr() || ptrRandom->type() != Clicked->type())
		{
			WrongCase(Clicked, RightCounter, WrongCounter);
		}
	}
	if (pManager->GetFigCount() != 0 && pManager->CheckForFillColor() == true&&ptrToPickByFig==NULL&&ptrToPickByFill==NULL)
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
	if (ptrToPickByFig != NULL)
	{
		delete ptrToPickByFig;
	}
	if (ptrToPickByFill != NULL)
	{
		delete ptrToPickByFill;
	}
}

