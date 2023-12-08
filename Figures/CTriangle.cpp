#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2,Point P3,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;

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

/*void CTriangle::PrintInfo(Output* pOut) const {
	string message = "Triangle: Corner 1= (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2= (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), Corner 3= (" + to_string(Corner3.x)
		+ "," + to_string(Corner3.y) + ")";
	pOut->PrintMessage(message);
}*/