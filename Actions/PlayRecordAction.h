#pragma once
#ifndef PLAY_RECORD_H
#define PLAY_RECORD_H
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <fstream>

class PlayRecordAction : public Action
{
private:
	Output* pOut;
	Input* pIn;
	string filename;
	string type;
	int NO_OF_FIGS;
	ifstream fIn;
public:
	PlayRecordAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	color getclr(string);
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
};

#endif
