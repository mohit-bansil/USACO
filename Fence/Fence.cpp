/*
ID: paradox4
PROG: fence
LANG: C++
*/

#include<iostream>
#include<fstream>

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::endl;

int F;

int adj[501][501];

int pos;

int tour[1500];

void makeTour(int node)
{
	for (int i = 1; i <= 500; i++)
	{
		if (adj[node][i] > 0)
		{
			adj[node][i]--;
			adj[i][node]--;

			makeTour(i);
		}
	}

	tour[pos] = node;
	pos++;

	return;
}

int main()
{
	ifstream Input("fence.in");
	ofstream Output("fence.out");
	
	Input >> F;

	int a, b;

	for (int i = 0; i < F; i++)
	{
		Input >> a >> b;

		adj[a][b]++;
		adj[b][a]++;
	}

	int sum;

	for (int i = 1; i <= 500; i++)
	{
		sum = 0;

		for (int j = 1; j <= 500; j++)
			sum += adj[i][j];
		
		if (sum % 2 == 1)
		{
			makeTour(i);

			for (int i = pos - 1; i >= 0; i--)
				Output << tour[i] << endl;

			return 0;
		}
	}

	for (int i = 1; pos != F + 1; i++)
	{
		pos = 0;
		makeTour(i);
	}

	for (int i = pos - 1; i >= 0; i--)
		Output << tour[i] << endl;

	return 0;
}

