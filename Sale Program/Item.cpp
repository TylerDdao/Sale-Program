#include "Item.h"

Item::Item()
{
	this->id = "\0";
	this->name = "\0";
	this->price = 0;
	this->next = nullptr;
}

Item::Item(string name, string id, float price)
{
	this->id = id;
	this->name = name;
	this->price = price;
	this->next = nullptr;
}

Item::~Item()
{
}

bool Item::SetName(string name)
{
	this->name = name;
	return true;
}

bool Item::SetId(string id)
{
	this->id = id;
	return true;
}

bool Item::SetPrice(float price)
{
	this->price = price;
	return true;
}

string Item::GetName()
{
	return name;
}

string Item::GetId()
{
	return id;
}

float Item::GetPrice()
{
	return price;
}
