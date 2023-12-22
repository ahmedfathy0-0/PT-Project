#include "Input.h"
#include "Output.h"
Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
	UI.conD = false;
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);

		pWind->FlushMouseQueue();
		pWind->FlushKeyQueue();
	}
}

bool Input::isClicked()
{
	int x, y;
	if (pWind->GetButtonState(LEFT_BUTTON,x,y)== BUTTON_DOWN)
		return true;
	else
		return false;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SWITCHPLAY: return TO_PLAY;
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_HEXAGON: return DRAW_HEXAGON;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case ITM_SELECTONE: return SELECTONE;
			case ITM_MOVE: return MOVE;
			case ITM_MOVEDRAG: return MOVEDRAG;
			case ITM_RESIZE: return RESIZE;
			case ITM_CLEAR: return CLEAR;
			case ITM_DELETE: return DELET;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_STARTRECORDING:return STARTRECORDING;
			case ITM_ENDRECORDING: return ENDRECORDING;
			case ITM_PLAYRECORDING:return PLAYRECORDING;
			case ITM_CHANGEDRAWCLR:return CHANGEDRAWCOLOR;
			case ITM_CHANGEFILLCLR:return CHANGEFILLCOLOR;
			case ITM_CHANGECOLOR: return CHANGECOLOR;
			case ITM_EXIT: return EXIT;
			default: return EMPTY;	//A click on empty place in design toolbar
			}
		}

		if (y >= UI.ColorPaletteHeightstart && y < UI.ColorPaletteHeightend && UI.conD) {

			if (x >= UI.ColorPaletteWidthstart && x < UI.ColorPaletteWidthend) {

				int ClickedItemOrder = ((x - UI.ColorPaletteWidthstart) / (UI.MenuItemWidth));
				switch (ClickedItemOrder) {
				case(COLOR_BLACK): return BLACKCLR;
				case(COLOR_YELLOW): return YELLOWCLR;
				case(COLOR_ORANGE): return ORANGECLR;
				case(COLOR_RED): return REDCLR;
				case(COLOR_GREEN): return GREENCLR;
				case(COLOR_BLUE): return BLUECLR;
				}
			}
		}


		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}


		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{

		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action

		if (y >= 0 && y < UI.ToolBarHeight &&!UI.conDforPicknHide)
		{
			
			int ClickedItemOrder = x / UI.MenuItemWidth;
			switch (ClickedItemOrder)
			{
			case(ITM_SWITCHDRAW):return TO_DRAW;
			case(ITM_PICKANDHIDE):return PICKANDHIDE;
			default:return EMPTY_PLAYTOOLBAR;
			}
		}
		if (y >= 0 && y < UI.ToolBarHeight && UI.conDforPicknHide)
		{

			int clickeditemorder = ((x) / UI.MenuItemWidth)-2;
			switch (clickeditemorder)
			{
			case(ITM_PICKBYFIGURE):return PICKBYFIG;
			case(ITM_PICKBYCOLOR):return PICKBYCOL;
			case(ITM_PICKBYBOTH):return PICKBYBOTH;
			}
		}
		if (y >= UI.ToolBarHeight && y <= (UI.height) - (UI.StatusBarHeight))
		{
			return PLAYING_AREA;
		}
		else
			return STATUS;


	}

}
/////////////////////////////////

Input::~Input()
{
}

