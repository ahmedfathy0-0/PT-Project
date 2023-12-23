#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "Action.h"
#include "..\Figures\CSquare.h"

//Add Square Action class
class AddSqrAction : public Action
{
private:
	Point P1;
	GfxInfo RectGfxInfo;
	CSquare* S;
	bool Sound;
public:
	AddSqrAction(ApplicationManager* pApp, bool s = false);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
};

#endif