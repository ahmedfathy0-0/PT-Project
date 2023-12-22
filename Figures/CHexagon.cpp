#include "CHexagon.h"

CHexagon::CHexagon() : CFigure(FigGfxInfo)
{

}

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	figtype = hexagon;

}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

bool CHexagon::IsInsideFigure(int X, int Y) const 
{
	int x[6];
	int y[6];
	x[0] = Center.x + UI.HexagonSize;
	y[0] = Center.y;
	x[1] = Center.x + UI.HexagonSize / 2;
	y[1] = Center.y + UI.HexagonSize * 0.866;
	x[2] = Center.x - UI.HexagonSize / 2;
	y[2] = Center.y + UI.HexagonSize * 0.866;
	x[3] = Center.x - UI.HexagonSize;
	y[3] = Center.y;
	x[4] = Center.x - UI.HexagonSize / 2;
	y[4] = Center.y - UI.HexagonSize * 0.866;
	x[5] = Center.x + UI.HexagonSize / 2;
	y[5] = Center.y - UI.HexagonSize * 0.866;

	Point P1, P2, P3, P4, P5, P6, P;
	P1.x = x[0]; P1.y = y[0];
	P2.x = x[1]; P2.y = y[1];
	P3.x = x[2]; P3.y = y[2];
	P4.x = x[3]; P4.y = y[3];
	P5.x = x[4]; P5.y = y[4];
	P6.x = x[5]; P6.y = y[5];
	P.x = X; P.y = Y;

	double HexagonArea1 = 25950;
	double HexagonArea2 = 25800;
	double triangle1Area = CalculateArea(P, P1, P6);
	double triangle2Area = CalculateArea(P, P1, P2);
	double triangle3Area = CalculateArea(P, P2, P3);
	double triangle4Area = CalculateArea(P, P3, P4);
	double triangle5Area = CalculateArea(P, P4, P5);
	double triangle6Area = CalculateArea(P, P5, P6);
	if (HexagonArea1 == triangle1Area + triangle2Area + triangle3Area + triangle4Area + triangle5Area + triangle6Area 
		||HexagonArea2== triangle1Area + triangle2Area + triangle3Area + triangle4Area + triangle5Area + triangle6Area) return true;
	else return false;
}

double CHexagon::CalculateArea(Point P1, Point P2, Point P3) const {
	return 0.5 * fabs((P1.x * (P2.y - P3.y)) + (P2.x * (P3.y - P1.y)) + (P3.x * (P1.y - P2.y)));
}

void CHexagon::Move(Point NewCenter)
{
	OldCenter = Center;
	Center = NewCenter;
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << "HEXAGN" << "     ";
	OutFile << ID << "     ";
	OutFile << Center.x << "     ";
	OutFile << Center.y << "     ";
	OutFile << getClr(FigGfxInfo.DrawClr) << "     ";
	if (FigGfxInfo.isFilled)
		OutFile << getClr(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
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
	}
	else
		FigGfxInfo.FillClr = getClr(clr);
}

void CHexagon::StartEndRecord(ofstream& OutFile)
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
	if (this->IsSelected())
		OutFile << "SELECTED" << endl;
	else
		OutFile << "NOT_SELECTED" << endl;
}
void CHexagon::PlayRecord(ifstream& Infile)
{
	string clr;
	string slc;
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

}

Point CHexagon::ReturnCenter()
{
	return Center;
}

Point CHexagon::ReturnOldCenter()
{
	return OldCenter;
}

CHexagon::~CHexagon() {
}

void CHexagon::PrintInfo(Output* pOut) {
	string message = "Hexagon: Centre= (" + to_string(Center.x) + " ," + to_string(Center.y) + " )";
	pOut->PrintMessage(message);
}