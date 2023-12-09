#include "PickByFig.h"
CFigure* PickByFig::Randomize()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("No drawn figures...Please draw some figures first:)");
			return NULL;
	}
	srand(time(0));
	int Random_Index = rand() % ((pManager->GetFigCount() + 1));
}