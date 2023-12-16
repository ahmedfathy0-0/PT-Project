#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddTrgAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\SelectOneAction.h"
#include "Actions\SaveAction.h"
#include "Actions\ClearAll.h"
#include "Actions\DeleteAction.h"
#include "Actions\MoveFigure.h"
#include "Actions\LoadAction.h"
#include "Actions\StartRecordingAction.h"
#include "Actions\PlayRecordAction.h"

#include"PickByFig.h"
#include"PickByFillClr.h"
#include"Actions\Changecolor.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	IsRecording = false;
	SelectedFigure = NULL;
	OPcount = 0;

}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	ActionType ActiType = DRAW_CIRCLE;
	ActionType ActTypeForPickndHide = DRAW_HEXAGON;

	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	if (OPcount == 20) {
		pOut->PrintMessage("You Reached the maximum operation please End Record first to continue drawing");
		switch(ActType)
				case ENDRECORDING:
					if (IsRecording) {
						pOut->CreateSTARTRECORDING();
						IsRecording = false;
						pAct = new StartRecordingAction(this);
						OPcount = 0;
						Recordfile.close();
					}
	}
	else
	switch (ActType)
	{
	case DRAW_RECT:
		
		pAct = new AddRectAction(this);
		break;

	case DRAW_SQUARE:
		
		pAct = new AddSqrAction(this);
		break;

	case DRAW_TRIANGLE:
		
		pAct = new AddTrgAction(this);
		break;

	case DRAW_HEXAGON:

		pAct = new AddHexAction(this);
		break;

	case DRAW_CIRCLE:
		
		pAct = new AddCircAction(this);
		break;

	case STATUS:	//a click on the status bar ==> no action
		pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
		return;

	case SAVE:
		pAct = new SaveAction(this);
		break;

	case UNDO:
		pOut->PrintMessage("Action: Undo Action, Click anywhere");
		break;

	case REDO:
		pOut->PrintMessage("Action: Redo Action, Click anywhere");
		break;

	case SELECTONE:
		pAct = new SelectOneAction(this);
		break;

	case LOAD:
		pAct = new LoadAction(this);
		break;

	case MOVE:
		pAct = new MoveAction(this);
		break;

	case RESIZE:
		pOut->PrintMessage("Action: RE-SIZE, Click anywhere");
		break;

	case CLEAR:
		pAct = new ClearAll(this);
		break;

	case DELET:
		pAct = new DeleteAction(this);
		break;

	case DRAWING_AREA:
		pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
		break;

	case EMPTY:
		pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
		break;

	case TO_DRAW:
		
		pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
		pOut->CreateDrawToolBar();
		UnHideFigures();
		
		break;

	case TO_PLAY:
		pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
		pOut->CreatePlayToolBar();
		break;

	case EMPTY_PLAYTOOLBAR:
		pOut->PrintMessage("Action: a click on empty area in the Play Tool Bar, Click anywhere");
		break;


	case PLAYING_AREA:
		pOut->PrintMessage("Action: a click on the draw area in Play Mode, Click anywhere");
		break;

	case PICKANDHIDE:
		pOut->PrintMessage("Action:Pick and Hide. Choose an Option");
		pOut->CreatePickAndHideToolbar();
		UI.conDforPicknHide = true;
		ActTypeForPickndHide = pIn->GetUserAction();
		switch (ActTypeForPickndHide)
		{
		case PICKBYFIG:
			pAct = new PickByFig(this);
			break;

		case PICKBYCOL:
			pAct = new PickByFillClr(this);

			break;
		case PICKBYBOTH:
			pOut->PrintMessage("You Chose to Pick by Both");

			break;
		}

		//pOut->deletePickAndHideToolbar();
		break;


	case STARTRECORDING:
		if (!IsRecording) {
			if (FigCount == 0) {
			pOut->CreateENDRECORDING();
			IsRecording = true;
			pAct = new StartRecordingAction(this);
		}
			else {
				pOut->PrintMessage("Please Clear all first");
			}
		}
		break;

	case ENDRECORDING:
		if (IsRecording) {
			pOut->CreateSTARTRECORDING();
			IsRecording = false;
			pAct = new StartRecordingAction(this);
			OPcount = 0;
			Recordfile.close();
		}
		break;

	case PLAYRECORDING:
		if (!IsRecording) {
			pAct = new PlayRecordAction(this);
		}
		break;

	case CHANGEDRAWCOLOR:
		pOut->PrintMessage("Action: change draw color, Choose the color you want");
		pOut->CreateColorPalette();
		UI.conD = true;
		ActiType = pIn->GetUserAction();

		switch (ActiType) {

		case BLACKCLR:
			if (SelectedFigure != NULL)
				pAct = new Changecolor(this, BLACK, "BLACK", 0);
			else{
				pOut->PrintMessage("The draw color will now be black!");
				pOut->setCrntDrawColor(BLACK);
				pOut->setisFilled(false);
			}
			break;

		case YELLOWCLR:
			if (SelectedFigure != NULL)
				pAct = new Changecolor(this, YELLOW, "YELLOW", 0);
			else{
				pOut->PrintMessage("The draw color will now be yellow!");
				pOut->setCrntDrawColor(YELLOW);
				pOut->setisFilled(false);
			}
			break;

		case ORANGECLR:

			if (SelectedFigure != NULL) {
				pAct = new Changecolor(this, ORANGE, "ORANGE", 0);
			}
			else{
				pOut->PrintMessage("The draw color will now be orange!");
				pOut->setCrntDrawColor(ORANGE);
				pOut->setisFilled(false);
			}
			break;

		case REDCLR:

			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, RED, "RED", 0);
			}
			else{
				pOut->PrintMessage("The draw color will now be red!");
				pOut->setCrntDrawColor(RED);
				pOut->setisFilled(false);
			}
			break;

		case GREENCLR:

			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, GREEN, "GREEN", 0);
		}
			else{
				pOut->PrintMessage("The draw color will now be green!");
				pOut->setCrntDrawColor(GREEN);
				pOut->setisFilled(false);
			
			}

			break;

		case BLUECLR:

			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, BLUE, "BLUE", 0);
			}
			else{
				pOut->PrintMessage("The draw color will now be blue!");
				pOut->setCrntDrawColor(BLUE);
				pOut->setisFilled(false);
			}

			break;

		}


		pOut->deleteColorPalette();


		UI.conD = false;
		break;

	case CHANGEFILLCOLOR:
		pOut->PrintMessage("Action: change fill color, Choose the color you want");
		pOut->CreateColorPalette();
		UI.conD = true;
		ActType = pIn->GetUserAction();

		switch (ActType) {

		case BLACKCLR:

			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, BLACK, "BLACK", 1);
			}
			else{
				pOut->PrintMessage("The fill color will now be black");
				pOut->setCrntFillColor(BLACK);
				pOut->setisFilled(true);
			}
			break;

		case YELLOWCLR:

			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, YELLOW, "YELLOW", 1);
			}
			else{
				pOut->PrintMessage("The fill color will now be yellow");
				pOut->setCrntFillColor(YELLOW);
				pOut->setisFilled(true);
			}

			break;

		case ORANGECLR:

			if (SelectedFigure != NULL)
			{

				pAct = new Changecolor(this, ORANGE, "ORANGE", 1);
			}
			else{
				pOut->PrintMessage("The fill color will now be orange");
				pOut->setCrntFillColor(ORANGE);
				pOut->setisFilled(true);
			}


			break;

		case REDCLR:

			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, RED, "RED", 1);
			}
			else{
				pOut->PrintMessage("The fill color will now be red");
				pOut->setCrntFillColor(RED);
				pOut->setisFilled(true);
			}
			break;

		case GREENCLR:
			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, GREEN, "GREEN", 1);
			}
			else{
				pOut->PrintMessage("The fill color will now be green");
				pOut->setCrntFillColor(GREEN);
				pOut->setisFilled(true);
			}
			break;

		case BLUECLR:
			if (SelectedFigure != NULL)
			{
		 		pAct = new Changecolor(this, BLUE, "BLUE", 1);
		    }
			else{
				pOut->PrintMessage("The fill color will now be blue");
				pOut->setCrntFillColor(BLUE);
				pOut->setisFilled(true);
			}
			break;

		}


		pOut->deleteColorPalette();
		UI.conD = false;
		break;

	case CHANGECOLOR:
		pOut->CreateColorPalette();
		pOut->PrintMessage("Action:You pressed the change color button, Choose the color you want ");
		UI.conD = true;
		ActiType = pIn->GetUserAction();

		switch (ActiType) {

		case BLACKCLR:

			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, BLACK, "BLACK", 2);
			}
			else{
				pOut->PrintMessage("Action: you pressed the black color");
				pOut->setCrntFillColor(BLACK);
				pOut->setCrntDrawColor(BLACK);
				pOut->setisFilled(true);
			}

			break;

		case YELLOWCLR:

			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, YELLOW, "YELLOW", 2);
			}
			else{
				pOut->PrintMessage("Action: you pressed the yellow color");
				pOut->setCrntFillColor(YELLOW);
				pOut->setCrntDrawColor(YELLOW);
				pOut->setisFilled(true);
			}
			break;

		case ORANGECLR:

			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, ORANGE, "ORANGE", 2);
			}
			else{
				pOut->PrintMessage("Action: you pressed the orange color");
				pOut->setCrntFillColor(ORANGE);
				pOut->setCrntDrawColor(ORANGE);
				pOut->setisFilled(true);
			}
			break;

		case REDCLR:

			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, RED, "RED", 2);
			}
			else{
				pOut->PrintMessage("Action: you pressed the red color");
				pOut->setCrntFillColor(RED);
				pOut->setCrntDrawColor(RED);
				pOut->setisFilled(true);
			}

			break;

		case GREENCLR:
			if (SelectedFigure != NULL){
			pAct = new Changecolor(this, GREEN, "GREEN", 2);
		    }
			else{
				pOut->PrintMessage("Action: you pressed the green color");
				pOut->setCrntFillColor(GREEN);
				pOut->setCrntDrawColor(GREEN);
					pOut->setisFilled(true);
			}
	
			break;

		case BLUECLR:
			if (SelectedFigure != NULL)
			{
				pAct = new Changecolor(this, BLUE, "BLUE", 2);
			}
			else{
				pOut->PrintMessage("Action: you pressed the blue color");
				pOut->setCrntFillColor(BLUE);
				pOut->setCrntDrawColor(BLUE);
				pOut->setisFilled(true);
			}
			break;

		}


		pOut->deleteColorPalette();
		UI.conD = false;




	case EXIT:
		///create ExitAction here
	{
    }

		break;

	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		if (pAct != NULL) {
			delete pAct;	//You may need to change this line depending to your implementation
			pAct = NULL;
		}
	}
}
int ApplicationManager::GetFigCount()
{
	return FigCount;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	int i = 0;
	for (i;i < FigCount;i++){
		if (FigList[i] != NULL) {
			if (pFig->getID() == FigList[i]->getID()) {
				delete FigList[i];
				FigList[i] = NULL;
				FigList[i] = pFig;
				break;
			}
		}
}
	if (i == FigCount)
	{
		if (FigCount < MaxFigCount) {
			FigList[FigCount++] = pFig;
		}
		pFig->setID(FigCount);
		if (IsRecording && OPcount <= 20) {
			OPcount++;
			pFig->StartEndRecord(Recordfile);
		}
		if (pFig->IsSelected())////used for PlayRecord while streaming
			SelectedFigure = pFig;
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	for (int i = 0; i < FigCount; i++) {
		if(FigList[i]->IsInsideFigure(x,y)&&(FigList[i]->GetHiddenStatus()==false)) return FigList[i];
	}
	return NULL;
}

void ApplicationManager::UnHideFigures()
{
	for (int i = 0; i < GetFigCount(); i++)
	{
		FigList[i]->IsHidden(false);
	}
}

void ApplicationManager::SetSelectedFigure(CFigure* pFig) {
	if (pFig){
		SelectedFigure = pFig;
	if (IsRecording && OPcount <= 20) {
		OPcount++;
		pFig->StartEndRecord(Recordfile);
	}
}
}



CFigure* ApplicationManager::GetSelectedFigure() const
{
	return SelectedFigure;
}



void ApplicationManager::deselectall()  {
	if (SelectedFigure != NULL) {
		SelectedFigure->SetSelected(false);
		if (IsRecording && OPcount < 20) {
			OPcount++;
			SelectedFigure->StartEndRecord(Recordfile);
		}

		SelectedFigure = NULL;
	}

}

void ApplicationManager::SaveAll(ofstream& OutFile) const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}
void ApplicationManager::Clearall()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}
void ApplicationManager::deletefigure()
{
	bool flag = true;
	for (int i = 0; i < FigCount&&flag; i++)
		if (FigList[i] != NULL) {
			if (FigList[i]->IsSelected())
			{
				if (IsRecording && OPcount <= 20) {
					OPcount++;
					Recordfile << "DELETE" << endl;
				}
				delete FigList[i];
				FigList[i] = FigList[FigCount - 1];
				FigList[i]->setID(i + 1);

				FigCount--;
				FigList[FigCount] = NULL;
				SelectedFigure = NULL;
				flag = false;

			}
		}
}
void ApplicationManager::StartRecord(string filename) 
{
	if (IsRecording)
		Recordfile.open(filename ,ios::trunc);
	else
		Recordfile.close();
}

void ApplicationManager::RecordFigure(CFigure* pFig)
{
	if (pFig != NULL) {
		if (IsRecording && OPcount < 20) {
			OPcount++;
			pFig->StartEndRecord(Recordfile);
		}
	}
	deselectall();

}

ofstream* ApplicationManager::getRecoedFile() 
{
	return &Recordfile;
}

bool ApplicationManager::getIsRecording() 
{
	return IsRecording;
}

CFigure* ApplicationManager::GetFigByIndex(int i)
{
	return FigList[i];
}



int ApplicationManager::RandomizedFigCount(CFigure*p)
{
	int count = 0;
	for (int i = 0; i < GetFigCount(); i++)
	{
		if (FigList[i]->type() == p->type())
		{
			count++;
		}
	}
	return count;
}

int ApplicationManager::RandomizedFillClrCount(CFigure*p)
{
	if (CheckForFillColor() == false)
	{
		return 0;
	}
	int count = 0;
	for (int i = 0; i < GetFigCount(); i++)
	{
		if (FigList[i]->GetFillClr() == p->GetFillClr())
		{
			count++;
		}
	}
	return count;

}

bool ApplicationManager::CheckForFillColor()
{
	for (int i = 0; i < GetFigCount(); i++)
	{
		if (FigList[i]->isfilled())
		{
			return true;
		}
	}
	return false;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface

void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		if(!(FigList[i]->GetHiddenStatus()))
		{
			FigList[i]->Draw(pOut);//Call Draw function (virtual member fn)

		}
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
