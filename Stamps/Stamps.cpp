/*
ID: paradox4
PROG: stamps
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int N, K;

int stamps[50];

short cost[2000000];

int main()
{
	ifstream Input("stamps.in");
	ofstream Output("stamps.out");

	Input >> K >> N;
	
	for (int i = 0; i < N; i++)
		Input >> stamps[i];

	int i;

	for (i = 1; true; i++)
	{
		cost[i] = 500;

		for (int j = 0; j < N; j++)
		{
			if (i >= stamps[j] && cost[i - stamps[j]] + 1 < cost[i])
				cost[i] = cost[i - stamps[j]] + 1;
		}

		if (cost[i] > K)
			break;
	}

	Output << i - 1 << endl;

	return 0;
}