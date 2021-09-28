/*
ID: paradox4
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int nameRanker(string name, string names[])
{
	for (int i = 0; i < 10; i++)
	{
		if (name == names[i])
			return i;
	}
	
	cout << "Error 1" << endl;
	return 0;
}

int main()
{
	ifstream Input("gift1.in");
	ofstream Output("gift1.out");
	
	int noPeople;
	Input >> noPeople;

	string names[10] = { "" };
	int paidIn[10] = { 0 };
	int paidOut[10] = { 0 };

	for (int i = 0; i < noPeople; i++)
		Input >> names[i];
	
	int money, people, moneyPerPerson, rank;
	string person;

	for (int i = 0; i < noPeople; i++)
	{
		Input >> person;

		Input >> money >> people;

		if (people != 0)
			moneyPerPerson = money / people;

		paidIn[nameRanker(person, names)] += moneyPerPerson * people;

		for (int k = 0; k < people; k++)
		{
			Input >> person;

			rank = nameRanker(person, names);
			
			paidOut[rank] += moneyPerPerson;
		}
	}

	for (int i = 0; i < noPeople; i++)
		Output << names[i] << " " << paidOut[i] - paidIn[i] << endl;

	return 0;
}