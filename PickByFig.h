#pragma once
#include"ApplicationManager.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class PickByFig :public Action
{private:
	Point P;
	enum WhichFigFromRandom
	{
		Circle,
		Hexagon,
		Rectangle,
		Square,
		Triangle
	};
	WhichFigFromRandom FigureToPick;
public:
	PickByFig(ApplicationManager* pApp);
	
	CFigure* Randomize();
	virtual void ReadActionParameters();
	virtual void Execute();
};

