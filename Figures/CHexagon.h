#ifndef CHEX_H
#define CHEX_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
	Point OldCenter;
public:
	CHexagon();
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInsideFigure(int x, int y) const;
	double CalculateArea(Point, Point, Point) const;
	virtual void Move(Point);
	virtual void Resize(Point);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void StartEndRecord(ofstream& OutFile) ;
	virtual void PlayRecord(ifstream& Infile);
	virtual Point ReturnOldCenter();
	virtual void PrintInfo(Output*) ;
	~CHexagon();
};

#endif


#pragma once
