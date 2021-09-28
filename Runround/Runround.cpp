/*
ID: paradox4
PROG: runround
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int M;

int digit(char a)
{
	switch (a)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		cout << "There was an error!!!" << endl;
	}
}

bool roundabout(const string number)
{
	int length = number.length();

	bool visited[9] = { false };
	bool digits[10] = { false };

	int current = 0;
	int currentDigit;
	
	for (int i = 0; i < length; i++)
	{
		currentDigit = digit(number[current]);

		if (visited[current] || digits[currentDigit])
			return false;
		
		visited[current] = true;
		digits[currentDigit] = true;

		current += currentDigit;

		current = current % length;
	}

	if (current == 0)
		return true;
	else
		return false;
}

int main()
{
	ifstream Input("runround.in");
	ofstream Output("runround.out");

	Input >> M;

	while (true)
	{
		M++;

		if (roundabout(to_string(M)))
		{
			Output << M << endl;
			return 0;
		}
	}

	return 0;
}
