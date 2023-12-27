 #include "ChangeFillColor.h"

ChangeFillcolor::ChangeFillcolor(ApplicationManager* pApp) : Action(pApp) {}

void ChangeFillcolor::ReadActionParameters()
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pFig = pManager->GetSelectedFigure();
}

void ChangeFillcolor::Execute()
{
	ReadActionParameters();

	if (pFig != NULL) 
	{
		OldColor = pFig->CGetFillClr();
		if (pOut->getCrntFillColor() == pFig->CGetFillClr()) 
		{
			pFig->setisFilled(false);
			pOut->setisFilled(false);
			NewColor = UI.BkGrndColor;
		}
		else
		{
			pFig->ChngFillClr(pOut->getCrntFillColor());
			NewColor = pFig->CGetFillClr();
		}
		pManager->deselectall();
	}

}

Action* ChangeFillcolor::Clone()
{
	return new ChangeFillcolor(*this);
}

void ChangeFillcolor::Undo()
{
	if (pFig)
	{
		pFig->ChngFillClr(OldColor);
		OldColor = NewColor;
		NewColor = pFig->CGetFillClr();
		if (NewColor == UI.BkGrndColor)
			pFig->SetIsFilled(false);
}
	pManager->RecordFigure(pFig);
}

void ChangeFillcolor::Redo()
{
	if (pFig) 
	{
		pFig->ChngFillClr(OldColor);
		OldColor = NewColor;
		NewColor = pFig->CGetFillClr();
		if (NewColor == UI.BkGrndColor)
			pFig->SetIsFilled(false);
	}
	pManager->RecordFigure(pFig);
}

bool ChangeFillcolor::IsUndoable()
{
	return true;
}
