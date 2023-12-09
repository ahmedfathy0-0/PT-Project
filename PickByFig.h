#pragma once
#include"PickAndHide.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
class PickByFig:public PickAndHide
{
public:
	CFigure* Randomize();
	void Action::ReadActionParameters();
	void Action::Execute();
};

