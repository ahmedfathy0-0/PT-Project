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

PickByFillClr::PickByFillClr(ApplicationManager* pApp) :Action(pApp)
{
	ptrToPickByFig = NULL;
	ptrToPickByBoth = NULL;
}

void PickByFillClr::RightCase(CFigure* Clicked, int& right, int& wrong)
{
	Output* pOut = pManager->GetOutput();
	right++;
	Clicked->IsHidden(true);
	pManager->UpdateInterface();
	pOut->PrintMessage("Right attempts: " + to_string(right) + " Wrong attempts: " + to_string(wrong));
}

void PickByFillClr::WrongCase(CFigure* Clicked, int& right, int& wrong)
{
	Output* pOut = pManager->GetOutput();
	wrong++;
	if (!pOut->getSound())
	PlaySound(("Sounds\\Wrong.wav"), NULL, SND_ASYNC);
	Clicked->IsHidden(true);
	pManager->UpdateInterface();
	pOut->PrintMessage("Right attempts: " + to_string(right) + " Wrong attempts: " + to_string(wrong));
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

	switch (ptrRandom->GetFillClr())
	{
	case Red:
		pOut->PrintMessage("Pick all the red figures!");
		break;
	case Blue:
		pOut->PrintMessage("Pick all the blue figures!");
		break;
	case Green:
		pOut->PrintMessage("Pick all the green figures!");
		break;
	case Orange:
		pOut->PrintMessage("Pick all the orange figures!");
		break;
	case Yellow:
		pOut->PrintMessage("Pick all the yellow figures!");
		break;
	case Black:
		pOut->PrintMessage("Pick all the black figures!");
		break;
	}
	return ptrRandom;
}

void PickByFillClr::RestartGame()
{
	pManager->UnHideFigures();
	pManager->UpdateInterface();
	RandomizeClr();
}

void PickByFillClr::ReturnToDrawMidGame()
{
	UI.InterfaceMode = MODE_DRAW;
	Output* pOut = pManager->GetOutput();
	if (ptrToPickByFig != NULL)
	{
		delete ptrToPickByFig;
	}
	if (ptrToPickByBoth != NULL)
	{
		delete ptrToPickByBoth;
	}
	pManager->UnHideFigures();
	pManager->UpdateInterface();
	pOut->CreateDrawToolBar();
}

void PickByFillClr::Execute()
{
	pManager->UnHideFigures();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* Clicked;
	int RightCounter = 0;
	int WrongCounter = 0;
	RandomizeClr();
	while (RightCounter < pManager->RandomizedFillClrCount(ptrRandom))
	{
		ReadActionParameters();
		if (P.x <= (UI.MenuItemWidth * 3) && P.x >= (UI.MenuItemWidth * 2) && P.y <= UI.ToolBarHeight && P.y >= 0)
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
		else if (P.x <= (UI.MenuItemWidth * 4) && P.x >= (UI.MenuItemWidth * 3) && P.y <= UI.ToolBarHeight && P.y >= 0)
		{
			pManager->UnHideFigures();
			pManager->UpdateInterface();
			ptrToPickByBoth = new PickByBoth(pManager);
			ptrToPickByBoth->Execute();
			break;
		}
			Clicked = pManager->GetFigure(P.x, P.y);
			if (Clicked == NULL)
			{

			}
			else if (ptrRandom->GetFillClr() == Clicked->GetFillClr())
			{
				RightCase(Clicked, RightCounter, WrongCounter);
			}
			else if (ptrRandom->GetFillClr() != Clicked->GetFillClr())
			{
				WrongCase(Clicked, RightCounter, WrongCounter);
			}
	}
	if (pManager->GetFigCount() != 0 && pManager->CheckForFillColor() == true&&ptrToPickByFig==NULL&&ptrToPickByBoth==NULL)
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

	if (ptrToPickByFig!=NULL)
	{
		delete ptrToPickByFig;
	}
	if (ptrToPickByBoth != NULL)
	{
		delete ptrToPickByBoth;
	}
	
}

Action* PickByFillClr::Clone()
{
	return new PickByFillClr(*this);
}

void PickByFillClr::Undo()
{
}

void PickByFillClr::Redo()
{
}

void PickByFillClr::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);
}
