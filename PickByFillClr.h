#pragma once
#include"ApplicationManager.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
#include"Actions/Action.h"
#include"Figures/CFigure.h"
#include"DEFS.h";
#include<cstring>
class PickByFillClr:public Action
{
	Point P;
	CFigure* ptrRandom;
public:
	PickByFillClr(ApplicationManager* pApp);

	CFigure* RandomizeClr();
	virtual void ReadActionParameters();
	virtual void Execute();
};

