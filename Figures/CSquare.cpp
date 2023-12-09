#include "CSquare.h"

CSquare::CSquare() : CFigure(FigGfxInfo)
{
}

CSquare::CSquare(Point P1,  GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
	
}
void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pOut->DrawSqr(Centre, FigGfxInfo, Selected);
}

bool CSquare::IsInsideFigure(int x, int y) const{
	Point p3, p4;
	p3.x = Centre.x + UI.SqrSize / 2;
	p3.y = Centre.y - UI.SqrSize / 2;
	p4.x = Centre.x - UI.SqrSize / 2;
	p4.y = Centre.y + UI.SqrSize / 2;

	if (x >= p4.x && x <= p3.x && y >= p3.y && y <= p4.y) return true;
	else return false;
}

void CSquare::Move(Point NewCenter)
{
	Centre = NewCenter;
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << "SQUARE" << "     ";
	OutFile << ID << "     ";
	OutFile << Centre.x << "     ";
	OutFile << Centre.y << "     ";
	OutFile << getClr(FigGfxInfo.DrawClr) << "     ";
	if (FigGfxInfo.isFilled)
		OutFile << getClr(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
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
	}
	else
		FigGfxInfo.FillClr = getClr(clr);
}

/*void CSquare::PrintInfo(Output* pOut) const {
	string message = "Circle: Centre= (" + to_string(Centre.x) + " ," + to_string(Centre.y) + " )";
	pOut->PrintMessage(message);
}*/
