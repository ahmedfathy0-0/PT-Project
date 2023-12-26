#pragma once
#include"ApplicationManager.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
#include"Actions/Action.h"
#include"Figures/CFigure.h"
#include"DEFS.h";
#include<cstring>
class SwitchToDrawAction:public Action
{
public:
	SwitchToDrawAction(ApplicationManager*);
	void ReadActionParameters();
	void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
};

