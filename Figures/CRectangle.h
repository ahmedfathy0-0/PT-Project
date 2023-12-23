#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Center;
	Point OldCenter;
	Point OldestCenter;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsInsideFigure(int x, int y) const;
	virtual void Move(Point);
	virtual void Resize(Point);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void StartEndRecord(ofstream& OutFile);
	virtual void PlayRecord(ifstream& Infile);
	virtual Point ReturnCenter() const;
	virtual Point ReturnOldCenter() const;
	virtual Point ReturnOldestCenter() const;
	virtual void PrintInfo(Output*);
};

#endif


