#include "CRectangle.h"

CRectangle::CRectangle() : CFigure(FigGfxInfo)
{

}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	figtype = rectangle;

}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsInsideFigure(int x, int y) const{
	int maxY = max(Corner1.y, Corner2.y);
	int maxX = max(Corner1.x, Corner2.x);
	int minY = min(Corner1.y, Corner2.y);
	int minX = min(Corner1.x, Corner2.x);
	if (x >= minX && x <= maxX && y >= minY && y <= maxY) return true;
	else return false;
}

void CRectangle::Move(Point NewCenter)
{
	OldCenter = Center;
	Corner1.x += NewCenter.x - Center.x;
	Corner1.y += NewCenter.y - Center.y;
	Corner2.x += NewCenter.x - Center.x;
	Corner2.y += NewCenter.y - Center.y;
	Center = NewCenter;
}

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << "RECTAN" << "     ";
	OutFile << ID << "     ";
	OutFile << Corner1.x << "     ";
	OutFile << Corner1.y << "     ";
	OutFile << Corner2.x << "     ";
	OutFile << Corner2.y << "     ";
	OutFile << getClr(FigGfxInfo.DrawClr) << "     ";
	if (FigGfxInfo.isFilled)
		OutFile << getClr(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

void CRectangle::Load(ifstream& Infile)
{
	string clr;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	Infile >> clr;
	FigGfxInfo.DrawClr = getClr(clr);
	Infile >> clr;
	if (clr == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = GREEN;
		UI.ISFILLED = false;
		UI.FillColor = GREEN;
	}
	else
	{
		FigGfxInfo.FillClr = getClr(clr);
		UI.FillColor = FigGfxInfo.FillClr;
	}
}

void CRectangle::StartEndRecord(ofstream& OutFile)
{
	OutFile << "RECTAN" << "     ";
	OutFile << ID << "     ";
	OutFile << Corner1.x << "     ";
	OutFile << Corner1.y << "     ";
	OutFile << Corner2.x << "     ";
	OutFile << Corner2.y << "     ";
	OutFile << getClr(FigGfxInfo.DrawClr) << "     ";
	if (FigGfxInfo.isFilled)
		OutFile << getClr(FigGfxInfo.FillClr) << "     ";
	else
		OutFile << "NO_FILL" << "     ";
	if (this->IsSelected())
		OutFile << "SELECTED" << endl;
	else
		OutFile << "NOT_SELECTED" << endl;
}

void CRectangle::PlayRecord(ifstream& Infile)
{
	string clr;
	string slc;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	Infile >> clr;
	FigGfxInfo.DrawClr = getClr(clr);
	Infile >> clr;
	if (clr == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.FillClr = getClr(clr);
	}
	Infile >> slc;
	if (slc == "SELECTED")
	{
		this->SetSelected(true);
	}
	else
		this->SetSelected(false);
}

Point CRectangle::ReturnOldCenter()
{
	return OldCenter;
}

void CRectangle::PrintInfo(Output* pOut)  {
	string message = "Rectangle: Corner 1= (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2= (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	pOut->PrintMessage(message);
}