#pragma once
#include"../../ApplicationManager.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
#include"../Actions/Action.h"
#include"../Figures/CFigure.h"
#include"../../DEFS.h"
#include<cstring>
#include"PickByFig.h"
#include"PickByBoth.h"
class PickByBoth;
class PickByFig;
class PickByFillClr:public Action
{private:
	Point P;
	CFigure* ptrRandom;
	PickByFig* ptrToPickByFig;
	PickByBoth* ptrToPickByBoth;
public:
	PickByFillClr(ApplicationManager* pApp);
	void RightCase(CFigure*, int&, int&);
	void WrongCase(CFigure*, int&, int&);
	CFigure* RandomizeClr();
	void RestartGame();
	void ReturnToDrawMidGame();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
};

