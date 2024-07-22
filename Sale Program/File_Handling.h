#pragma once
#include "Menu.h"
#include <fstream>
#include <sstream>
using namespace std;

bool SaveItems(string fileName, Menu menu); //Done
bool LoadItems(string fileName, Menu& menu); //Done