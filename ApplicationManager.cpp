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
#include"Actions\PickByFig.h"
#include"Actions\PickByFillClr.h"
#include"SwitchToPlayAction.h"
#include"Actions\Changecolor.h"
#include "Actions/UndoAction.h"
#include "Actions/RedoAction.h"
#include"Actions\ChangeFillcolor.h"
#include"Actions\PickByBoth.h"
#include"SwitchToDrawAction.h"
#include"Exit.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	ISPLYING = false;
	FigCount = 0;
	IsMute = false;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	IsRecording = false;
	SelectedFigure = NULL;
	OPcount = 0;
	UndoableActionsCount = 0;
	RedoableActionsCount = 0;
	DeletedActionsCount = 0;
	for (int i = 0; i < 5; i++)
		UndoableActions[i] = NULL;
	for (int i = 0; i < 5; i++)
		RedoableActions[i] = NULL;
	for (int i = 0; i < 5; i++)
		DeletedArray[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction(pOut);
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
		switch (ActType)
				case ENDRECORDING:
					if (IsRecording) {
						pOut->CreateSTARTRECORDING();
						Recordfile << "FINISHED" << endl;
						IsRecording = false;
						pAct = new StartRecordingAction(this);
						PlaySound(("Sounds\\End.wav"), NULL, SND_ASYNC);
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
			if (FigCount == 0) {
				pOut->PrintMessage("Please Draw some figures first");
			}
			else
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
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case TO_DRAW:

			pAct = new SwitchToDrawAction(this);
			pAct->Execute();
			break;

		case TO_PLAY:
			pAct = new SwitchToPlayAction(this);
			pAct->Execute();
			break;

		case PICKBYFIG:
			pAct = new PickByFig(this);
			break;

		case PICKBYCOL:
			pAct = new PickByFillClr(this);

			break;
		case PICKBYBOTH:
			pAct = new PickByBoth(this);

			break;


		case EMPTY_PLAYTOOLBAR:
			pOut->PrintMessage("Action: a click on empty area in the Play Tool Bar, Click anywhere");
			break;


		case PLAYING_AREA:
			pOut->PrintMessage("Action: a click on the draw area in Play Mode, Click anywhere");
			break;



	case STARTRECORDING:
		if (!IsRecording) {
			if (FigCount == 0) {
			pOut->CreateENDRECORDING();
			IsRecording = true;
			if (!pOut->getSound())
				PlaySound(("Sounds\\Start.wav"), NULL, SND_ASYNC);
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
			if (!pOut->getSound())
			PlaySound(("Sounds\\End.wav"), NULL, SND_ASYNC);
			pAct = new StartRecordingAction(this);
			OPcount = 0;
			Recordfile.close();
		}
		break;

		case PLAYRECORDING:
			if (!IsRecording) {
				pAct = new PlayRecordAction(this);
				ISPLYING = true;
			}
			break;

		case CHANGEDRAWCOLOR:
			if (SelectedFigure != NULL) {
				pOut->CreateColorPalette();
				UI.conD = true;
				ActiType = pIn->GetUserAction(pOut);
				pAct = new ChangeDrawcolor(this);
			}
			else
				pOut->PrintMessage("Please select figure first to be able to change the color");

			pOut->deleteColorPalette();


			UI.conD = false;
			break;

		case CHANGEFILLCOLOR:
			if (SelectedFigure != NULL) {
				pOut->CreateColorPalette();
				UI.conD = true;
				ActiType = pIn->GetUserAction(pOut);
				pAct = new ChangeFillcolor(this);
			}
			else
				pOut->PrintMessage("Please select figure first to be able to change the color");

			pOut->deleteColorPalette();
			UI.conD = false;
			break;

		case MUTE: {
			if (IsMute) {
				pOut->CreateUNMUTE();
				IsMute = false;

			}
			else {
				pOut->CreateMUTE();
				IsMute = true;

			}
			break;
		}
		case EXIT:
		{
			pAct = new ClearAll(this);
			pAct->Execute();
			delete pAct;
			pAct = NULL;
			pAct = new Exit(this);
		}

		break;

		}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute

		//adding the action to the undoable list if this action is undoable
		if (pAct->IsUndoable())
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
	if (ISPLYING) {
		for (i; i < FigCount; i++) {
			if (FigList[i] != NULL) {
				if (pFig->getID() == FigList[i]->getID()) {
					delete FigList[i];
					FigList[i] = NULL;
					FigList[i] = pFig;
					break;
				}
			}
		}
		
	}
	else i = FigCount;
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

void ApplicationManager::ClearUndoList()
{
	for (int i = 0; i < UndoableActionsCount; i++)
	{
		if (UndoableActions[i] != NULL)
		{
			delete UndoableActions[i];
			UndoableActions[i] = NULL;
		}
	}
	UndoableActionsCount = 0;
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

void ApplicationManager::AddToDeleteList(CFigure* figtobedeleted)
{
	if (DeletedActionsCount < 5) {
		DeletedArray[DeletedActionsCount++] = figtobedeleted;
	}
	else {
		if (DeletedArray[0])
		{
			delete DeletedArray[0];
			DeletedArray[0] = NULL;
			for (int i = 0; i < 4; i++)
			{
				DeletedArray[i] = DeletedArray[i + 1];
			}
			DeletedArray[4] = figtobedeleted;
		}
	}
}
void ApplicationManager::ClearDeleteList()
{
	if (DeletedActionsCount != 0) {
		for (int i = 0; i < 5; i++)
		{
			if (DeletedArray[i] != NULL)
			{
				delete DeletedArray[i];
				DeletedArray[i] = NULL;
			}
		}
		DeletedActionsCount = 0;
	}
}
void ApplicationManager::SaveAll(ofstream& OutFile) const //call save functions of all figures
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}
void ApplicationManager::Clearall() //clear all figures
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	pOut->PrintMessage("All Cleared Successfully");
}
void ApplicationManager::deletefigure(CFigure* figtobedeleted) //delete figure and some actions of saving undo history and recording
{
	bool flag = true;
	for (int i = 0; i < FigCount && flag; i++)
		if (FigList[i] != NULL) {
			if (FigList[i]==figtobedeleted)
			{
				if (IsRecording && OPcount <= 20) {
					OPcount++;
					Recordfile << "DELETE" << endl;
				}
				
				FigList[i] = FigList[FigCount - 1];
				FigList[i]->setID(i + 1);

				FigCount--;
				FigList[FigCount] = NULL;
				SelectedFigure = NULL;
				flag = false;

			}
		}
}
void ApplicationManager::ResetConstants() //reset UI variables
{
	UI.DrawColor = BLUE;
	UI.FillColor = UI.BkGrndColor;
	UI.ISFILLED = false;
	UI.SqrSize = 160;
	UI.HexagonSize = 100;
}
void ApplicationManager::StartRecord(string filename) 
{
	if (IsRecording)
		Recordfile.open(filename ,ios::trunc);
	else
		Recordfile.close();
}

void ApplicationManager::StopRecord()
{
	pOut->CreateSTARTRECORDING();
	IsRecording = false;
	if (!pOut->getSound())
		PlaySound(("Sounds\\End.wav"), NULL, SND_ASYNC);
	OPcount = 0;
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

void ApplicationManager::setISPlaying(bool flg)
{
	ISPLYING = flg;
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

int ApplicationManager::RandomizedPickByBothCount(CFigure*p)
{
	if (CheckForFillColor() == false)
	{
		return 0;
	}
	int count = 0;
	for (int i = 0; i < GetFigCount(); i++)
	{
		if (FigList[i]->GetFillClr() == p->GetFillClr()&&FigList[i]->type()==p->type())
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

void ApplicationManager::UpdateBuffer(bool flag) const
{
	pOut->SetBuffering(flag);
	pIn->SetWaitClose(flag);
	pOut->UpdateBuffer();
	pOut->CreateDrawToolBar();
}
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		if (!(FigList[i]->GetHiddenStatus()))
		{
			FigList[i]->Draw(pOut);//Call Draw function (virtual member fn)
		}
	//pOut->UpdateBuffer();
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
	/*for (int i = 0; i < FigCount; i++)
		delete FigList[i];*/
	delete pIn;
	delete pOut;
}
