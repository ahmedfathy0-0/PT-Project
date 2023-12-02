#include "ApplicationManager.h"


int main()
{

	ActionType ActType;

	ActionType ActiType = DRAW_CIRCLE;
	ActionType ActTypeForPickndHide = DRAW_HEXAGON;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType, ActiType, ActTypeForPickndHide);

		//Update the interface
		AppManager.UpdateInterface();

	} while (ActType != EXIT);







	return 0;
}

