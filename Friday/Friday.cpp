/*
ID: paradox4
PROG: friday
LANG: C++
*/
#include<iostream>
#include<fstream>

using namespace std;

bool isLeapYear(int year)
{
	if (year % 4 != 0)
		return false;
	else if (year % 100 == 0 && year % 400 != 0)
		return false;
	else
		return true;
}

int daysInMonth(int month, int year)
{
	switch (month) 
	{
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			if (isLeapYear(year))
				return 29;
			else
				return 28;
		default:
			return 31;
	}
}

void modDown(int& day)
{
	day = day % 7;
}

int main()
{
	ifstream Input("friday.in");
	ofstream Output("friday.out");
	
	int N;
	Input >> N;

	int Count[7] = { 0 };

	int year = 1900;
	int month = 1;
	int day = 0;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < 12; k++)
		{
			Count[day]++;

			day += daysInMonth(month, year);

			modDown(day);

			month++;
		}
		month = 1;
		year++;
	}

	for (int i = 0; i < 6; i++)
		Output << Count[i] << " ";

	Output << Count[6] << endl;

	return 0;
}