#ifndef UNDO_ACTION_H
#define UNDO_ACTION_H
#include "Action.h"
#include "../Figures/CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class UndoAction :public Action
{
	Action* ReturnedAction;
public:
	UndoAction(ApplicationManager* pApp, Action* A=NULL);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
};
#endif