/*
ID: paradox4
PROG: butter
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

const int LARGE = 9999999;

int N, P, C;

int main()
{
	ifstream Input("butter.in");
	ofstream Output("butter.out");

	Input >> N >> P >> C;

	int dist[801][801];

	int cows[501];

	for (int i = 1; i <= 800; i++)
		for (int j = 1; j <= 800; j++)
			dist[i][j] = LARGE;

	int a, b, c;

	for (int i = 1; i <= N; i++)
		Input >> cows[i];

	for (int i = 1; i <= C; i++)
	{
		Input >> a >> b >> c;

		dist[a][b] = c;
		dist[b][a] = c;
	}

	for (int i = 1; i <= P; i++)
		dist[i][i] = 0;

	for (int k = 1; k <= P; k++)
	{
		for (int i = 1; i <= P; i++)
		{
			for (int j = 1; j <= P; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int min = LARGE;
	int min_pas = 0;

	int sum;

	for (int i = 1; i <= P; i++)
	{
		sum = 0;

		for (int j = 1; j <= N; j++)
			sum += dist[i][cows[j]];

		if (min > sum)
		{
			min = sum;
			min_pas = i;
		}
	}

	Output << min << endl;

	return 0;
}