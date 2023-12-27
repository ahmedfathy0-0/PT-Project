#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Figures/CFigure.h"
#include <fstream>


class MoveDragAction : public Action
{
private:
	Point NewCenter;
	CFigure* pFig;
	Output* pOut;
	Input* pIn;
	Point C;
public :
	MoveDragAction(ApplicationManager* pApp);//Garbage intial value if its garabge getpoint from the user
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
	virtual bool IsUndoable();
};