#include "CHexagon.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}