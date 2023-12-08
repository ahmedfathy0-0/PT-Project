#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
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

/*void CRectangle::PrintInfo(Output* pOut) const {
	string message = "Rectangle: Corner 1= (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2= (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	pOut->PrintMessage(message);
}*/