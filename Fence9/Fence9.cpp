/*
ID: paradox4
PROG: fence9
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int n, m, p;

int main()
{
	ifstream Input("fence9.in");
	ofstream Output("fence9.out");

	Input >> n >> m >> p;

	int count = 0;

	for (int y = 1; y < m; y++)
	{
		if (n*y % m == 0)
			count++;

		if((n - p)*y % m == 0)
			count++;
	}

	int area = p*m;

	Output << (area / 2) - ((p + count) / 2) << endl;

	return 0;
}