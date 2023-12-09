#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include"DEFS.h"
#include"Figures/CFigure.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
class PickAndHide:public Action
{

	PickAndHide(ApplicationManager* pApp) :Action(pApp)
	{

	}
	virtual CFigure* Randomize() = 0;
	
	
};

