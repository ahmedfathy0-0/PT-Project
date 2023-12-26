#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>
//Base class for all figures

class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	string getClr(color Dclr);
	color getClr(string Dclr);
	bool getselected(string select);
	FigureType figtype;
	FillClr FillClr=No_Fill;
	bool isHidden;

	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);


	//Select figure functions
	void SetSelected(bool s);	                             //select/unselect the figure
	bool IsSelected() const;	                             //check whether fig is selected
	virtual bool IsInsideFigure(int, int) const = 0;         //Checks if the point is inside any of the figures
	//virtual void PrintInfo(Output*) const = 0;             //prints the info of the selected figure

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	double CalculateDistance(Point P1, Point P2) const;
	virtual void Move(Point) = 0;
	virtual void Resize(Point) = 0;
	virtual Point ReturnCenter() const = 0;
	virtual Point ReturnOldCenter() const= 0;
	virtual Point ReturnOldestCenter() const = 0;
	void SetIsFilled(bool);
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual void StartEndRecord(ofstream& OutFile) = 0;//Record child action
	virtual void PlayRecord(ifstream& Infile) = 0;//Play that Record
	int type();
	void IsHidden(bool);
	void SetHidden(bool);
	bool GetHiddenStatus();
	void setisFilled(bool b);
	bool isfilled();
	int GetFillClr();
	color CGetFillClr();
	color CGetDrawClr();

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	void setID(int);
	int getID ()const;
};

#endif