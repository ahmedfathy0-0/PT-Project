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

void PickByFillClr::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* Clicked;
	int RightCounter = 0;
	int WrongCounter = 0;
	RandomizeClr();
	while (RightCounter<pManager->RandomizedFillClrCount(ptrRandom))
	{
		switch (ptrRandom->GetFillClr())
		{
		case Red:
			ReadActionParameters();
			Clicked = pManager->GetFigure(P.x, P.y);
			if (Clicked == NULL)
			{

			}
			else if (Clicked->GetFillClr() == Red)
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

		case Blue:
			ReadActionParameters();
			Clicked = pManager->GetFigure(P.x, P.y);
			if (Clicked == NULL)
			{

			}
			else if (Clicked->GetFillClr() == Blue)
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
		case Green:
			ReadActionParameters();
			Clicked = pManager->GetFigure(P.x, P.y);
			if (Clicked == NULL)
			{

			}
			else if (Clicked->GetFillClr() == Green)
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
		case Orange:
			ReadActionParameters();
			Clicked = pManager->GetFigure(P.x, P.y);
			if (Clicked == NULL)
			{

			}
			else if (Clicked->GetFillClr() == Orange)
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
		case Yellow:
			ReadActionParameters();
			Clicked = pManager->GetFigure(P.x, P.y);
			if (Clicked == NULL)
			{

			}
			else if (Clicked->GetFillClr() == Yellow)
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
		case Black:
			ReadActionParameters();
			Clicked = pManager->GetFigure(P.x, P.y);
			if (Clicked == NULL)
			{

			}
			else if (Clicked->GetFillClr() == Black)
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
	if(pManager->GetFigCount()!=0&&pManager->CheckForFillColor()==true)
	pOut->PrintMessage("SCORE---------->>Right attempts: " + to_string(RightCounter) + " Wrong attempts: " + to_string(WrongCounter));

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
