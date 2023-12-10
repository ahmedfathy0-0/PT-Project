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
	string filename;
	string type;
	int NO_OF_FIGS;
	ifstream fIn;
public :
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	color getclr(string);
};

#endif