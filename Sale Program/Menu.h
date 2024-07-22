#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Sale.h"
#include "Item.h"
using namespace std;

class Menu
{
public:
	Menu();
	~Menu();

	void AddItem(string name, string id, float price); //Done
	void RemoveItem(string id); //Done
	void EditItem(string id, string newName, string newId, float newPrice); //Done

	void AddSale(vector<string> orders); //Done
	void RemoveSale(int id); // Done
	void LoadSale(vector<string> orders, string time, int id, float total);

	float GetPriceOf(string id); //Done
	Item* SearchItem(string id); //Done
	Sale* SearchSale(int id); //Done

	void PrintItems(); //Done
	void PrintSale(); //Done

	bool ItemIdVerification(string id);

	void ClearMemory(); //Done

	Item* item;
	Sale* sale;
};