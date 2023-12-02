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