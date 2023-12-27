#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "Action.h"
#include "..\Figures\CHexagon.h"

//Add Hexagon Action class
class AddHexAction : public Action
{
private:
	Point P1; //Hexagon Centers
	GfxInfo RectGfxInfo;
	CHexagon* H;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
	virtual bool IsUndoable();
};

#endif