#pragma once

#ifndef CHANGE_COLOR_H
#define CHANGE_COLOR_H
#include "Action.h"
#include "../Figures/CFigure.h"
#include "..\ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"


class Changecolor : public Action
{
private:
	CFigure* pFig;
	color Color;
	string name;
	int Type;//draw color or fill color or both of them
public:
	Changecolor(ApplicationManager* pApp,color c ,string nam,int type);
	virtual void ReadActionParameters( );
	virtual void Execute();
};

#endif