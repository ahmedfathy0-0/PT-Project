#ifndef CHEX_H
#define CHEX_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
	Point OldCenter;
	Point OldestCenter;
	int HexSize;// i have to use it after making the resize operation

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
	virtual Point ReturnCenter() const;
	virtual Point ReturnOldCenter() const;
	virtual void PrintInfo(Output*) ;
	virtual Point ReturnOldestCenter() const;
	~CHexagon();
};

#endif


#pragma once
