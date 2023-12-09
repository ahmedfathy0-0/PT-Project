#include "CCircle.h"

CCircle::CCircle() : CFigure(FigGfxInfo)
{
}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = P1;
	point = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Circle on the screen	
	pOut->DrawCirc(Center, point, FigGfxInfo, Selected);
}

bool CCircle::IsInsideFigure(int x, int y) const {
	Point P;
	P.x = x; 
	P.y = y;
	if (CalculateDistance(Center, point) >= CalculateDistance(Center, P)) {
		return true;
	}
	else return false;
}

void CCircle::Move(Point NewCenter)
{
	point.x += NewCenter.x - Center.x;
	point.y += NewCenter.y - Center.y;
	Center = NewCenter;
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << "CIRCLE" << "     ";
	OutFile << ID << "     ";
	OutFile << Center.x << "     ";
	OutFile << Center.y << "     ";
	OutFile << point.x << "     ";
	OutFile << point.y << "     ";
	OutFile << getClr(FigGfxInfo.DrawClr) << "     ";
	if (FigGfxInfo.isFilled)
		OutFile << getClr(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

/*void CCircle::PrintInfo(Output* pOut) const {
	string message = "Circle, Center = (" + to_string(Center.x) + "," + to_string(Center.y)
		+ "), Radius: " + to_string(int(CalculateDistance(Center,point)));
	pOut->PrintMessage(message);
}*/