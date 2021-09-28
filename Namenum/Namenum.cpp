/*
ID: paradox4
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

char charToNumber(char letter)
{
	switch (letter)
	{
		case 'A':
		case 'B':
		case 'C':
			return '2';
		case 'D':
		case 'E':
		case 'F':
			return '3';
		case 'G':
		case 'H':
		case 'I':
			return '4';
		case 'J':
		case 'K':
		case 'L':
			return '5';
		case 'M':
		case 'N':
		case 'O':
			return '6';
		case 'P':
		case 'R':
		case 'S':
			return '7';
		case 'T':
		case 'U':
		case 'V':
			return '8';
		case 'W':
		case 'X':
		case 'Y':
			return '9';
		case 'Q':
		case 'Z':
			return '0';
		default:
			cout << "Error 1" << endl;
			return 'a';
	}
}

string stringToNumber(string name)
{
	string number = "";

	for (int i = 0; i < name.size(); i++)
		number += charToNumber(name[i]);

	return number;
}

int main()
{
	ifstream Input("namenum.in");
	ofstream Output("namenum.out");
	ifstream Dictionary("dict.txt");

	string serial;
	Input >> serial;

	int size = serial.size();

	string name;

	bool nothingPrinted = true;

	while (true)
	{
		Dictionary >> name;

		if (Dictionary.eof())
			break;

		if (name.size() == size && stringToNumber(name) == serial)
		{
			Output << name << endl;
			nothingPrinted = false;
		}
	}

	if (nothingPrinted)
		Output << "NONE" << endl;

	return 0;
}