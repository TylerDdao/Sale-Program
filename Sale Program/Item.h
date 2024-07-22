#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Item
{
	string name;
	string id;
	float price;
public:
	Item* next;

	Item();
	Item(string name, string id, float price);
	~Item();

	bool SetName(string name);
	bool SetId(string id);
	bool SetPrice(float price);

	string GetName();
	string GetId();
	float GetPrice();
};
