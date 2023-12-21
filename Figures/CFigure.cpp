#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	isHidden = false;
	ID = 0;
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
	if (Fclr == RED)
	{
		FillClr = Red;
	}
	if (Fclr == BLUE)
	{
		FillClr = Blue;
	}
	if (Fclr == GREEN)
	{
		FillClr = Green;
	}
	if (Fclr == ORANGE)
	{
		FillClr = Orange;
	}
	if (Fclr == YELLOW)
	{
		FillClr = Yellow;
	}
	if (Fclr == BLACK)
	{
		FillClr = Black;
	}

}

bool CFigure::isfilled()
{
	return FigGfxInfo.isFilled;
}

int CFigure::GetFillClr()
{
	return FillClr;
}

double CFigure::CalculateDistance(Point P1, Point P2) const{
	return sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
}

void CFigure::setID(int i)
{
	ID = i;
}

int CFigure::getID() const
{
	return ID;
}

int CFigure::type()
{
	return figtype;
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
	else
		return BLUE;
}
bool CFigure::getselected(string select)
{
	if (select == "SELECTED")
		return 1;
	else if (select == "NOT_SELECTED")
		return 0;

}
void CFigure::IsHidden(bool b)
{
	isHidden = b;
}

void CFigure::SetHidden(bool b)
{
	isHidden = b;
}

bool CFigure::GetHiddenStatus()
{
	return isHidden;
}

