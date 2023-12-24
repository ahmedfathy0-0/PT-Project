#pragma once
#include"../../ApplicationManager.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
#include"../Actions/Action.h"
#include"../Figures/CFigure.h"
#include"../DEFS.h"
#include<cstring>
#include"PickByFig.h"
#include"PickByFillClr.h"
#include"PickByFig.h"
#include"PickByFillClr.h"
class PickByFig;
class PickByFillClr;
class PickByBoth :public Action
{
private:
	Point P;
	CFigure* ptrRandom;
	PickByFig* ptrToPickByFig;
	PickByFillClr* ptrToPickByFill;
public:
	PickByBoth(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	CFigure* Randomize();
	void RightCase(CFigure*, int&, int&);
	void WrongCase(CFigure*, int&, int&);
	void RestartGame();
	void ReturnToDrawMidGame();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
};

