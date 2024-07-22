#include <iostream>
#include <vector>
#include <string>
#include "Menu.h"
#include "Core.h"
#include "File_Handling.h"
using namespace std;

int main() {
	srand(time(NULL));
	Menu menu;
	menu.AddItem("Test", "D001", 14.453);
	menu.AddItem("Test2", "D002", 20.34);
	menu.AddItem("Test3", "D003", 35.864);
	menu.AddItem("Test4", "D004", 45);
	vector<string> ids;
	ids.push_back("D001");
	ids.push_back("D002");
	ids.push_back("D003");
	menu.AddSale(ids);
	menu.PrintSale();
	Save(menu);
	menu.ClearMemory();

	//Menu menu2;
	//Load(menu2);
	//menu2.PrintItems();
	//cout << endl << endl;
	//menu2.PrintSale();
	//menu2.ClearMemory();
	//return 1;
}