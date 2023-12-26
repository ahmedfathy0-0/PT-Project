#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
};
//o
enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SWITCHPLAY,
	ITM_RECT,	//Rectangle item in menu
	ITM_SQUARE,
	ITM_TRIANGLE,
	ITM_HEXAGON,
	ITM_CIRCLE,
	//TODO: Add more items names here
	ITM_SELECTONE,
	ITM_MOVE,
	ITM_MOVEDRAG,
	ITM_RESIZE,
	ITM_DELETE,
	ITM_CLEAR,
	ITM_UNDO,
	ITM_REDO,
	ITM_SAVE,
	ITM_LOAD,
	ITM_CHANGEDRAWCLR,
	ITM_CHANGEFILLCLR,
	ITM_MUTE,
	ITM_STARTRECORDING,
	ITM_ENDRECORDING,
	ITM_PLAYRECORDING,
	ITM_EXIT,	//Exit item


	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_SWITCHDRAW,
	ITM_PICKBYFIGURE,

	ITM_PICKBYCOLOR,

	ITM_PICKBYBOTH,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum ColorPaletteItem
{
	COLOR_BLACK,
	COLOR_YELLOW,
	COLOR_ORANGE,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,

	colors
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth,
		ChangeColorPaletteHeight,
		PickandHidetoolbarheight,
		PickandHidetoolbarwidth,
		ColorPaletteWidthstart,
		ColorPaletteWidthend,
		ColorPaletteHeightstart,
		ColorPaletteHeightend,
		SqrSize,      //Square Size
		HexagonVertices,
		HexagonSize;
	bool conD;


	color DrawColor;		//Drawing color
	color OldDrawColor;
	color FillColor;		//Filling color
	color OldFillColor;
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;
	color ChangeColorPalette;
	int PenWidth;//width of the pen that draws shapes	
	bool ISFILLED;

	/// Add more members if needed


}UI;	//create a global object UI

#endif