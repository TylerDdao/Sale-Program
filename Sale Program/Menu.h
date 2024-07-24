#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Sale.h"
#include "Item.h"
#include "Ui.h"
using namespace std;

class Menu
{
public:
	Menu();
	~Menu();

	void AddItem(string name, string id, float price); //Done
	void RemoveItem(string id); //Done
	void EditItem(string id, string newName, string newId, float newPrice); //Done

	int AddSale(vector<string> orders); //Done
	void RemoveSale(int id); // Done
	void LoadSale(vector<string> orders, string time, int id, float total); //Done

	float GetPriceOf(string id); //Done
	Item* SearchItem(string id); //Done
	Sale* SearchSale(int id); //Done

	void PrintItems(); //Done
	void PrintItem(string id); //Done
	void PrintSales(); //Done
	void PrintSale(int id); //Done
	void PrintSale(Sale sale); //Done
	void PrintSaleByTime(int day, int month, int year);
	bool ItemIdVerification(string id); //Done

	void EndOfDaySaleSummary(); //Done but haven't released

	void ClearSales(); //Done
	void ClearItems(); //Done
	void ClearMemory(); //Done

	Item* item;
	Sale* sale;
};