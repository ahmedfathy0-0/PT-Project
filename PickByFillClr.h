#pragma once
#include"ApplicationManager.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
#include"Actions/Action.h"
#include"Figures/CFigure.h"
#include"DEFS.h"
#include<cstring>
#include"PickByFig.h"
class PickByFig;
class PickByFillClr:public Action
{private:
	Point P;
	CFigure* ptrRandom;
	PickByFig* ptrToPickByFig;
public:
	PickByFillClr(ApplicationManager* pApp);

	CFigure* RandomizeClr();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
};

