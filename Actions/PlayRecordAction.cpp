#include "PlayRecordAction.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CHexagon.h"
#include "MoveFigure.h"

PlayRecordAction::PlayRecordAction(ApplicationManager* pApp) : Action(pApp) {}

void PlayRecordAction::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();

	filename = "Last Record";
	pManager->Clearall();
	pOut->PrintMessage("Streaming The Last Record is started ;)");
}

void PlayRecordAction::Execute()
{
	int n1 = 0;
	int n2 = 0;
	ReadActionParameters();
	fIn.open(filename);
	if (fIn.peek() == ifstream::traits_type::eof())
		pOut->PrintMessage("No Records to Play");
	else
	{
		bool flag = true;
		CFigure* myFig = NULL;
		for (int i = 0;flag ; i++)
		{
			fIn >> type;
			if (type == "RECTAN") {
				myFig = new CRectangle;
				myFig->PlayRecord(fIn);
				pManager->AddFigure(myFig);
				Pause(1000);
			}
			else if (type == "SQUARE") {
				myFig = new CSquare;
				myFig->PlayRecord(fIn);
				pManager->AddFigure(myFig);
				Pause(1000);
			}
			else if (type == "TRIANG") {
				myFig = new CTriangle;
				myFig->PlayRecord(fIn);
				pManager->AddFigure(myFig);
				Pause(1000);
			}
			else if (type == "HEXAGN") {
				myFig = new CHexagon;
				myFig->PlayRecord(fIn);
				pManager->AddFigure(myFig);
				Pause(1000);
			}
			else if (type == "CIRCLE") {
				myFig = new CCircle;
				myFig->PlayRecord(fIn);
				pManager->AddFigure(myFig);
				Pause(1000);

			}
			else if (type == "DELETE") {
				pManager->deletefigure(myFig);

			}
			else if(type=="FINISHED") {
				flag = false;
			}
			pManager->UpdateInterface();
		}
		pOut->PrintMessage("Streaming The Last Record is finished :)");
		pManager->setISPlaying(false);
	}
}

color PlayRecordAction::getclr(string colour)
{
	if (colour == "BLACK")
		return BLACK;
	else if (colour == "YELLOW")
		return YELLOW;
	else if (colour == "ORANGE")
		return ORANGE;
	else if (colour == "RED")
		return RED;
	else if (colour == "GREEN")
		return GREEN;
	else if (colour == "BLUE")
		return BLUE;
}

Action* PlayRecordAction::Clone()
{
	return NULL;
}

void PlayRecordAction::Undo()
{
}

void PlayRecordAction::Redo()
{
}

