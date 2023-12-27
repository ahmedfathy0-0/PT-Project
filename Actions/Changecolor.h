#pragma once

#ifndef CHANGE_COLOR_H
#define CHANGE_COLOR_H
#include "Action.h"
#include "../Figures/CFigure.h"
#include "..\ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"


class ChangeDrawcolor : public Action
{
private:
	CFigure* pFig;
	color OldColor;
	color NewColor;
	string name;
	Output* pOut;
	Input* pIn;
public:
	ChangeDrawcolor(ApplicationManager* pApp);
	virtual void ReadActionParameters( );
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
	virtual bool IsUndoable();
};

#endif