/*
ID: paradox4
PROG: nocows
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int N, K;

int counts[200][100];

void fill(int n, int k)
{
	for (int i = 1; i < n; i += 2)
	{
		for(int j = 1; j <= k - 1; j++)
			counts[n][k] += counts[i][k - 1]*counts[n - i - 1][j];
			counts[n][k] %= 9901;
	}

	for (int i = 1; i < n; i += 2)
	{
		for (int j = 1; j < k - 1; j++)
			counts[n][k] += counts[i][k - 1] * counts[n - i - 1][j];
			counts[n][k] %= 9901;
	}

	counts[n][k] %= 9901;


}

int main()
{
	ifstream Input("nocows.in");
	ofstream Output("nocows.out");

	Input >> N >> K;

	counts[1][1] = 1;

	for (int i = 3; i < 200; i += 2)
	{
		for (int j = 1; j < 100; j++)
			fill(i, j);
	}

	Output << counts[N][K] << endl;

	return 0;
}