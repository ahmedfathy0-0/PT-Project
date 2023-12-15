#ifndef CSQ_H
#define CSQ_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Centre;
public:
	CSquare();
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInsideFigure(int x, int y) const;
	virtual void Move(Point);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void StartEndRecord(ofstream& OutFile);
	virtual void PlayRecord(ifstream& Infile);

	//virtual void PrintInfo(Output*) const;
};

#endif