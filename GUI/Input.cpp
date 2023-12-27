#include "Input.h"
#include "Output.h"
#include "..\CMUgraphicsLib\auxil.h"
bool Input::flag = false;
Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
	UI.conD = false;
	PlaySound(("Sounds\\HELLO.wav"), NULL, SND_ASYNC);

}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

void Input::UpdateBuffer() const// to solve when window turns white suddenly or after minmized it
{
	pWind->UpdateBuffer();
}
void Input::SetBuffering (bool flag)const// to solve when window turns white suddenly or after minmized it
{
	pWind->SetBuffering(flag);

}
void Input::SetWaitClose(bool flag) const {
	pWind->SetWaitClose(flag);
}


string Input::GetString(Output* pO) const
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

bool Input::isClicked(int &x,int &y)//told us is the user click to the left button or not 
{
	if (pWind->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN)
		return true;
	else
		return false;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(Output* pOut) const
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
			case ITM_MUTE:return MUTE;
			case ITM_STARTRECORDING:return STARTRECORDING;
			case ITM_ENDRECORDING: return ENDRECORDING;
			case ITM_PLAYRECORDING:return PLAYRECORDING;
			case ITM_CHANGEDRAWCLR: {
				flag = false;
				pOut->setisFilled(false);
				return CHANGEDRAWCOLOR;}
			case ITM_CHANGEFILLCLR: {
				flag = true;
				pOut->setisFilled(true);
				return CHANGEFILLCOLOR;
			}
			case ITM_EXIT: {
					return EXIT;}
			default: return EMPTY;	//A click on empty place in design toolbar
			}
		}

		if (y >= UI.ColorPaletteHeightstart && y < UI.ColorPaletteHeightend && UI.conD) {

			if (x >= UI.ColorPaletteWidthstart && x < UI.ColorPaletteWidthend) {

				int ClickedItemOrder = ((x - UI.ColorPaletteWidthstart) / (UI.MenuItemWidth));
				switch (ClickedItemOrder) {
				case(COLOR_BLACK): {
					if (flag == true) {
						pOut->PrintMessage("The Fill color will now be black");
						pOut->SetOldFillColor(pOut->getCrntFillColor());
						pOut->setCrntFillColor(BLACK);
					}
					else {
						pOut->PrintMessage("The Draw color will now be black");
						pOut->SetOldDrawColor(pOut->getCrntDrawColor());
						pOut->setCrntDrawColor(BLACK);
					}
					return BLACKCLR;
				}
				case(COLOR_YELLOW): { 
					if (flag == true) {
						pOut->PrintMessage("The Fill color will now be YELLOW");
						pOut->SetOldFillColor(pOut->getCrntFillColor());
						pOut->setCrntFillColor(YELLOW);
					}
					else {
						pOut->PrintMessage("The Draw color will now be YELLOW");
						pOut->SetOldDrawColor(pOut->getCrntDrawColor());
						pOut->setCrntDrawColor(YELLOW);
					}
					return YELLOWCLR;}
				case(COLOR_ORANGE): {
					if (flag == true) {
						pOut->PrintMessage("The Fill color will now be ORANGE");
						pOut->SetOldFillColor(pOut->getCrntFillColor());
						pOut->setCrntFillColor(ORANGE);
					}
					else {
						pOut->PrintMessage("The Draw color will now be ORANGE");
						pOut->SetOldDrawColor(pOut->getCrntDrawColor());
						pOut->setCrntDrawColor(ORANGE);
					}
					return ORANGECLR;}
				case(COLOR_RED): { 
					if (flag == true) {
						pOut->PrintMessage("The Fill color will now be RED");
						pOut->SetOldFillColor(pOut->getCrntFillColor());
						pOut->setCrntFillColor(RED);
					}
					else {
						pOut->PrintMessage("The Draw color will now be RED");
						pOut->SetOldDrawColor(pOut->getCrntDrawColor());
						pOut->setCrntDrawColor(RED);
					}
					return REDCLR;}
				case(COLOR_GREEN): { 
					if (flag == true) {
						pOut->PrintMessage("The Fill color will now be GREEN");
						pOut->SetOldFillColor(pOut->getCrntFillColor());
						pOut->setCrntFillColor(GREEN);
					}
					else {
						pOut->PrintMessage("The Draw color will now be GREEN");
						pOut->SetOldDrawColor(pOut->getCrntDrawColor());
						pOut->setCrntDrawColor(GREEN);
					}
					return GREENCLR;}
				case(COLOR_BLUE): {
					if (flag == true) {
						pOut->PrintMessage("The Fill color will now be BLUE");
						pOut->SetOldFillColor(pOut->getCrntFillColor());
						pOut->setCrntFillColor(BLUE);
					}
					else {
						pOut->PrintMessage("The Draw color will now be BLUE");
						pOut->SetOldDrawColor(pOut->getCrntDrawColor());
						pOut->setCrntDrawColor(BLUE);
					}
					return BLUECLR;}
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

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			
			int ClickedItemOrder = x / UI.MenuItemWidth;
			switch (ClickedItemOrder)
			{
			case(ITM_SWITCHDRAW):return TO_DRAW;
			case(ITM_PICKBYFIGURE):return PICKBYFIG;
			case(ITM_PICKBYCOLOR):return PICKBYCOL;
			case(ITM_PICKBYBOTH):return PICKBYBOTH;
			default:return EMPTY_PLAYTOOLBAR;
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

