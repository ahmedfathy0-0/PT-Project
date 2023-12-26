#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
	static bool flag;//for Start and end record items
	static string Lastmsg;//used to fix statue bar issue to get last message back after clear all in every figure function
	static bool SOUND;//for MUTE & UNMUTE items

public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void deletePickAndHideToolbar() const;


	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void CreateColorPalette() const;
	void deleteColorPalette() const;
	void CreateENDRECORDING() const;
	void CreateSTARTRECORDING() const;
	void CreateMUTE() const;
	bool getSound() const;
	void deleteENDRECORDING() const;
	void deleteSTARTRECORDING() const;
	void UpdateBuffer() const;
	void SetBuffering(bool flag)const;

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawSqr(Point P1, GfxInfo SqGfxInfo, bool selected = false,double SqrSize=160) const;
	void DrawTr(Point P1, Point P2, Point P3, GfxInfo TrGfxInfo, bool selected = false) const;
	void DrawHex(Point P1, GfxInfo HXGfxInfo, bool selected = false,double HexSize=100) const;
	void DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected = false) const;
	///Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	void setCrntDrawColor(color);
	void setCrntFillColor(color);
	void setisFilled(bool);
	void incrementcount();
	int getcount() const;
	bool getisFilled() const;
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	color getOldFillColor() const;	//get old filling color
	color getOldDrawColor() const;	//get old Drawing color
	void SetOldFillColor(color);	//get old filling color
	void SetOldDrawColor(color);
	void CreateUNMUTE() const;


	int getCrntPenWidth() const;		//get current pen width


	~Output();
};

#endif