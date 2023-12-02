#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "Action.h"

//Add Square Action class
class AddSqrAction : public Action
{
private:
	Point P1;
	GfxInfo RectGfxInfo;
public:
	AddSqrAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif