#ifndef ADD_TRG_ACTION_H
#define ADD_TRG_ACTION_H

#include "Action.h"

//Add Triangle Action class
class AddTrgAction : public Action
{
private:
	Point P1, P2,P3; //Triangle Corners
	GfxInfo RectGfxInfo;
public:
	AddTrgAction(ApplicationManager* pApp);

	//Reads Triangle parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();

};

#endif