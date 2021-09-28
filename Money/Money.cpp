/*
ID: paradox4
PROG: money
LANG: C++
*/

#include<iostream>
#include<fstream>

#pragma comment(linker, "/STACK:900000000")

using namespace std;

int V, N;

int coins[26];

long long f[10001][26];

int main()
{
	ifstream Input("money.in");
	ofstream Output("money.out");

	Input >> V >> N;
	
	for (int i = 1; i <= V; i++)
		Input >> coins[i];
	
	for (int i = 1; i <= N; i++)
		f[i][1] = 1;

	for (int j = 1; j <= V; j++)
		f[0][j] = 1;

	long long sum;
	
		for (int i = 1; i <= N; i++)
	{
		for (int j = 2; j <= V; j++)
		{
			sum = 0;

			for (int k = 2; k <= j; k++)
			{
				if (i >= coins[k])
					sum += f[i - coins[k]][k];
			}

			if (i % coins[1] == 0)
				sum++;

			f[i][j] = sum;
		}
	}
	
	Output << f[N][V] << endl;

	return 0;
}
