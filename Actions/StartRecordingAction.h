#ifndef STARTRECORD_ACTION_H
#define STARTRECORD_ACTION_H
#include "Action.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <fstream>

class StartRecordingAction : public Action
{
private:
	string filename;
	ofstream fout;
protected:
	string getClr(color Dclr);
public:
	StartRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual Action* Clone();
	virtual void Undo();
	virtual void Redo();
};

#endif