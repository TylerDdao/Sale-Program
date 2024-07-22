#include <iostream>
#include <vector>
#include <string>
#include "Menu.h"
#include "Core.h"
#include "File_Handling.h"
using namespace std;

int main() {
	Menu menu;
	menu.AddItem("Test", "D001", 14.453);
	menu.AddItem("Test2", "D002", 20.34);
	menu.AddItem("Test3", "D003", 35.864);
	menu.AddItem("Test4", "D008", 45);
	SaveItems("Test.txt", menu);
	menu.ClearMemory();

	Menu menu2;
	LoadItems("Test.txt", menu2);
	menu2.PrintItems();
	menu2.ClearMemory();
	//menu.AddItem("Test2", "D002", 14.453);
	//menu.PrintItems();
	//menu.EditItem("D001", "Changed", "C001", 10);
	//menu.PrintItems();
	//vector<string> ids;
	//ids.push_back("D001");
	//ids.push_back("D002");
	//menu.AddSale(ids);
	//menu.PrintSale();
	return 1;
}