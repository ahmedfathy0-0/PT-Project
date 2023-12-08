#include "CHexagon.h"

int* x = new int[UI.HexagonVertices];
int* y = new int[UI.HexagonVertices];

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

bool CHexagon::IsInsideFigure(int X, int Y) const 
{
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

	double HexagonArea = 66480;
	double triangle1Area = CalculateArea(P, P1, P6);
	double triangle2Area = CalculateArea(P, P1, P2);
	double triangle3Area = CalculateArea(P, P2, P3);
	double triangle4Area = CalculateArea(P, P3, P4);
	double triangle5Area = CalculateArea(P, P4, P5);
	double triangle6Area = CalculateArea(P, P5, P6);
	
	if (HexagonArea == triangle1Area + triangle2Area + triangle3Area + triangle4Area + triangle5Area + triangle6Area) return true;
	else return false;
}

double CHexagon::CalculateArea(Point P1, Point P2, Point P3) const {
	return 0.5 * fabs((P1.x * (P2.y - P3.y)) + (P2.x * (P3.y - P1.y)) + (P3.x * (P1.y - P2.y)));
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

CHexagon::~CHexagon() {
	delete[] x;
	delete[] y;
	x = nullptr;
	y = nullptr;
}

/*void CHexagon::PrintInfo(Output* pOut) const {
	string message = "Hexagon: Centre= (" + to_string(Center.x) + " ," + to_string(Center.y) + " )";
	pOut->PrintMessage(message);
}*/