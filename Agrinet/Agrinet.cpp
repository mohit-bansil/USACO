/*
ID: paradox4
PROG: agrinet
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int N;

int adj[100][100];

struct node
{
	int dist;

	bool in;
};

node prim[100];

int main()
{
	ifstream Input;
	ofstream Output;

	Input.open("agrinet.in");
	Output.open("agrinet.out");

	Input >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Input >> adj[i][j];

	prim[0].in = true;

	for (int i = 0; i < N; i++)
		prim[i].dist = adj[0][i];

	int cost = 0;

	int min_dist, min_index;

	for (int i = 1; i < N; i++)
	{
		min_dist = 250000;

		for (int j = 0; j < N; j++)
		{
			if (prim[j].in)
				continue;

			if (prim[j].dist < min_dist)
			{
				min_dist = prim[j].dist;
				min_index = j;
			}
		}

		cost += min_dist;
		prim[min_index].in = true;

		for (int j = 0; j < N; j++)
		{
			if (prim[j].dist > adj[min_index][j])
				prim[j].dist = adj[min_index][j];
		}
	}

	Output << cost << endl;

	return 0;
}