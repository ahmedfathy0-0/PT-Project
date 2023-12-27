#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <fstream>

class LoadAction : public Action
{
private:
	string filename, type, fillcolor;
	int NO_OF_FIGS;
	ifstream fIn;
	Output* pOut;
	Input* pIn;
public :
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	color getclr(string);
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
	virtual bool IsUndoable();
};

#endif