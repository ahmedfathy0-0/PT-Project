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
#include "Actions\MoveFigureByDrag.h"
#include "Actions\ResizeAction.h"
#include "Actions\LoadAction.h"
#include "Actions\StartRecordingAction.h"
#include "Actions\PlayRecordAction.h"
#include"PickAndHideAction.h"
#include"PickByFig.h"
#include"PickByFillClr.h"
#include"SwitchToPlayAction.h"
#include"Actions\Changecolor.h"
#include "Actions/UndoAction.h"
#include "Actions/RedoAction.h"
#include"Actions\ChangeFillcolor.h"
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
	UndoableActionsCount = 0;
	RedoableActionsCount = 0;
	for (int i = 0; i < 4; i++)
		UndoableActions[i] = NULL;
	for (int i = 0; i < 4; i++)
		RedoableActions[i] = NULL;
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
						Recordfile << "FINISHED" << endl;
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
		pAct = new UndoAction(this);
		break;

	case REDO:
		pAct = new RedoAction(this);
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

	case MOVEDRAG:
		pAct = new MoveDragAction(this);
		break;

	case RESIZE:
		pAct = new ResizeAction(this);
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
		pAct = new SwitchToPlayAction(this);
		break;

	case EMPTY_PLAYTOOLBAR:
		pOut->PrintMessage("Action: a click on empty area in the Play Tool Bar, Click anywhere");
		break;


	case PLAYING_AREA:
		pOut->PrintMessage("Action: a click on the draw area in Play Mode, Click anywhere");
		break;

	case PICKANDHIDE:
		pAct = new PickAndHideAction(this);
		pAct->Execute();
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
			Recordfile << "FINISHED" << endl;
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
			pOut->PrintMessage("The draw color will now be black!");
			pOut->setCrntDrawColor(BLACK);
			pOut->setisFilled(false);
			if (SelectedFigure != NULL)
				pAct = new ChangeDrawcolor(this);
			break;

		case YELLOWCLR:
			pOut->PrintMessage("The draw color will now be yellow!");
			pOut->setCrntDrawColor(YELLOW);
			pOut->setisFilled(false);
			if (SelectedFigure != NULL)
				pAct = new ChangeDrawcolor(this);
			break;

		case ORANGECLR:
			pOut->PrintMessage("The draw color will now be orange!");
			pOut->setCrntDrawColor(ORANGE);
			pOut->setisFilled(false);
			if (SelectedFigure != NULL) {
				pAct = new ChangeDrawcolor(this);
			}
			break;

		case REDCLR:
			pOut->PrintMessage("The draw color will now be red!");
			pOut->setCrntDrawColor(RED);
			pOut->setisFilled(false);
			if (SelectedFigure != NULL)
			{
				pAct = new ChangeDrawcolor(this);
			}

			break;

		case GREENCLR:

			pOut->PrintMessage("The draw color will now be green!");
			pOut->setCrntDrawColor(GREEN);
			pOut->setisFilled(false);
			if (SelectedFigure != NULL)
			{
				pAct = new ChangeDrawcolor(this);
			}

			break;

		case BLUECLR:
			pOut->PrintMessage("The draw color will now be blue!");
			pOut->setCrntDrawColor(BLUE);
			pOut->setisFilled(false);
			if (SelectedFigure != NULL)
			{
				pAct = new ChangeDrawcolor(this);
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
			pOut->PrintMessage("The fill color will now be black");
			pOut->setCrntFillColor(BLACK);
			pOut->setisFilled(true);
			if (SelectedFigure != NULL)
			{
				pAct = new ChangeFillcolor(this);
			}

			break;

		case YELLOWCLR:
			pOut->PrintMessage("The fill color will now be yellow");
			pOut->setCrntFillColor(YELLOW);
			pOut->setisFilled(true);
			if (SelectedFigure != NULL)
			{
				pAct = new ChangeFillcolor(this);
			}


			break;

		case ORANGECLR:
			pOut->PrintMessage("The fill color will now be orange");
			pOut->setCrntFillColor(ORANGE);
			pOut->setisFilled(true);
		
			if (SelectedFigure != NULL)
				pAct = new ChangeFillcolor(this);

			break;

		case REDCLR:
			pOut->PrintMessage("The fill color will now be red");
			pOut->setCrntFillColor(RED);
			pOut->setisFilled(true);
			if (SelectedFigure != NULL)
			{
				pAct = new ChangeFillcolor(this);
			}

			break;

		case GREENCLR:
			pOut->PrintMessage("The fill color will now be green");
			pOut->setCrntFillColor(GREEN);
			pOut->setisFilled(true);
			if (SelectedFigure != NULL)
			{
				pAct = new ChangeFillcolor(this);
			}

			break;

		case BLUECLR:
			pOut->PrintMessage("The fill color will now be blue");
			pOut->setCrntFillColor(BLUE);
			pOut->setisFilled(true);
			if (SelectedFigure != NULL)
			{
		 		pAct = new ChangeFillcolor(this);
		    }
			break;

		}


		pOut->deleteColorPalette();
		UI.conD = false;
		break;

	case CHANGECOLOR:
		
			break;


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

		//adding the action to the undoable list if this action is undoable
	if (dynamic_cast<AddCircAction*>(pAct) != NULL || dynamic_cast<AddRectAction*>(pAct) != NULL || dynamic_cast<AddSqrAction*>(pAct) != NULL ||
			dynamic_cast<AddTrgAction*>(pAct) != NULL || dynamic_cast<AddHexAction*>(pAct) != NULL || dynamic_cast<DeleteAction*>(pAct) != NULL || dynamic_cast<MoveAction*>(pAct) != NULL
			|| dynamic_cast<ChangeDrawcolor*>(pAct) != NULL)
		{
			AddAction(pAct);
			ClearRedoList();
		}

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
	if (SelectedFigure != NULL) {
		return SelectedFigure;
	}
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

void ApplicationManager::AddAction(Action* Act)
{
	if (Act != NULL)
	{
		if (UndoableActionsCount < 5) //if the undo array doesn't have the maximum 5 elements
		{
			UndoableActions[UndoableActionsCount++] = Act->Clone();
		}

		else //if it has 5 elements,it will remove the oldest element of the array and put the new action in the last index
		{
			if (UndoableActions[0]) 
			{
				delete UndoableActions[0];
				UndoableActions[0] = NULL;
				for (int i = 0; i < 4; i++)
				{
					UndoableActions[i] = UndoableActions[i + 1];
				}
				UndoableActions[4] = Act->Clone();

			}
		}
	}
}

Action* ApplicationManager::ReturnLastUndoableAction()
{
	if (UndoableActionsCount == 0)
		return NULL;
	else if (UndoableActionsCount > 0)
	{
		UndoableActionsCount--;
		/*if (UndoableActionsCount == 0)
		{
			for (int i = 0; i < 4; i++) 
			{
				if (UndoableActions[i]) UndoableActionsCount++;
				else break;
			}
			return UndoableActions[UndoableActionsCount];
		}*/
		return UndoableActions[UndoableActionsCount];
	}
}
void ApplicationManager::AddToRedo(Action* Act)
{
	if (Act != NULL)
	{
		RedoableActions[RedoableActionsCount++] = Act->Clone();
		delete UndoableActions[UndoableActionsCount];
		UndoableActions[UndoableActionsCount] = NULL;
	}
}

Action* ApplicationManager::ReturnLastRedoableAction()
{
	if (RedoableActionsCount == 0)
		return NULL;
	else if (RedoableActionsCount > 0)
	{
		RedoableActionsCount--;
		return RedoableActions[RedoableActionsCount];
	}
}

void ApplicationManager::ClearRedoList()
{
	for (int i = 0; i < RedoableActionsCount; i++)
	{
		if (RedoableActions[i] != NULL)
		{
			delete RedoableActions[i];
			RedoableActions[i] = NULL;
		}
	}
	RedoableActionsCount = 0;
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
	/*for (int i = 0; i < FigCount && flag; i++)
		if (FigList[i] != NULL) {
			if (FigList[i]->IsSelected())
			{
				if (IsRecording && OPcount <= 20) {
					OPcount++;
					Recordfile << "DELETE" << endl;
				}
				//delete FigList[i];

				//this is the part i changed ya fathy
				FigList[i]->IsHidden(true);
				FigList[i] = FigList[FigCount - 1];
				FigList[i]->setID(i + 1);

				FigCount--;
				FigList[FigCount] = NULL;
				SelectedFigure = NULL;
				flag = false;

			}
		}*/
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
			FigList[i]->Draw(pOut);//Call Draw function (virtual member fn)1
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
