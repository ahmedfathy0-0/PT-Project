#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFigure;

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;
	bool IsRecording;
	ofstream Recordfile;//used for save kids operations in the game
	int OPcount;//used for max 20 operation
	Action* UndoableActions[5];
	Action* RedoableActions[5];
	int UndoableActionsCount;
	int RedoableActionsCount;
public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	int GetFigCount();
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void Changefigurecolor(color, int);//the integer here represent the type of change color 
	//if = 0 change draw color if =1 change fillcolor if =-1 change both 
	void SaveAll(ofstream& OutFile) const;
	void Clearall();
	void deletefigure();
	// functions for the Start,Stop,and Play Record  action//
	void StartRecord(string) ;
	void RecordFigure(CFigure*); //to record any changes in draw mode
	ofstream* getRecoedFile();//send the file address to any class Action
	bool getIsRecording();//send the Recording boolean to any class Action


	// functions for the select action//
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void IsInsideFigure(CFigure* pFig);
	void SetSelectedFigure(CFigure* pFig);
	CFigure* GetSelectedFigure() const;
	void deselectall();

	//Functions for the undo action

	void AddAction(Action*);
	Action* ReturnLastUndoableAction();
	void AddToRedo(Action*);

	Action* ReturnLastRedoableAction();
	void ClearRedoList();

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void UpdateBuffer(bool) const;

	//Functions for PickAndHide
	CFigure* GetFigByIndex(int i);
	int RandomizedFigCount(CFigure*);
	void UnHideFigures();
	bool CheckForFillColor();
	int RandomizedFillClrCount(CFigure*);
	Action* GetActionType();
};

#endif