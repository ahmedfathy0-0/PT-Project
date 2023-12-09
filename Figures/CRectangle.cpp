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
	Infile >> clr;
	FigGfxInfo.DrawClr = getClr(clr);
	Infile >> clr;
	if (clr == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = GREEN;
	}
	else
		FigGfxInfo.FillClr = getClr(clr);
}

/*void CRectangle::PrintInfo(Output* pOut) const {
	string message = "Rectangle: Corner 1= (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2= (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	pOut->PrintMessage(message);
}*/