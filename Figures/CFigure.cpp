#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 

}

double CFigure::CalculateDistance(Point P1, Point P2) const{
	return sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
}

void CFigure::setID(int i)
{
	ID = i;
}

string CFigure::getClr(color Dclr)
{
	if (Dclr == BLACK)
		return "BLACK";
	else if (Dclr == YELLOW)
		return "YELLOW";
	else if (Dclr == ORANGE)
		return "ORANGE";
	else if (Dclr == RED)
		return "RED";
	else if (Dclr == GREEN)
		return "GREEN";
	else if (Dclr == BLUE)
		return "BLUE";
}
color CFigure::getClr(string Dclr)
{
	if (Dclr == "BLACK")
		return BLACK;
	else if (Dclr == "YELLOW")
		return YELLOW;
	else if (Dclr == "ORANGE")
		return ORANGE;
	else if (Dclr == "RED")
		return RED;
	else if (Dclr == "GREEN")
		return GREEN;
	else if (Dclr == "BLUE")
		return BLUE;
}

