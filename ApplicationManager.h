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


	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;
	bool IsRecording;
	ofstream Recordfile;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType, ActionType, ActionType); //Creates an action and executes it
	int GetFigCount();
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void Changefigurecolor(color, int);//the integer here represent the type of change color 
	//if = 0 change draw color if =1 change fillcolor if =-1 change both 
	void SaveAll(ofstream& OutFile) const;
	void Clearall();
	void deletefigure();
	void movefigure(Point New);
	// functions for the Start,Stop,and Play Record  action//
	void StartRecord(string) ;

	// functions for the select action//
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void IsInsideFigure(CFigure* pFig);
	void SetSelectedFigure(CFigure* pFig);
	CFigure* GetSelectedFigure() const;
	void deselectall() ;

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	//Functions for PickAndHide
	CFigure* GetFigByIndex(int i);
	int RandomizedFigCount();
	
};

#endif