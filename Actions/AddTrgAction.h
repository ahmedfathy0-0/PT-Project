#ifndef ADD_TRG_ACTION_H
#define ADD_TRG_ACTION_H

#include "Action.h"
#include "..\Figures\CTriangle.h"

//Add Triangle Action class
class AddTrgAction : public Action
{
private:
	Point P1, P2,P3; //Triangle Corners
	GfxInfo RectGfxInfo;
	CTriangle* T;
public:
	AddTrgAction(ApplicationManager* pApp);

	//Reads Triangle parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
	virtual bool IsUndoable();
};

#endif