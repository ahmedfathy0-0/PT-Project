#ifndef MOVE_ACTION_H
#define MOVE_ACTION_H
#include "Action.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

class MoveAction : public Action
{
private:
	Point NewCenter;
public :
	MoveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif