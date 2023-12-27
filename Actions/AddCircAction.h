#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "Action.h"
#include "..\Figures\CCircle.h"

//Add Circle Action class
class AddCircAction : public Action
{
private:
	Point P1,P2; //Circle Center and point
	GfxInfo RectGfxInfo;
	CCircle* C;
public:
	AddCircAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
	virtual bool IsUndoable();
};

#endif