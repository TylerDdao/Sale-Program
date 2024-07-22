#include "Menu.h"

Menu::Menu()
{
	sale = nullptr;
	item = nullptr;
}

Menu::~Menu()
{
}

void Menu::AddItem(string name, string id, float price)
{
	Item newItem(name, id, price);

	Item* ptr = new Item(newItem);
	if (ptr == NULL) {
		cerr << "Cannot allocate memory" << endl;
		return;
	}
	ptr->next = item;
	item = ptr;
	return;
}

void Menu::RemoveItem(string id)
{
	if (item == nullptr) {
		cerr << "Empty" << endl;
		return;
	}
	Item* ptr = item;
	while (ptr!= nullptr) {
		if (ptr->GetId() == id) {
			break;
		}
		ptr = ptr->next;
	}
	if (ptr == nullptr) {
		cerr << "ID is not found" << endl;
		return;
	}
	if (ptr == item) {
		item = ptr->next;
		delete ptr;
		return;
	}
	Item* ptr2 = item;
	while (ptr2->next = ptr) {
		ptr2 = ptr2->next;
	}
	ptr2->next = ptr->next;
	delete ptr;
	return;
}

void Menu::EditItem(string id, string newName, string newId, float newPrice)
{
	if (item == nullptr) {
		cerr << "Empty" << endl;
		return;
	}
	Item* ptr = SearchItem(id);
	if (ptr == nullptr) {
		cerr << "No ID found" << endl;
		return;
	}
	ptr->SetName(newName);
	ptr->SetId(newId);
	ptr->SetPrice(newPrice);
	return;
}

void Menu::AddSale(vector<string> orders)
{
	float total = 0;
	for (int i = 0; i < orders.size(); i++) {
		float price = GetPriceOf(orders[i]);
		total += price;
	}
	Sale newSale(orders, total);
	Sale* ptr = new Sale(newSale);
	if (ptr == NULL) {
		cerr << "Cannot allocate memory" << endl;
		return;
	}
	ptr->next = sale;
	sale = ptr;
	return;
}

void Menu::RemoveSale(int id)
{
	if (sale == nullptr) {
		cerr << "Empty" << endl;
		return;
	}
	Sale* ptr = SearchSale(id);
	if (ptr == nullptr) {
		cerr << "No sale found" << endl;
		return;
	}
	if (ptr == sale) {
		sale = ptr->next;
		delete ptr;
	}
	Sale* ptr2 = sale;
	while (ptr2->next != ptr) {
		ptr2 = ptr2->next;
	}
	ptr2->next = ptr->next;
	delete ptr;
	return;
}

float Menu::GetPriceOf(string id)
{
	Item* ptr = SearchItem(id);
	if (ptr == nullptr) {
		return -1;
	}
	float price = ptr->GetPrice();
	return price;
}

Item* Menu::SearchItem(string id)
{
	if (item == nullptr) {
		return nullptr;
	}
	Item* ptr = item;
	while (ptr != NULL) {
		if (ptr->GetId() == id) {
			break;
		}
		ptr = ptr->next;
	}
	return ptr;
}

Sale* Menu::SearchSale(int id)
{
	if (sale == nullptr) {
		return nullptr;
	}
	Sale* ptr = sale;
	while (ptr != NULL) {
		if (ptr->GetId() == id) {
			break;
		}
		ptr = ptr->next;
	}
	return ptr;
}

void Menu::PrintItems()
{
	if (item == nullptr) {
		cerr << "Empty" << endl;
		return;
	}
	Item* ptr = item;
	int count = 0;
	while (ptr != nullptr)
	{
		count++;
		cout << "Name: " << ptr->GetName() << endl;
		cout << "ID: " << ptr->GetId() << endl;
		cout << "Price: $" << ptr->GetPrice() << endl;
		cout << "********************" << endl;
		ptr = ptr->next;
	}
	cout << count << " Items" << endl;
	return;
}

void Menu::PrintSale()
{
	if (sale == nullptr) {
		cerr << "Empty" << endl;
		return;
	}
	Sale* ptr = sale;
	int count = 0;
	while (ptr != nullptr) {
		count++;
		cout << "Sale ID: " << ptr->GetId() << " at " << ptr->GetTime() <<endl;
		cout << "Total: $" << ptr->GetTotal() <<endl;
		cout << "********************" << endl;
		ptr = ptr->next;
	}
	cout << count << " Sales" << endl;
}

void Menu::ClearMemory()
{
	while (item != nullptr)
	{
		Item* iPtr = item;
		item = iPtr->next;
		delete iPtr;
	}
	while (sale != nullptr)
	{
		Sale* sPtr = sale;
		sale = sPtr->next;
		delete sPtr;
	}
}

