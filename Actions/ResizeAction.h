#pragma once
#ifndef RESIZE_H
#define RESIZE_H

#include "Action.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Figures/CFigure.h"
#include <fstream>
//Add Circle Action class
class ResizeAction : public Action
{
private:
	Output* pOut;
	Input* pIn;
	Point P1; //Circle Center and point
	CFigure* pFig;

public:
	ResizeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

#endif