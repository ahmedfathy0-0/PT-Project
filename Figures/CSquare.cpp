#include "CSquare.h"

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

/*void CSquare::PrintInfo(Output* pOut) const {
	string message = "Circle: Centre= (" + to_string(Centre.x) + " ," + to_string(Centre.y) + " )";
	pOut->PrintMessage(message);
}*/
