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
	Item* ptr = SearchItem(id);
	if (ptr == nullptr) {
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

int Menu::AddSale(vector<string> orders)
{
	float total = 0;
	for (int i = 0; i < orders.size(); i++) {
		float price = GetPriceOf(orders[i]);
		total += price;
	}
	Sale newSale(orders, total);
	Sale* ptr = new Sale(newSale);
	if (ptr == NULL) {
		return -1;
	}
	ptr->next = sale;
	sale = ptr;
	return ptr->GetId();
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
		return;
	}
	Sale* ptr2 = sale;
	while (ptr2->next != ptr) {
		ptr2 = ptr2->next;
	}
	ptr2->next = ptr->next;
	delete ptr;
	return;
}

void Menu::LoadSale(vector<string> orders, string time, int id, float total)
{

	Sale newSale;
	newSale.LoadSale(orders, total, time, id);
	Sale* ptr = new Sale(newSale);
	if (ptr == NULL) {
		cerr << "Cannot allocate memory" << endl;
		return;
	}
	ptr->next = sale;
	sale = ptr;
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
		cout <<on_cyan<< "Name: " << ptr->GetName() <<reset<< endl;
		cout << "ID: " << ptr->GetId() << endl;
		cout << "Price: $" << ptr->GetPrice() << endl;
		cout << "**********" << endl;
		ptr = ptr->next;
	}
	cout << count << " Items" << endl;
	return;
}

void Menu::PrintItem(string id)
{
	Item* ptr = SearchItem(id);
	if (ptr == nullptr) {
		return;
	}
	cout <<on_cyan<< "Name: " << ptr->GetName()<<reset << endl;
	cout << "ID: " << ptr->GetId() << endl;
	cout << "Price: $" << ptr->GetPrice() << endl;
	return;
}

void Menu::PrintSales()
{
	if (sale == nullptr) {
		cerr << "Empty" << endl;
		return;
	}
	Sale* ptr = sale;
	int count = 0;
	while (ptr != nullptr) {
		count++;
		cout <<on_cyan<< "Sale ID: "<< ptr->GetId() << " at " << ptr->GetTime()<<reset <<endl;
		cout << ptr->GetOrders().size() << " items" << endl;
		cout << "Total: $" << ptr->GetTotal() <<endl;
		cout << "********************" << endl;
		ptr = ptr->next;
	}
	cout << count << " Sales" << endl;
}

void Menu::PrintSale(int id)
{
	Sale* ptr = SearchSale(id);
	if (ptr == nullptr) {
		return;
	}
	cout << on_cyan << "Sale ID: " << ptr->GetId()<<" at "<<ptr->GetTime() << reset << endl;;
	cout << "Items:" << endl;
	for (int i = 0;i < ptr->GetOrders().size();i++) {
		PrintItem(ptr->GetOrders()[i]);
		cout << "**********" << endl;
	}
	cout<< ptr->GetOrders().size() << " items"<< endl;
	cout <<"Total: $" << ptr->GetTotal()<< endl;
	return;
}

void Menu::PrintSale(Sale sale)
{
	cout << "Items:" << endl;
	for (int i = 0;i < sale.GetOrders().size();i++) {
		PrintItem(sale.GetOrders()[i]);
		cout << "**********" << endl;
	}
	cout << sale.GetOrders().size() << " items" << endl;
	cout <<"Total: $"<< sale.GetTotal() << endl;
	return;
}

void Menu::PrintSaleByTime(int day, int month, int year)
{
	if (sale == nullptr) {
		return;
	}
	Sale* ptr = sale;
	while (ptr!=nullptr)
	{
		if (ExtractYear(ptr->GetTime()) == year) {
			if (ExtractMonth(ptr->GetTime()) == month) {
				if (ExtractDay(ptr->GetTime()) == day) {
					cout << on_cyan << "Sale ID: " << ptr->GetId() << " at " << ptr->GetTime() << reset << endl;
					cout << ptr->GetOrders().size() << " items" << endl;
					cout << "Total: $" << ptr->GetTotal() << endl;
					cout << "********************" << endl;
				}
			}
		}
		ptr = ptr->next;
	}
}

bool Menu::ItemIdVerification(string id)
{
	if (item == nullptr) {
		return true;
	}
	Item* ptr = SearchItem(id);
	if (ptr == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void Menu::EndOfDaySaleSummary()
{
	if (sale == nullptr) {
		return;
	}
	string time = GetCurrentDateTime();
	cout << on_cyan << ExtractDay(time) << "/" << ExtractMonth(time) << "/" << ExtractYear(time) << reset << endl;;
	int count = 0;
	float total = 0;
	Sale* ptr = sale;
	while (ptr != nullptr) {
		if (ExtractDay(ptr->GetTime()) == ExtractDay(time) && ExtractMonth(ptr->GetTime()) == ExtractMonth(time) && ExtractYear(ptr->GetTime()) == ExtractYear(time)) {
			count++;
			total += ptr->GetTotal();
		}
		ptr = ptr->next;
	}
	PrintSaleByTime(ExtractDay(time), ExtractMonth(time), ExtractYear(time));
	cout << "**********" << endl;
	cout << on_cyan << "Total: $" << total << reset << endl;
	cout << on_cyan << count<<" sales" << reset << endl;
}

void Menu::ClearSales()
{
	while (sale != nullptr)
	{
		Sale* sPtr = sale;
		sale = sPtr->next;
		delete sPtr;
	}
}

void Menu::ClearItems()
{
	while (item != nullptr)
	{
		Item* iPtr = item;
		item = iPtr->next;
		delete iPtr;
	}
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

