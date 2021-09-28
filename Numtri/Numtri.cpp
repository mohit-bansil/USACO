/*
ID: paradox4
PROG: numtri
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int N;

int main()
{
	ifstream Input("numtri.in");
	ofstream Output("numtri.out");

	Input >> N;

	unsigned short triangle[1002][1002];
	int sums[1002][1002];
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			Input >> triangle[i][j];

	sums[0][0] = triangle[0][0];

	int number;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			number = 0;

			if (j < i)
				number = sums[i - 1][j];

			if (j > 0)
				if (sums[i - 1][j - 1] > number)
					number = sums[i - 1][j - 1];

			sums[i][j] = number + triangle[i][j];
		}
	}

	int max = 0;

	for (int j = 0; j < N; j++)
	{
		if (sums[N - 1][j] > max)
			max = sums[N - 1][j];
	}

	Output << max << endl;

	return 0;
}