#include "Sale.h"

Sale::Sale()
{
	this->time = "\0";
	this->total = 0;
	next = nullptr;
	this->id = 0;
}

Sale::Sale(vector<string> orders, float total)
{
	this->id = 001;
	this->time = GetCurrentDateTime();
	this->total = total;
	ordersList = orders;
	next = nullptr;
}

Sale::~Sale()
{
}

string Sale::GetTime()
{
	return time;
}

vector<string> Sale::GetOrders()
{
	return ordersList;
}

float Sale::GetTotal()
{
	return total;
}

int Sale::GetId()
{
	return id;
}
