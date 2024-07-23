#include "Ui.h"

void MainUI()
{
	cout << "[c] Config Mode" << endl;
	cout << "[s] Sale Mode" << endl;
	cout <<red<< "[r] Report Mode (Developing...)" <<reset<< endl;
	cout << "[d] Reset All" << endl;
	cout << "[q] Save & Quit" << endl;
	cout << ">";
}

void ConfigUI()
{
	cout << "1. Add Item" << endl;
	cout << "2. Remove Item" << endl;
	cout << "3. Edit Item" << endl;
	cout << "4. Search Item" << endl;
	cout << "5. Print all Items" << endl;
	cout << "6. Delete all items" << endl;
	cout << "6. Return to Main" << endl;
	cout << ">";
}

void SaleUI()
{
	cout << "1. New Sale" << endl;
	cout << "2. Remove Sale" << endl;
	cout << "3. Search Sale" << endl;
	cout << "4. Print all Sales" << endl;
	cout << "5. Delete all sales" << endl;
	cout << "6. Return to Main" << endl;
	cout << ">";
}

void ReportUI()
{
	cout << "1. End-of-day Summary" << endl;
	cout << "2. Total Sale Today" << endl;
	cout << "3. Export End-of-day summary" << endl;
	cout << "4. Return to Main" << endl;
	cout << ">";
}
