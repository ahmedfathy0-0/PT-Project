#ifndef CSQ_H
#define CSQ_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Centre;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInsideFigure(int x, int y) const;
	virtual void Save(ofstream& OutFile);
	//virtual void PrintInfo(Output*) const;
};

#endif