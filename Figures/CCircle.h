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
};

#endif


