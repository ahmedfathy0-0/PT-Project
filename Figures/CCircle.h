#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point point;//Point at the circle
public:
	CCircle(Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInsideFigure(int x, int y) const;
	virtual void Save(ofstream& OutFile);
	//virtual void PrintInfo(Output*) const;
};

#endif


