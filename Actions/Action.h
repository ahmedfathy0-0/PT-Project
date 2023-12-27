#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include "..\CMUgraphicsLib\auxil.h"
#include <Windows.h>

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	virtual Action* Clone() = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
	//Execute action (code depends on action type)
	virtual void Execute() =0;
	virtual bool IsUndoable();

};

#endif