#include "Output.h"
string Output::Lastmsg = " ";

Output::Output()
{
	count = 0;  //if count is even start button enabled
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1400;
	UI.height = 800;
	UI.wx = 5;
	UI.wy = 5;
	UI.SqrSize = 160;
	UI.HexagonVertices = 6;
	UI.HexagonSize = 100;

	UI.StatusBarHeight = 60;
	UI.ToolBarHeight = 60;
	UI.ChangeColorPaletteHeight = 50;
	UI.MenuItemWidth = 55;
	UI.PickandHidetoolbarheight = UI.ToolBarHeight * 2;
	UI.PickandHidetoolbarwidth = 3 * UI.MenuItemWidth;

	UI.ColorPaletteWidthstart = UI.width / 3;
	UI.ColorPaletteWidthend = UI.width / 3 + colors * UI.MenuItemWidth;
	UI.ColorPaletteHeightstart = 75;
	UI.ColorPaletteHeightend = 75 + UI.ChangeColorPaletteHeight;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = WHITESMOKE;		//Messages color
	UI.BkGrndColor = GHOSTWHITE;	//Background color
	UI.ChangeColorPalette = grey;
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = grey;
	UI.ToolBarColor = grey;
	UI.PenWidth = 4;	//width of the figures frames
	UI.ISFILLED = false;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reorder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];

	MenuItemImages[ITM_SWITCHPLAY] = "images\\MenuItems\\PLAY.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Triangle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Hexagon.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Circle.jpg";
	MenuItemImages[ITM_SELECTONE] = "images\\MenuItems\\SELECTONE.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\MOVE.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\RESIZE.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\CLEAR.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\DELETE.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\SAVE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\LOAD.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\UNDO.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\REDO.jpg";
	MenuItemImages[ITM_CHANGEDRAWCLR] = "images\\MenuItems\\CHANGEDRAWCOLOR.jpg";
	MenuItemImages[ITM_CHANGEFILLCLR] = "images\\MenuItems\\CHANGEFILLCOLOR.jpg";
	MenuItemImages[ITM_CHANGECOLOR] = "images\\MenuItems\\ChangeColor.jpg";
	if (count % 2 == 0) {
		MenuItemImages[ITM_STARTRECORDING] = "images\\MenuItems\\STARTRECORD.jpg";
		MenuItemImages[ITM_ENDRECORDING] = "images\\MenuItems\\ENDRECORD-1.jpg";
	}
	if (count % 2 != 0) {
		MenuItemImages[ITM_STARTRECORDING] = "images\\MenuItems\\STARTRECORD-1.jpg";
		MenuItemImages[ITM_ENDRECORDING] = "images\\MenuItems\\ENDRECORD.jpg";
	}

	MenuItemImages[ITM_PLAYRECORDING] = "images\\MenuItems\\PLAYRECORD.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], (i * UI.MenuItemWidth) + 5, 5, UI.MenuItemWidth - 5, UI.ToolBarHeight - 10);



	//Draw a line under the toolbar



}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	pWind->SetBrush(grey);
	pWind->SetPen(grey, 1);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	string PlayToolBarImages[PLAY_ITM_COUNT];
	PlayToolBarImages[ITM_SWITCHDRAW] = "images\\MenuItems\\DRAW.jpg";
	PlayToolBarImages[ITM_PICKANDHIDE] = "images\\MenuItems\\PICKANDHIDE.jpg";


	for (int i = 0; i < PLAY_ITM_COUNT; i++)
	{
		pWind->DrawImage(PlayToolBarImages[i], (i * UI.MenuItemWidth) + 5, 5, UI.MenuItemWidth - 5, UI.ToolBarHeight - 10);
	}



	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePickAndHideToolbar() const
{
	
	CreatePlayToolBar();
	string PickAndHideImages[PICKANDHIDECOUNT];
	PickAndHideImages[ITM_PICKBYFIGURE] = "images\\MenuItems\\pickbyfig.jpg";
	PickAndHideImages[ITM_PICKBYCOLOR] = "images\\MenuItems\\ChangeColor.jpg";
	PickAndHideImages[ITM_PICKBYBOTH] = "images\\MenuItems\\pickbyboth.jpg";

	for (int i = 0; i < PICKANDHIDECOUNT; i++)
	{
		pWind->DrawImage(PickAndHideImages[i], ((i+2) * UI.MenuItemWidth) + 5, 5, UI.MenuItemWidth - 5, UI.ToolBarHeight - 10);
	}

}

void Output::deletePickAndHideToolbar() const
{
//	pWind->SetPen(UI.BkGrndColor, 1);
	//pWind->SetBrush(UI.BkGrndColor);
	//pWind->DrawRectangle(0, UI.ToolBarHeight, UI.PickandHidetoolbarwidth, UI.ToolBarHeight + UI.PickandHidetoolbarheight);
}

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	Lastmsg = msg;
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5) - 5, msg);
}


void Output::CreateENDRECORDING() const {


	string MenuItemImages[DRAW_ITM_COUNT];

	MenuItemImages[ITM_STARTRECORDING] = "images\\MenuItems\\STARTRECORD-1.jpg";
	MenuItemImages[ITM_ENDRECORDING] = "images\\MenuItems\\ENDRECORD.jpg";


	for (int i = 18; i < 20; i++)
		pWind->DrawImage(MenuItemImages[i], (i * UI.MenuItemWidth) + 5, 5, UI.MenuItemWidth - 5, UI.ToolBarHeight - 10);

}

void Output::CreateSTARTRECORDING() const {


	string MenuItemImages[DRAW_ITM_COUNT];

	MenuItemImages[ITM_STARTRECORDING] = "images\\MenuItems\\STARTRECORD.jpg";
	MenuItemImages[ITM_ENDRECORDING] = "images\\MenuItems\\ENDRECORD-1.jpg";


	for (int i = 18; i < 20; i++)

		pWind->DrawImage(MenuItemImages[i], (i * UI.MenuItemWidth) + 5, 5, UI.MenuItemWidth - 5, UI.ToolBarHeight - 10);
}

void Output::CreateColorPalette() const
{
	string Colors[colors];
	Colors[COLOR_BLACK] = "images\\colors\\black.jpg";
	Colors[COLOR_YELLOW] = "images\\colors\\yellow.jpg";
	Colors[COLOR_ORANGE] = "images\\colors\\orange.jpg";
	Colors[COLOR_RED] = "images\\colors\\red.jpg";
	Colors[COLOR_GREEN] = "images\\colors\\green.jpg";
	Colors[COLOR_BLUE] = "images\\colors\\blue.jpg";


	pWind->SetPen(UI.ChangeColorPalette, 5);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(UI.ColorPaletteWidthstart - 10, UI.ColorPaletteHeightstart - 10, UI.ColorPaletteWidthend + 10, UI.ColorPaletteHeightend + 10);

	for (int i = 0; i < colors; i++)
		pWind->DrawImage(Colors[i], UI.ColorPaletteWidthstart + i * UI.MenuItemWidth, UI.ColorPaletteHeightstart, UI.MenuItemWidth - 5, UI.ChangeColorPaletteHeight);

}

void Output::deleteColorPalette() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(UI.ColorPaletteWidthstart - 10, UI.ColorPaletteHeightstart - 10, UI.ColorPaletteWidthend + 10, UI.ColorPaletteHeightend + 10);
}
void Output::setCrntDrawColor(color color)
{
	UI.DrawColor = color;
}
void Output::setCrntFillColor(color color)
{
	UI.FillColor = color;

}
void Output::setisFilled(bool isfilled)
{
	UI.ISFILLED = isfilled;
}
void Output::incrementcount()
{
	count++;
}
int Output::getcount() const
{
	return count;
}
bool Output::getisFilled() const
{
	return UI.ISFILLED;
}
color Output::getCrntDrawColor() const	//get current drawing color
{


	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
	{
		style = FRAME;
	}



	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

	if (P1.y < UI.ToolBarHeight || P2.y < UI.ToolBarHeight)
		CreateDrawToolBar();

	ClearStatusBar();	
	PrintMessage(Lastmsg);


}
void Output::DrawSqr(Point P1, GfxInfo SqGfxInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = SqGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SqGfxInfo.BorderWdth);
	drawstyle style;
	if (SqGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point p3, p4;

	p3.x = P1.x + UI.SqrSize / 2;
	p3.y = P1.y - UI.SqrSize / 2;
	p4.x = P1.x - UI.SqrSize / 2;
	p4.y = P1.y + UI.SqrSize / 2;

	pWind->DrawRectangle(p3.x, p3.y, p4.x, p4.y, style);

	if (p4.y < UI.ToolBarHeight || p3.y < UI.ToolBarHeight)
		CreateDrawToolBar();
	
	ClearStatusBar();
	PrintMessage(Lastmsg);
}

void Output::DrawTr(Point P1, Point P2, Point P3, GfxInfo TrGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = TrGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TrGfxInfo.BorderWdth);
	drawstyle style;
	if (TrGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TrGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	if (P1.y < UI.ToolBarHeight || P2.y < UI.ToolBarHeight || P3.y < UI.ToolBarHeight)
		CreateDrawToolBar();


	ClearStatusBar();
	PrintMessage(Lastmsg);

}
void Output::DrawHex(Point P1, GfxInfo HXGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = HXGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, HXGfxInfo.BorderWdth);
	drawstyle style;
	if (HXGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HXGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int* x = new int[UI.HexagonVertices];
	int* y = new int[UI.HexagonVertices];
	x[0] = P1.x + UI.HexagonSize;
	y[0] = P1.y;
	x[1] = P1.x + UI.HexagonSize / 2;
	y[1] = P1.y + UI.HexagonSize * 0.866;
	x[2] = P1.x - UI.HexagonSize / 2;
	y[2] = P1.y + UI.HexagonSize * 0.866;
	x[3] = P1.x - UI.HexagonSize;
	y[3] = P1.y;
	x[4] = P1.x - UI.HexagonSize / 2;
	y[4] = P1.y - UI.HexagonSize * 0.866;
	x[5] = P1.x + UI.HexagonSize / 2;
	y[5] = P1.y - UI.HexagonSize * 0.866;
	pWind->DrawPolygon(x, y, UI.HexagonVertices, style);
	if ((P1.y - UI.HexagonSize * 0.866) < UI.ToolBarHeight)
		CreateDrawToolBar();



	delete[] x;
	delete[] y;


	ClearStatusBar();
	PrintMessage(Lastmsg);

}
void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int radius = sqrt((pow((P1.y) - (P2.y), 2) + pow((P1.x) - (P2.x), 2)));



	pWind->DrawCircle(P1.x, P1.y, radius, style);
	if (P1.y - radius < UI.ToolBarHeight)
		CreateDrawToolBar();

	ClearStatusBar();
	PrintMessage(Lastmsg);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

