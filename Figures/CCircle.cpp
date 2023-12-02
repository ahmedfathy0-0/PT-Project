#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	point = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Circle on the screen	
	pOut->DrawCirc(Center, point, FigGfxInfo, Selected);
}