#ifndef DELETE_H
#define DELETE_H

#include "Action.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

class DeleteAction : public Action
{
	CFigure* pFig;
	Output* pOut;
public:
	DeleteAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
	virtual bool IsUndoable();
};

#endif