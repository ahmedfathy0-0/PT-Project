#include "CTriangle.h"

CTriangle::CTriangle() : CFigure(FigGfxInfo)
{

}

CTriangle::CTriangle(Point P1, Point P2,Point P3,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	figtype = triangle;

}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Triangle on the screen	
	pOut->DrawTr(Corner1,Corner2,Corner3, FigGfxInfo, Selected);
}

bool CTriangle::IsInsideFigure(int x, int y) const 
{
	Point P;
	P.x = x;
	P.y = y;
	double BigTriangleArea = CalculateArea(Corner1, Corner2, Corner3);
	double firstSmallArea = CalculateArea(Corner1, Corner2, P);
	double SecondSmallArea = CalculateArea(Corner1, Corner3, P);
	double thirdSmallArea = CalculateArea(Corner2, Corner3, P);

	if (BigTriangleArea == firstSmallArea + SecondSmallArea + thirdSmallArea) return true;
	else return false;
}

double CTriangle::CalculateArea(Point P1, Point P2, Point P3) const{
	return 0.5 * fabs((P1.x * (P2.y - P3.y)) + (P2.x * (P3.y - P1.y)) + (P3.x * (P1.y - P2.y)));
}

void CTriangle::Move(Point NewCenter)
{
	OldCenter = Center;
	Corner1.x = Corner1.x + NewCenter.x - Center.x;
	Corner1.y = Corner1.y + NewCenter.y - Center.y;
	Corner2.x = Corner2.x + NewCenter.x - Center.x;
	Corner2.y = Corner2.y + NewCenter.y - Center.y;
	Corner3.x = Corner3.x + NewCenter.x - Center.x;
	Corner3.y = Corner3.y + NewCenter.y - Center.y;
	Center = NewCenter;
}

void CTriangle::Resize(Point NewPoint)
{
	Point* Nearest2Point = NewPoint.IsNeartoWhich(&Corner1, &Corner2);
	Point* NearestPoint = NewPoint.IsNeartoWhich(Nearest2Point, &Corner3);
	NearestPoint->x = NewPoint.x;
	NearestPoint->y = NewPoint.y;

}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << "TRIANG" << "     ";
	OutFile << ID << "     ";
	OutFile << Corner1.x << "     ";
	OutFile << Corner1.y << "     ";
	OutFile << Corner2.x << "     ";
	OutFile << Corner2.y << "     ";
	OutFile << Corner3.x << "     ";
	OutFile << Corner3.y << "     ";
	OutFile << getClr(FigGfxInfo.DrawClr) << "     ";
	if (FigGfxInfo.isFilled)
		OutFile << getClr(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

void CTriangle::Load(ifstream& Infile)
{
	string clr;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
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

void CTriangle::StartEndRecord(ofstream& OutFile)
{
	OutFile << "TRIANG" << "     ";
	OutFile << ID << "     ";
	OutFile << Corner1.x << "     ";
	OutFile << Corner1.y << "     ";
	OutFile << Corner2.x << "     ";
	OutFile << Corner2.y << "     ";
	OutFile << Corner3.x << "     ";
	OutFile << Corner3.y << "     ";
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

void CTriangle::PlayRecord(ifstream& Infile)
{
	string clr;
	string slc;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
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
	Infile >> slc;
	if (slc == "SELECTED")
	{
		this->SetSelected(true);
	}
	else
		this->SetSelected(false);
}

Point CTriangle::ReturnCenter()const
{
	return Center;
}

Point CTriangle::ReturnOldCenter()const
{
	return OldCenter;
}

void CTriangle::PrintInfo(Output* pOut) {
	string message = "Triangle: Corner 1= (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2= (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Corner 3= (" + to_string(Corner3.x)
		+ "," + to_string(Corner3.y) + ")";
	pOut->PrintMessage(message);
}