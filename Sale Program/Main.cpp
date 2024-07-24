#include <iostream>
#include <vector>
#include <string>
#include "Menu.h"
#include "Core.h"
#include "File_Handling.h"
#include "Ui.h"
using namespace std;

int main() {
	srand(time(NULL));
	Menu menu;
	Load(menu);
	while (true) {
		char confirm;
		MainUI();
		cin >> confirm;
		switch (confirm)
		{
		case 'c':
			ConfigMode(menu);
			break;
		case 's':
			SaleMode(menu);
			break;
		case 'r':
			cerr<<on_red << "Fearture being developed, some features may not available!"<<reset << endl;
			ReportMode(menu);
			break;
		case 'd': {
			if (Confirm("Do you want to save data before deleting") == true) {
				cout << "Saving data...";
				Save(menu);
				cout << "\r";
				cout << "\x1b[2K";
				cout << green << "Data saved" << reset << endl;

				cout << "Deleting data...";
				menu.ClearMemory();
				cout << "\r";
				cout << "\x1b[2K";
				cout << green << "Data deleted" << reset << endl;
			}
			else
			{
				cout << on_red << "Data is not saved, you can't recover after deleting" << reset << endl;
				if (Confirm() == true) {
					cout << reset << "Deleting data...";
					menu.ClearMemory();
					cout << "\r";
					cout << "\x1b[2K";
					cout << green << "Data deleted" << reset << endl;
				}
				else {
					cout << reset << red << "Cancelled" <<reset<< endl;
				}
			}
			break;
		}
		case 'q': {
			cout << "Saving data...";
			Save(menu);
			cout << "\r";
			cout << "\x1b[2K";
			cout <<green<< "Data saved" <<reset<< endl;
			menu.ClearMemory();
			cout << "Clearing memory...";
			cout << "\r";
			cout << "\x1b[2K";
			cout <<green<< "Memory cleared"<<reset << endl;
			return 1;
		}
		default:
			cout<<on_red << "Invalid option, try again"<<reset << endl;
			break;
		}
	}

	//Menu menu;
	//menu.AddItem("Test", "D001", 14.453);
	//menu.AddItem("Test2", "D002", 20.34);
	//menu.AddItem("Test3", "D003", 35.864);
	//menu.AddItem("Test4", "D004", 45);
	//vector<string> ids;
	//ids.push_back("D001");
	//ids.push_back("D002");
	//ids.push_back("D003");
	//menu.AddSale(ids);
	//menu.PrintSale();
	//Save(menu);
	//menu.ClearMemory();

	//Menu menu2;
	//Load(menu2);
	//menu2.PrintItems();
	//cout << endl << endl;
	//menu2.PrintSale();
	//menu2.ClearMemory();
	//return 1;
}