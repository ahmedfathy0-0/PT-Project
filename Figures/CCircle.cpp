#include "CCircle.h"

CCircle::CCircle() : CFigure(FigGfxInfo)
{

}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = P1;
	point = P2;
	figtype = circle;

}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a Circle on the screen	
	pOut->DrawCirc(Center, point, FigGfxInfo, Selected);
}

bool CCircle::IsInsideFigure(int x, int y) const {
	Point P;
	P.x = x; 
	P.y = y;
	if (CalculateDistance(Center, point) >= CalculateDistance(Center, P)) {
		return true;
	}
	else return false;
}

void CCircle::Move(Point NewCenter)
{
	OldCenter = Center;
	point.x += NewCenter.x - Center.x;
	point.y += NewCenter.y - Center.y;
	Center = NewCenter;
}

void CCircle::Resize(Point NewPoint)
{
	point.x = NewPoint.x;
	point.y = NewPoint.y;
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << "CIRCLE" << "     ";
	OutFile << ID << "     ";
	OutFile << Center.x << "     ";
	OutFile << Center.y << "     ";
	OutFile << point.x << "     ";
	OutFile << point.y << "     ";
	OutFile << getClr(FigGfxInfo.DrawClr) << "     ";
	if (FigGfxInfo.isFilled)
		OutFile << getClr(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

void CCircle::Load(ifstream& Infile)
{
	string clr;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Infile >> ID >> Center.x >> Center.y >> point.x >> point.y;
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
}

void CCircle::StartEndRecord(ofstream& OutFile)
{
	OutFile << "CIRCLE" << "     ";
	OutFile << ID << "     ";
	OutFile << Center.x << "     ";
	OutFile << Center.y << "     ";
	OutFile << point.x << "     ";
	OutFile << point.y << "     ";
	OutFile << getClr(FigGfxInfo.DrawClr) << "     ";
	if (FigGfxInfo.isFilled)
		OutFile << getClr(FigGfxInfo.FillClr) << "     ";
	else
		OutFile << "NO_FILL" << "     ";
	if(this->IsSelected())
		OutFile << "SELECTED" << endl;
	else 
		OutFile << "NOT_SELECTED" << endl;


}

void CCircle::PlayRecord(ifstream& Infile)
{
	string clr;
	string slc;
	FigGfxInfo.BorderWdth = UI.PenWidth;
	Infile >> ID >> Center.x >> Center.y >> point.x >> point.y;
	Infile >> clr;
	FigGfxInfo.DrawClr = getClr(clr);
	Infile >> clr;
	if (clr == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else {

		FigGfxInfo.FillClr = getClr(clr);
	}
	Infile >> slc;
	if (slc == "SELECTED")
	{
		this->SetSelected(true);
	}
	else
		this->SetSelected(false);


}

Point CCircle::ReturnCenter()
{
	return Center;
}

Point CCircle::ReturnOldCenter()
{
	return OldCenter;
}

void CCircle::PrintInfo(Output* pOut) {
	string message = "Circle, Center = (" + to_string(Center.x) + "," + to_string(Center.y)
		+ "), Radius: " + to_string(int(CalculateDistance(Center,point)));
	pOut->PrintMessage(message);
}