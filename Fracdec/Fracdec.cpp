/*
ID: paradox4
PROG: fracdec
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int n, d;

int reached[100010];

int out[100010];

int main()
{
	ifstream Input("fracdec.in");
	ofstream OutputFile("fracdec.out");

	ostringstream Output;

	for (int k = 0; k < 100010; k++)
		reached[k] = -1;

	Input >> n >> d;

	Output << n / d << ".";

	n = n % d;

	if (n == 0)
		Output << "0";

	int step;

	for (step = 0; reached[n] == -1; step++)
	{
		reached[n] = step;

		n *= 10;

		out[step] = n / d;

		n = n % d;
	}

	int i = 0;

	for (i; i < reached[n]; i++)
		Output << out[i];

	if (!(i == step - 1 && out[i] == 0))
	{
		Output << "(";

		for (i; i < step; i++)
			Output << out[i];

		Output << ")";
	}

	string stringy;

	stringy = Output.str();

	int j;

	for (j = 0; j < stringy.size(); j++)
	{
		if (j % 76 == 0 && j != 0)
			OutputFile << endl;

		OutputFile << stringy[j];
	}

	OutputFile << endl;

	return 0;
}