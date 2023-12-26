#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;   // forward declaration

class Input		//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
	static bool flag;//used to check if its fill or draw color
public:
	Input(window* pW);		//Consturctor
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetString(Output* pO) const;	 //Returns a string entered by the user
	bool isClicked(int&, int&);
	void UpdateBuffer() const;
	void SetWaitClose(bool flag) const;
	void SetBuffering(bool flag)const;
	ActionType GetUserAction(Output* pOut) const; //Read the user click and map to an action

	~Input();
};

#endif