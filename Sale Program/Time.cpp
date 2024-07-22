#define _CRT_SECURE_NO_WARNINGS

#include "Time.h"

string GetCurrentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return buf;
}

int ExtractYear(string time) {
	istringstream dateLine(time);
	string year;
	getline(dateLine, year, '-');
	return stoi(year);
}

int ExtractMonth(string time) {
	istringstream dateLine(time);
	string month;
	getline(dateLine, month, '-');
	getline(dateLine, month, '-');
	return stoi(month);
}

int ExtractDay(string time) {
	istringstream dateLine(time);
	string day;
	getline(dateLine, day, '-');
	getline(dateLine, day, '-');
	getline(dateLine, day, ' ');
	return stoi(day);
}