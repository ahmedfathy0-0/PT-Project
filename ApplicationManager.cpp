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
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
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
void ApplicationManager::ExecuteAction(ActionType ActType, ActionType ActiType, ActionType ActTypeForPickndHide)
{


	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
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
			pOut->PrintMessage("You Chose to Select by Figure");


			break;

		case PICKBYCOL:
			pOut->PrintMessage("You Chose to Select by Color");

			break;
		case PICKBYBOTH:
			pOut->PrintMessage("You Chose to Pick by Both");

			break;
		}

		pOut->deletePickAndHideToolbar();
		UI.conDforPicknHide = false;
		break;


	case STARTRECORDING:
		if (pOut->getcount() % 2 == 0) {
			pOut->incrementcount();
			pOut->PrintMessage("Action: START RECORDING, Click anywhere");
			pOut->CreateENDRECORDING();
		}
		break;

	case ENDRECORDING:
		if (pOut->getcount() % 2 != 0) {
			pOut->incrementcount();
			pOut->PrintMessage("Action: END RECORDING, Click anywhere");
			pOut->CreateSTARTRECORDING();
		}
		break;

	case PLAYRECORDING:
		pOut->PrintMessage("Action: PLAY RECORDING, Click anywhere");
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
			Changefigurecolor(BLACK,0);
			break;

		case YELLOWCLR:
			pOut->PrintMessage("The draw color will now be yellow!");
			pOut->setCrntDrawColor(YELLOW);
			pOut->setisFilled(false);
			Changefigurecolor(YELLOW, 0);

			break;

		case ORANGECLR:
			pOut->PrintMessage("The draw color will now be orange!");
			pOut->setCrntDrawColor(ORANGE);
			pOut->setisFilled(false);
			Changefigurecolor(ORANGE, 0);

			break;

		case REDCLR:
			pOut->PrintMessage("The draw color will now be red!");
			pOut->setCrntDrawColor(RED);
			pOut->setisFilled(false);
			Changefigurecolor(RED, 0);

			break;

		case GREENCLR:
			pOut->PrintMessage("The draw color will now be green!");
			pOut->setCrntDrawColor(GREEN);
			pOut->setisFilled(false);
			Changefigurecolor(GREEN, 0);

			break;

		case BLUECLR:
			pOut->PrintMessage("The draw color will now be blue!");
			pOut->setCrntDrawColor(BLUE);
			pOut->setisFilled(false);
			Changefigurecolor(BLUE, 0);

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
			Changefigurecolor(BLACK, 1);

			break;

		case YELLOWCLR:
			pOut->PrintMessage("The fill color will now be yellow");
			pOut->setCrntFillColor(YELLOW);
			pOut->setisFilled(true);
			Changefigurecolor(YELLOW, 1);

			break;

		case ORANGECLR:
			pOut->PrintMessage("The fill color will now be orange");
			pOut->setCrntFillColor(ORANGE);
			pOut->setisFilled(true);
			Changefigurecolor(ORANGE, 1);

			break;

		case REDCLR:
			pOut->PrintMessage("The fill color will now be red");
			pOut->setCrntFillColor(RED);
			pOut->setisFilled(true);
			Changefigurecolor(RED, 1);

			break;

		case GREENCLR:
			pOut->PrintMessage("The fill color will now be green");
			pOut->setCrntFillColor(GREEN);
			pOut->setisFilled(true);
			Changefigurecolor(GREEN, 1);

			break;

		case BLUECLR:
			pOut->PrintMessage("The fill color will now be blue");
			pOut->setCrntFillColor(BLUE);
			pOut->setisFilled(true);
			Changefigurecolor(BLUE, 1);

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
			pOut->PrintMessage("Action: you pressed the black color");
			pOut->setCrntFillColor(BLACK);
			pOut->setCrntDrawColor(BLACK);
			Changefigurecolor(BLACK, 2);
			pOut->setisFilled(true);
			break;

		case YELLOWCLR:
			pOut->PrintMessage("Action: you pressed the yellow color");
			pOut->setCrntFillColor(YELLOW);
			pOut->setCrntDrawColor(YELLOW);
			pOut->setisFilled(true);
			Changefigurecolor(YELLOW, 2);

			break;

		case ORANGECLR:
			pOut->PrintMessage("Action: you pressed the orange color");
			pOut->setCrntFillColor(ORANGE);
			pOut->setCrntDrawColor(ORANGE);
			pOut->setisFilled(true);
			Changefigurecolor(ORANGE, 2);

			break;

		case REDCLR:
			pOut->PrintMessage("Action: you pressed the red color");
			pOut->setCrntFillColor(RED);
			pOut->setCrntDrawColor(RED);
			Changefigurecolor(RED, 2);

			pOut->setisFilled(true);
			break;

		case GREENCLR:
			pOut->PrintMessage("Action: you pressed the green color");
			pOut->setCrntFillColor(GREEN);
			pOut->setCrntDrawColor(GREEN);
			Changefigurecolor(GREEN, 2);

			pOut->setisFilled(true);
			break;

		case BLUECLR:
			pOut->PrintMessage("Action: you pressed the blue color");
			pOut->setCrntFillColor(BLUE);
			pOut->setCrntDrawColor(BLUE);
			pOut->setisFilled(true);
			Changefigurecolor(BLUE, 2);

			break;

		}


		pOut->deleteColorPalette();
		UI.conD = false;




	case EXIT:
		///create ExitAction here

		break;

	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
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
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
	pFig->setID(FigCount);

}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	for (int i = 0; i < FigCount; i++) {
		if(FigList[i]->IsInsideFigure(x,y)) return FigList[i];
	}
	return NULL;
}


void ApplicationManager::SetSelectedFigure(CFigure* pFig) {
	SelectedFig = pFig;
}

CFigure* ApplicationManager::GetSelectedFigure() const {
	return SelectedFig;
}

void ApplicationManager::deselectall() const {
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->SetSelected(false);
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
		if (FigList[i]->IsSelected())
		{
			delete FigList[i];
			FigList[i] = FigList[FigCount-1];
			FigList[i]->setID(i + 1);
			FigCount--;
			FigList[FigCount] = NULL;
			flag = false;
		}
}
void ApplicationManager::Changefigurecolor(color c,int type)
{
	bool flag = true;
	for (int i = 0; i < FigCount&&flag; i++)
	if (FigList[i]->IsSelected())
	{
		FigList[i]->SetSelected(false);
		if (type == 0) {
			FigList[i]->ChngDrawClr(c);
		}
		else if (type == 1) {
			FigList[i]->ChngFillClr(c);
		}
		else if (type == 2) {
			FigList[i]->ChngFillClr(c);
			FigList[i]->ChngDrawClr(c);
		}
		flag = false;
	}
}
void ApplicationManager::movefigure(Point New)
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsSelected())
			FigList[i]->Move(New);
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface

void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
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
