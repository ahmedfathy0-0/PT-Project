#include "CHexagon.h"

CHexagon::CHexagon() : CFigure(FigGfxInfo)
{
	HexSize = 100;
	figtype = hexagon;
}

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	HexSize = 100;
	Center = P1;
	figtype = hexagon;
	OldestCenter = Center;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected, HexSize);
}

bool CHexagon::IsInsideFigure(int X, int Y) const 
{
	Point p3, p4;
	p3.x = Center.x + HexSize;
	p3.y = Center.y - HexSize *0.866;
	p4.x = Center.x - HexSize;
	p4.y = Center.y + HexSize *0.866;

	if (X >= p4.x && X <= p3.x && Y >= p3.y && Y <= p4.y)
	{

		///after findig that the hexagon is inside the rectangle or not we now need to find is the point in the four triangle remain or not
			//note: that the four triangle area +the hexagon area = rectangle area
			//first triangle
		Point P;
		Point Corner3;
		Point Corner2;
		Point Corner1;
		P.x = X;
		P.y = Y;
		Corner1.x = Center.x - HexSize;
		Corner1.y = Center.y - HexSize * 0.866;
		Corner2.x = Corner1.x + HexSize / 2;
		Corner2.y = Corner1.y;
		Corner3.x = Corner1.x;
		Corner3.y = Corner1.y + HexSize * 0.866;
		double BigTriangleArea1 = CalculateArea(Corner1, Corner2, Corner3);
		double firstSmallArea1 = CalculateArea(Corner1, Corner2, P);
		double SecondSmallArea1 = CalculateArea(Corner1, Corner3, P);
		double thirdSmallArea1 = CalculateArea(Corner2, Corner3, P);

		///second triangle
		Corner1.x += HexSize + HexSize / 2;
		//y coordianate of Corner1 is same here
		Corner2.x += HexSize + (HexSize) / 2;
		//y coordianate of Corner2 is same here
		Corner3.x += 2 * HexSize;
		//y coordianate of Corner3 is same here
		double BigTriangleArea2 = CalculateArea(Corner1, Corner2, Corner3);
		double firstSmallArea2 = CalculateArea(Corner1, Corner2, P);
		double SecondSmallArea2 = CalculateArea(Corner1, Corner3, P);
		double thirdSmallArea2 = CalculateArea(Corner2, Corner3, P);

		///third triangle
		Corner1.y +=2*(HexSize * 0.866);
		//x coordianate of Corner1 is same here
		Corner2.y += 2 * (HexSize * 0.866);
		//x coordianate of Corner2 is same here
		// coordianates of Corner3 is same here
		double BigTriangleArea3 = CalculateArea(Corner1, Corner2, Corner3);
		double firstSmallArea3 = CalculateArea(Corner1, Corner2, P);
		double SecondSmallArea3 = CalculateArea(Corner1, Corner3, P);
		double thirdSmallArea3 = CalculateArea(Corner2, Corner3, P);

		///Fourth triangle
		//coordianates of Corner1 is same here
		Corner2.x -= 2 * HexSize;
		//y coordianate of Corner2 is same here
		Corner3.x -= 2 * HexSize;
		// y coordianate of Corner3 is same here
		double BigTriangleArea4 = CalculateArea(Corner1, Corner2, Corner3);
		double firstSmallArea4 = CalculateArea(Corner1, Corner2, P);
		double SecondSmallArea4 = CalculateArea(Corner1, Corner3, P);
		double thirdSmallArea4 = CalculateArea(Corner2, Corner3, P);


		if ((BigTriangleArea1 == firstSmallArea1 + SecondSmallArea1 + thirdSmallArea1) || (BigTriangleArea2 == firstSmallArea2 + SecondSmallArea2 + thirdSmallArea2) || 
			(BigTriangleArea3 == firstSmallArea3 + SecondSmallArea3 + thirdSmallArea3) || (BigTriangleArea4 == firstSmallArea4 + SecondSmallArea4 + thirdSmallArea4)) 
		return false;
		else 
			return true;


	}





	else 
		return false;
}

double CHexagon::CalculateArea(Point P1, Point P2, Point P3) const {
	return 0.5 * fabs((P1.x * (P2.y - P3.y)) + (P2.x * (P3.y - P1.y)) + (P3.x * (P1.y - P2.y)));

}

void CHexagon::Move(Point NewCenter)
{
	OldCenter = Center;
	Center = NewCenter;
}

void CHexagon::Resize(Point NewPoint)
{
	HexSize = (abs(Center.y - NewPoint.y))/0.866;
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "HEXAGN" << "     ";
	OutFile << ID << "     ";
	OutFile << Center.x << "     ";
	OutFile << Center.y << "     ";
	OutFile << getClr(FigGfxInfo.DrawClr) << "     ";
	if (FigGfxInfo.isFilled)
		OutFile << getClr(FigGfxInfo.FillClr) << "     ";
	else
		OutFile << "NO_FILL" << "     ";
	OutFile << HexSize << endl; // we have to add this after doing the resize operation
}

void CHexagon::Load(ifstream& Infile)
{
	string clr;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Infile >> ID >> Center.x >> Center.y;
	Infile >> clr;
	FigGfxInfo.DrawClr = getClr(clr);
	Infile >> clr;
	if (clr == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = GREEN;
		UI.ISFILLED = false;
		FigGfxInfo.isFilled = false;
		FillClr = No_Fill;
	}
	else
	{
		FigGfxInfo.FillClr = getClr(clr);
		UI.FillColor = FigGfxInfo.FillClr;
		if (UI.FillColor == RED)
		{
			FillClr = Red;
		}
		if (UI.FillColor == BLUE)
		{
			FillClr = Blue;
		}
		if (UI.FillColor == GREEN)
		{
			FillClr = Green;
		}
		if (UI.FillColor == ORANGE)
		{
			FillClr = Orange;
		}
		if (UI.FillColor == YELLOW)
		{
			FillClr = Yellow;
		}
		if (UI.FillColor == BLACK)
		{
			FillClr = Black;
		}
	}
	Infile >> HexSize;
}

void CHexagon::StartEndRecord(ofstream& OutFile)
{
	OutFile << "HEXAGN" << "     ";
	OutFile << ID << "     ";
	OutFile << Center.x << "     ";
	OutFile << Center.y << "     ";
	OutFile << HexSize << "     "; // we have to add this after doing the resize operation
	OutFile << getClr(FigGfxInfo.DrawClr) << "     ";
	if (FigGfxInfo.isFilled)
		OutFile << getClr(FigGfxInfo.FillClr) << "     ";
	else
		OutFile << "NO_FILL" << "     ";
	if (this->IsSelected())
		OutFile << "SELECTED" << "     ";
	else
		OutFile << "NOT_SELECTED" << "     ";
	if (this->isHidden)
		OutFile << "HIDDEN" << endl;
	else
		OutFile << "NOT_HIDDEN" << endl;
}
void CHexagon::PlayRecord(ifstream& Infile)
{
	string clr;
	string slc;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Infile >> ID >> Center.x >> Center.y >> HexSize;
	Infile >> clr;
	FigGfxInfo.DrawClr = getClr(clr);
	Infile >> clr;
	if (clr == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		FigGfxInfo.FillClr = GREEN;
		UI.ISFILLED = false;
		UI.FillColor = GREEN;
	}
	else
	{
		FigGfxInfo.FillClr = getClr(clr);
		UI.FillColor = FigGfxInfo.FillClr;
	}
	Infile >> slc;
	if (slc == "SELECTED")
	{
		this->SetSelected(true);
	}
	else
		this->SetSelected(false);
	Infile >> slc;
	if (slc == "HIDDEN")
	{
		this->IsHidden(true);
	}
	else
		this->IsHidden(false);

}

Point CHexagon::ReturnCenter() const
{
	return Center;
}

Point CHexagon::ReturnOldCenter() const
{
	return OldCenter;
}

CHexagon::~CHexagon() {
}

void CHexagon::PrintInfo(Output* pOut) {
	string message = "Hexagon: Centre= (" + to_string(Center.x) + " ," + to_string(Center.y) + " )";
	pOut->PrintMessage(message);
}

Point CHexagon::ReturnOldestCenter() const
{
	return OldestCenter;
}
