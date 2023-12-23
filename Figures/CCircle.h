#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point point;//Point at the circle
	Point OldCenter;
	Point OldestCenter;
public:
	CCircle();
	CCircle(Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInsideFigure(int x, int y) const;
	virtual void Move(Point);
	virtual void Resize(Point);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void StartEndRecord(ofstream& OutFile) ;
	virtual void PlayRecord(ifstream& Infile);
	virtual Point ReturnCenter() const;
	virtual Point ReturnOldCenter() const;
	virtual Point ReturnOldestCenter() const;
	virtual void PrintInfo(Output*);
};

#endif


