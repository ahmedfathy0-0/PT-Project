#ifndef MOVE_ACTION_H
#define MOVE_ACTION_H
#include "Action.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Figures/CFigure.h"
#include <fstream>


class MoveAction : public Action
{
private:
	Point NewCenter;
	Point OldCenter;
	CFigure* pFig;
	Output* pOut;
	Input* pIn;
public :
	MoveAction(ApplicationManager* pApp);//Garbage intial value if its garabge getpoint from the user
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
	virtual bool IsUndoable();
};

#endif