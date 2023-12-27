#include "CSquare.h"

CSquare::CSquare() : CFigure(FigGfxInfo)
{
	SqrSize = 160;
	figtype = square;
}

CSquare::CSquare(Point P1,  GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	SqrSize = 160;
	Centre = P1;
	figtype = square;
	OldestCentre = Centre;
}
void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pOut->DrawSqr(Centre, FigGfxInfo, Selected, SqrSize);
}

bool CSquare::IsInsideFigure(int x, int y) const{
	Point p3, p4;
	p3.x = Centre.x + SqrSize / 2;
	p3.y = Centre.y - SqrSize / 2;
	p4.x = Centre.x - SqrSize / 2;
	p4.y = Centre.y + SqrSize / 2;

	if (x >= p4.x && x <= p3.x && y >= p3.y && y <= p4.y) return true;
	else return false;
}

void CSquare::Move(Point NewCenter)
{
	OldCentre = Centre;
	Centre = NewCenter;
}

void CSquare::Resize(Point NewPoint)
{
	SqrSize = 2 * abs(Centre.y - NewPoint.y);
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQUARE" << "     ";
	OutFile << ID << "     ";
	OutFile << Centre.x << "     ";
	OutFile << Centre.y << "     ";
	OutFile << getClr(FigGfxInfo.DrawClr) << "     ";
	if (FigGfxInfo.isFilled)
		OutFile << getClr(FigGfxInfo.FillClr) << "     ";
	else
		OutFile << "NO_FILL" << "     ";
	OutFile << SqrSize << endl;//we have to add this after doing the resize operation
}

void CSquare::Load(ifstream& Infile)
{
	string clr;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Infile >> ID >> Centre.x >> Centre.y;
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
	Infile >> SqrSize;
}

void CSquare::StartEndRecord(ofstream& OutFile)
{
	OutFile << "SQUARE" << "     ";
	OutFile << ID << "     ";
	OutFile << Centre.x << "     ";
	OutFile << Centre.y << "     ";
	OutFile << SqrSize << "     ";//we have to add this after doing the resize operation
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

void CSquare::PlayRecord(ifstream& Infile)
{
	string clr;
	string slc;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Infile >> ID >> Centre.x >> Centre.y>>SqrSize;
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

Point CSquare::ReturnCenter() const
{
	return Centre;
}

Point CSquare::ReturnOldCenter()const
{
	return OldCentre;
}

Point CSquare::ReturnOldestCenter() const
{
	return OldestCentre;
}

void CSquare::PrintInfo(Output* pOut) {
	string message = "Square: Centre= (" + to_string(Centre.x) + " ," + to_string(Centre.y) + " )";
	pOut->PrintMessage(message);
}
