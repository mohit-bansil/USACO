/*
ID: paradox4
PROG: cowtour
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>

using namespace std;

const int ALOT = 21474836;

int N;

int location[2][150];

double adj[150][150], max_dist[150];

double distancea(int a, int b)
{
	int distx = location[0][a] - location[0][b];
	int disty = location[1][a] - location[1][b];

	double answer;
	
	answer =  sqrt((double)(distx*distx + disty*disty));

	return answer;
}

void intilize(double array_thingy[150][150], int intili)
{
	for (int i = 0; i < 150; i++)
		for (int j = 0; j < 150; j++)
			array_thingy[i][j] = intili;
}

int main()
{
	ifstream Input("cowtour.in");
	ofstream Output("cowtour.out");

	Input >> N;

	for (int i = 0; i < N; i++)
		Input >> location[0][i] >> location[1][i];

	intilize(adj, ALOT);
	char junk;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Input >> junk;

			if (junk == '1' || i == j)
				adj[i][j] = distancea(i, j);
		}
	}

	for (int k = 0; k < 150; k++)
	{
		for (int i = 0; i < 150; i++)
		{
			for (int j = 0; j < 150; j++)
			{
				if (adj[i][k] + adj[k][j] < adj[i][j])
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}

	for (int i = 0; i < 150; i++)
	{
		for (int j = 0; j < 150; j++)
		{
			if(adj[i][j] > ALOT / 2)
				adj[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (adj[i][j] > max_dist[i])
				max_dist[i] = adj[i][j];
		}
	}

	double max_inter = ALOT;

	double hold;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (adj[i][j] != -1)
				continue;

			hold = max_dist[i] + max_dist[j] + distancea(i, j);

			if (hold < max_inter)
				max_inter = hold;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		if (max_dist[i] > max_inter)
			max_inter = max_dist[i];
	}

	Output << fixed;
	Output << setprecision(6);

	Output << max_inter << endl;

	return 0;
}