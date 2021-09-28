/*
ID: paradox4
PROG: preface
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int N;

string pageNumbers[3501];

int magnitude(int n)
{
	int magnitude = 1;

	while (magnitude < n)
		magnitude *= 10;

	return (magnitude / 10);
}

int main()
{
	ifstream Input("preface.in");
	ofstream Output("preface.out");

	Input >> N;

	pageNumbers[1] = "I";
	pageNumbers[5] = "V";
	pageNumbers[10] = "X";
	pageNumbers[50] = "L";
	pageNumbers[100] = "C";
	pageNumbers[500] = "D";
	pageNumbers[1000] = "M";

	pageNumbers[4] = "IV";
	pageNumbers[9] = "IX";
	pageNumbers[40] = "XL";
	pageNumbers[90] = "XC";
	pageNumbers[400] = "CD";
	pageNumbers[900] = "CM";

	for (int i = 2; i < 9; i++)
	{
		if (pageNumbers[i] != "")
			continue;

		pageNumbers[i] = pageNumbers[i - 1] + "I";
	}

	int mag, modulo;

	for (int i = 11; i < 3501; i++)
	{
		if (pageNumbers[i] != "")
			continue;
		
		modulo = i % 10;

		if (modulo != 0)
		{
			pageNumbers[i] = pageNumbers[i - modulo] + pageNumbers[modulo];
			continue;
		}

		mag = magnitude(i);
		
		if (i > 5 * mag)
		{
			if (i / mag != 9)
			{
				pageNumbers[i] = pageNumbers[5 * mag] + pageNumbers[i - 5 * mag];
				continue;
			}

			else
			{
				pageNumbers[i] = pageNumbers[mag] + pageNumbers[10 * mag] + pageNumbers[i - 9 * mag];
				continue;
			}
		}

		if (i / mag != 4)
			pageNumbers[i] = pageNumbers[mag] + pageNumbers[i - mag];
		else
			pageNumbers[i] = pageNumbers[mag] + pageNumbers[5 * mag] + pageNumbers[i - 4 * mag];
	}

	/*
	for (int i = 1; i <= 3500; i++)
		Output << i << " " << pageNumbers[i] << endl;
	*/
	
	int count[7];

	for (int i = 0; i < 7; i++)
		count[i] = 0;

	int length;

	for (int i = 1; i <= N; i++)
	{
		length = pageNumbers[i].length();

		for (int j = 0; j < length; j++)
		{
			switch (pageNumbers[i][j])
			{
				case 'I':
					count[0]++;
					break;
				case 'V':
					count[1]++;
					break;
				case 'X':
					count[2]++;
					break;
				case 'L':
					count[3]++;
					break;
				case 'C':
					count[4]++;
					break;
				case 'D':
					count[5]++;
					break;
				case 'M':
					count[6]++;
					break;
				default:
					cout << "ERROR!!! The program has encountered an unexpected error. Error Code:afnkj3xx8413485" << endl;
			}
		}

	}

	if (count[0] != 0)
		Output << 'I' << " " << count[0] << endl;

	if (count[1] != 0)
		Output << 'V' << " " << count[1] << endl;

	if (count[2] != 0)
		Output << 'X' << " " << count[2] << endl;

	if (count[3] != 0)
		Output << 'L' << " " << count[3] << endl;

	if (count[4] != 0)
		Output << 'C' << " " << count[4] << endl;

	if (count[5] != 0)
		Output << 'D' << " " << count[5] << endl;

	if (count[6] != 0)
		Output << 'M' << " " << count[6] << endl;
	
	return 0;
}
