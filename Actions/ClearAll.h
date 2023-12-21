#ifndef CLEAR_ALL_H
#define CLEAR_ALL_H

#include "Action.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

class ClearAll : public Action
{
private:
	ofstream ClearRecord;
public:
	ClearAll(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
};

#endif