#include "CRectangle.h"

CRectangle::CRectangle() : CFigure(FigGfxInfo)
{
	figtype = rectangle;
}

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	figtype = rectangle;
	OldestCenter = Center;
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

void CRectangle::Resize(Point NewPoint)
{
	Point* NearestPoint = NewPoint.IsNeartoWhich(&Corner1, &Corner2);
	NearestPoint->x = NewPoint.x;
	NearestPoint->y = NewPoint.y;
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
		FillClr = No_Fill;
	}
	else
	{
		FigGfxInfo.FillClr = getClr(clr);
		UI.FillColor = FigGfxInfo.FillClr;
		if (UI.FillColor == RED)
		{
			FillClr = Red;
		}
		if (UI.FillColor == BLUE)
		{
			FillClr = Blue;
		}
		if (UI.FillColor == GREEN)
		{
			FillClr = Green;
		}
		if (UI.FillColor == ORANGE)
		{
			FillClr = Orange;
		}
		if (UI.FillColor == YELLOW)
		{
			FillClr = Yellow;
		}
		if (UI.FillColor == BLACK)
		{
			FillClr = Black;
		}
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
		OutFile << "SELECTED" << "     ";
	else
		OutFile << "NOT_SELECTED" << "     ";
	if (this->isHidden)
		OutFile << "HIDDEN" << endl;
	else
		OutFile << "NOT_HIDDEN" << endl;
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
	Infile >> slc;
	if (slc == "HIDDEN")
	{
		this->IsHidden(true);
	}
	else
		this->IsHidden(false);
}

Point CRectangle::ReturnCenter() const 
{
	return Center;
}

Point CRectangle::ReturnOldCenter() const 
{
	return OldCenter;
}

Point CRectangle::ReturnOldestCenter() const
{
	return OldestCenter;
}

void CRectangle::PrintInfo(Output* pOut)  {
	string message = "Rectangle: Corner 1= (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2= (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	pOut->PrintMessage(message);
}