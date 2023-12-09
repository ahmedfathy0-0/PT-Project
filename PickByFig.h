#pragma once
#include"ApplicationManager.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
#include"Actions/Action.h"
class PickByFig :public Action
{
public:
	PickByFig(ApplicationManager* pApp);
	
	CFigure* Randomize();
	virtual void ReadActionParameters();
	virtual void Execute();
};

