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
