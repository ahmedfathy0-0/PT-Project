#ifndef CTRG_H
#define CTRG_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point,Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInsideFigure(int x, int y) const;
	double CalculateArea(Point, Point, Point) const;
	virtual void Save(ofstream& OutFile);
	//virtual void PrintInfo(Output*) const;
};

#endif