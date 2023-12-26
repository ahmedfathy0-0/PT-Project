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
	bool IsMute;
	bool ISPLYING;
	ofstream Recordfile;//used for save kids operations in the game
	int OPcount;//used for max 20 operation
	Action* UndoableActions[5];
	Action* RedoableActions[5];
	int UndoableActionsCount;
	int RedoableActionsCount;
	CFigure* DeletedArray[5];
	int DeletedActionsCount;
public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	int GetFigCount();//getter for number of drawn figures
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void Changefigurecolor(color, int);//the integer here represent the type of change color 
	//if = 0 change draw color if =1 change fillcolor if =-1 change both 
	
	//function of save
	void SaveAll(ofstream& OutFile) const; //call the save functions of all figures drawn

	//functions of clear all
	void Clearall(); //clear all figures and delete it
	void ClearUndoList(); //clear undo history
	void ClearRedoList(); //clear redo history
	void ClearDeleteList(); //clear the rest of undo & redo history
	void ResetConstants(); // reset UI constants like colors and sizes

	//fuction of delete
	void deletefigure(CFigure*); // delete figure and shift the rest


	// functions for the Start,Stop,and Play Record  action//
	void StartRecord(string) ;
	void StopRecord();
	void RecordFigure(CFigure*); //to record any changes in draw mode
	ofstream* getRecoedFile();//send the file address to any class Action
	bool getIsRecording();//send the Recording boolean to any class Action
	void setISPlaying(bool flg);

	// functions for the select action//
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SetSelectedFigure(CFigure* pFig);
	CFigure* GetSelectedFigure() const;
	void deselectall();

	//Functions for the undo action

	void AddAction(Action*);
	Action* ReturnLastUndoableAction();
	void AddToRedo(Action*);

	Action* ReturnLastRedoableAction();

	void AddToDeleteList(CFigure *);


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
	int RandomizedPickByBothCount(CFigure*);
	
};

#endif