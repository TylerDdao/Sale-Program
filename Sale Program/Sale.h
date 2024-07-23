#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Randomizer.h"
#include "Time.h"
using namespace std;

class Sale
{
	string time;
	vector<string> ordersList;
	float total;
	int id;
public:
	Sale* next;

	Sale();
	Sale(vector<string> orders, float total);
	~Sale();

	void LoadSale(vector<string> orders, float total, string time, int id);
	void Print();

	string GetTime();
	vector<string> GetOrders();
	float GetTotal();
	int GetId();
};