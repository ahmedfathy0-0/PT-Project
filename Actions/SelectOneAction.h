#ifndef SELECT_ONE_ACTION_H
#define SELECT_ONE_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

class SelectOneAction :public Action {

	Point P;
	
public:

	SelectOneAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif
