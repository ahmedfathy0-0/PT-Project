#include "Exit.h"


Exit::Exit(ApplicationManager*pApp):Action(pApp)
{
}

void Exit::ReadActionParameters()
{
	pManager->GetUserAction();
}

void Exit::Execute()
{
	Output* pOut=pManager->GetOutput();
	pOut->PrintMessage("Click anywhere to exit");
	ReadActionParameters();
	if (!pOut->getSound())
		PlaySound(("Sounds\\Exit.wav"), NULL, SND_ASYNC);
	Pause(1000);
}

Action* Exit::Clone()
{
	return nullptr;
}

void Exit::Undo()
{
}

void Exit::Redo()
{
}

