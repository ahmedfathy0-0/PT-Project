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