#include "File_Handling.h"

bool SaveItems(string fileName, Menu menu)
{
	Item* ptr = menu.item;
	ofstream fp;
	fp.open(fileName);
	if (!fp.is_open()) {
		return false;
	}
	while (ptr != nullptr) {
		fp << ptr->GetName() << ":" << ptr->GetId() << ":" << ptr->GetPrice() << endl;
		ptr = ptr->next;

	}
	fp.close();
	return true;
}

bool LoadItems(string fileName, Menu& menu)
{
	ifstream fp;
	fp.open(fileName);
	if (!fp.is_open()) {
		return false;
	}
	string line="\0";
	while (getline(fp, line)) {
		string name = "\0";
		string id = "\0";
		string price = "\0";
		istringstream isLine(line);
		getline(isLine, name, ':');
		getline(isLine, id, ':');
		getline(isLine, price);
		menu.AddItem(name, id, stof(price));
	}
}

bool SaveSales(string fileName, Menu menu)
{
	Sale* ptr = menu.sale;
	ofstream fp;
	fp.open(fileName);
	if (!fp.is_open()) {
		return false;
	}
	while (ptr != nullptr) {
		fp << ptr->GetId() << ";" << ptr->GetTime() << ";"<<ptr->GetTotal()<<";";
		for (int i = 0; i < ptr->GetOrders().size();i++) {
			fp << ptr->GetOrders()[i] << ",";
		}

		fp << endl;
		ptr = ptr->next;
	}
	fp.close();
	return true;
}

bool LoadSales(string fileName, Menu& menu)
{
	ifstream fp;
	fp.open(fileName);
	if (!fp.is_open()) {
		return false;
	}
	string line = "\0";
	while (getline(fp, line)) {
		string id = "\0";
		string time = "\0";
		string total = "\0";
		vector<string> orders;
		istringstream isLine(line);
		getline(isLine, id, ';');
		getline(isLine, time, ';');
		getline(isLine, total, ';');
		string data;
		while (getline(isLine, data, ',')) {
			orders.push_back(data);
		}
		menu.LoadSale(orders, time, stoi(id), stof(total));
	}
	fp.close();
	return true;
}

bool Save(Menu menu)
{
	if (SaveItems("Items.txt", menu) == false || SaveSales("Sales.txt", menu) == false) {
		return false;
	}
	return true;
}

bool Load(Menu& menu)
{
	if (LoadItems("Items.txt", menu) == false || LoadSales("Sales.txt", menu) == false) {
		return false;
	}
	return true;
}
