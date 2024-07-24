#pragma once
#include "Menu.h"
#include "File_Handling.h"
#include "Ui.h"
using namespace std;

bool Confirm(); //Done
bool Confirm(string message); //Done

void ConfigMode(Menu& menu); //Done
void SaleMode(Menu& menu); //Done
void ReportMode(Menu menu);