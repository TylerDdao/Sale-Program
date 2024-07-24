#include "Core.h"

bool Confirm()
{
	while (true) {
		char confirm;
		cout << "Confirm (Y/N): ";
		cin >> confirm;
		cin.ignore();
		if (confirm == 'Y' || confirm == 'y') {
			return true;
		}
		else if (confirm == 'N' || confirm == 'n') {
			return false;
		}
		else
		{
			cerr << on_red << "Invalid option, try again" << reset << endl;
		}
	}
}

bool Confirm(string message)
{
	while (true) {
		char confirm;
		cout << message<<" (Y/N): ";
		cin >> confirm;
		cin.ignore();
		if (confirm == 'Y' || confirm == 'y') {
			return true;
		}
		else if (confirm == 'N' || confirm == 'n') {
			return false;
		}
		else
		{
			cerr << on_red << "Invalid option, try again" << reset << endl;
		}
	}
}

void ConfigMode(Menu& menu)
{
	while (true)
	{
		int option;
		ConfigUI();
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1: {
			string name;
			cout << "Enter name: ";
			getline(cin, name);
			string id;
			while (true) {
				bool idVer;
				cout << "Enter ID: ";
				getline(cin, id);
				idVer = menu.ItemIdVerification(id);
				if (idVer == true) {
					break;
				}
				cout<<on_red << "ID already exist, try again"<<reset << endl;
			}
			float price = 0;
			cout << "Enter price: $";
			cin >> price;
			cout << "**********" << endl << "Adding" << endl;
			cout << "Name: " << name << endl << "ID: " << id << endl << "Price: $" << price << endl;
			if (Confirm() == true) {
				menu.AddItem(name, id, price);
				cout <<green<< "Item added"<<reset << endl;
			}
			else
			{
				cout <<red<< "Cancelled"<<reset << endl;
			}
			break;
		}
		case 2:{
			if (menu.item == nullptr) {
				cerr << "Empty" << endl;
				break;
			}
			string id;
			cout << "Enter ID: ";
			getline(cin, id);
			Item* ptr = menu.SearchItem(id);
			if (ptr == nullptr) {
				cerr <<on_red<< "No item found"<<reset << endl;
				break;
			}
			cout << "**********" << endl << "Removing:" << endl;
			menu.PrintItem(id);
			if (Confirm() == true) {
				menu.RemoveItem(id);
				cout <<green<< "Item removed"<<reset << endl;
			}
			else {
				cout<<red << "Cancelled"<<reset << endl;
			}
			break;
		}
		case 3: {
			if (menu.item == nullptr) {
				cerr<<on_red << "Empty"<<reset << endl;
				break;
			}
			string id;
			cout << "Enter ID: ";
			getline(cin, id);
			Item* ptr = menu.SearchItem(id);
			if (ptr == nullptr) {
				cerr<<on_red << "No item found"<<reset << endl;
				break;
			}
			string newName;
			cout << "Enter new name: ";
			getline(cin, newName);
			string newId;
			while (true) {
				bool idVer;
				cout << "Enter new ID: ";
				getline(cin, newId);
				idVer = menu.ItemIdVerification(newId);
				if (idVer == true) {
					break;
				}
				cerr<<on_red << "ID already exist, try again"<<reset << endl;
			}
			float newPrice = 0;
			cout << "Enter new price: $";
			cin >> newPrice;
			menu.PrintItem(id);
			cout << "**********" << endl;
			cout << "Changing to:" << endl;
			cout << "**********" << endl;
			cout << on_cyan << "Name: " << newName << reset << endl;
			cout << "ID: " << newId << endl;
			cout << "Price: $" << newPrice << endl;
			if (Confirm() == true) {
				menu.EditItem(id, newName, newId, newPrice);
				cout<<green << "Item changed"<<reset << endl;
			}
			else {
				cout<<red << "Cancelled"<<reset << endl;
			}
			break;
		}
		case 4: {
			if (menu.item == nullptr) {
				cerr<<on_red << "Empty"<<reset << endl;
				break;
			}
			string id;
			cout << "Enter ID: ";
			getline(cin, id);
			Item* ptr = menu.SearchItem(id);
			if (ptr == nullptr) {
				cerr <<on_red<< "No item found" <<reset<< endl;
				break;
			}
			cout << "**********" << endl << "Result:" << endl;
			menu.PrintItem(id);
			break;
		}
		case 5:
			cout << "********************" << endl;
			menu.PrintItems();
			break;
		case 6: {
			if (Confirm("Do you want to save data before deleting") == true) {
				cout << "Enter file name (Including format of file): ";
				string fileName;
				getline(cin, fileName);
				cout << "Saving data...";
				SaveItems(fileName, menu);
				cout << "\r";
				cout << "\x1b[2K";
				cout << green << "Data saved in: " << reset << on_green << fileName<< reset << endl;

				cout << "Deleting data...";
				menu.ClearItems();
				cout << "\r";
				cout << "\x1b[2K";
				cout << green << "Data deleted" << reset << endl;
			}
			else
			{
				cout << on_red << "Data is not saved, you can't recover after deleting" << reset << endl;
				if (Confirm() == true) {
					cout << reset << "Deleting data...";
					menu.ClearItems();
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
		case 7:
			return;
		default:
			cerr<<on_red << "Invalid option, try again"<<reset << endl;
			break;
		}
	}
}

void SaleMode(Menu& menu)
{
	while (true)
	{
		int option;
		SaleUI();
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1: {
			if (menu.item == nullptr) {
				cerr <<on_red<< "No item"<<reset << endl;
				break;
			}
			menu.PrintItems();
			vector<string> orders;
			float total = 0;
			while (true) {
				int quantity = 0;
				string id;
				while (true) {
					cout << "Enter item ID: ";
					getline(cin, id);
					Item* ptr = menu.SearchItem(id);
					if (ptr != nullptr) {
						break;
					}
					cerr<<on_red << "No item found, try again"<<reset<<endl;
				}
				cout << "Quantity: ";
				cin >> quantity;
				for (int i = 0; i < quantity;i++) {
					orders.push_back(id);
					total = total + menu.GetPriceOf(id);
				}
				if (Confirm("Add more") == false) {
					break;
				}
			}
			Sale sale(orders, total);
			menu.PrintSale(sale);
			if (Confirm() == true) {
				int id = menu.AddSale(orders);
				if (id == -1) {
					cerr << on_red << "Error adding new sale" << reset << endl;
					break;
				}
				cout << "Your sale ID: " << on_cyan << id << reset << endl;;
				cout<<green << "Sale added"<<reset << endl;
			}
			else {
				cout<<red << "Cancelled"<<reset << endl;
			}
			break;
		}
		case 2: {
			if (menu.item == nullptr) {
				cerr << "Empty" << endl;
				break;
			}
			int id;
			cout << "Enter ID: ";
			cin >> id;
			Sale* ptr = menu.SearchSale(id);
			if (ptr == nullptr) {
				cerr << on_red << "No sale found" << reset << endl;
				break;
			}
			cout << "**********" << endl << "Removing:" << endl;
			menu.PrintSale(id);
			if (Confirm() == true) {
				menu.RemoveSale(id);
				cout << green << "Sale removed" << reset << endl;
			}
			else {
				cout << red << "Cancelled" << reset << endl;
			}
			break;
		}
		case 3: {
			if (menu.sale == nullptr) {
				cerr << on_red << "Empty" << reset << endl;
				break;
			}
			int id = 0;
			cout << "Enter ID: ";
			cin >> id;
			Sale* ptr = menu.SearchSale(id);
			if (ptr == nullptr) {
				cerr << on_red << "No sale found" << reset << endl;
				break;
			}
			cout << "Result:"<<endl <<"********************"<< endl;
			menu.PrintSale(id);
			break;
		}
		case 4: {
			if (menu.sale == nullptr) {
				cerr << on_red << "Empty" << reset << endl;
				break;
			}
			menu.PrintSales();
			break;
		}
		case 5: {
			if (Confirm("Do you want to save before deleting") == true) {
				cout << "Enter file name (Including format of file): ";
				string fileName;
				getline(cin, fileName);
				cout << "Saving data...";
				SaveSales(fileName, menu);
				cout << "\r";
				cout << "\x1b[2K";
				cout << green << "Data saved in " << reset << on_green << fileName << reset << endl;

				cout << "Deleting data...";
				menu.ClearSales();
				cout << "\r";
				cout << "\x1b[2K";
				cout << green << "Data deleted" << reset << endl;
			}
			else
			{
				cout <<on_red << "Data is not saved, you can't recover after deleting"<<reset << endl;
				if (Confirm() == true) {
					cout <<reset<< "Deleting data...";
					menu.ClearSales();
					cout << "\r";
					cout << "\x1b[2K";
					cout << green << "Data deleted" << reset << endl;
				}
				else {
					cout << reset <<red<< "Cancelled" <<reset<< endl;
				}
			}
			break;
		}
		case 6:
			return;
		default:
			cerr<<on_red << "Invalid option, try again"<<reset << endl;
			break;
		}
	}
}

void ReportMode(Menu menu)
{
	while (true)
	{
		int option;
		ReportUI();
		cin >> option;
		cin.ignore();
		switch (option)
		{
		case 1: {
			menu.EndOfDaySaleSummary();
			break;
		}
		case 4:
			return;
		default:
			cerr << on_red << "Invalid option, try again" << reset << endl;
			break;
		}
	}
}
