/*
ID: paradox4
PROG: holstein
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

short M, N; //M vitamins and N feeds
short requirements[25];
short vitamins[15][25];

void intilizeArray(bool arrayThing[])
{
	for (int i = 0; i <= N; i++)
		arrayThing[i] = false;
}

int solve(short reqs[], short vitasLeft, bool include[])
{
	if (vitasLeft == 0)
	{
		for (int i = 0; i < M; i++)
		{
			if (0 < reqs[i])
				return 1000;
		}

		return 0;
	}
	 
	short a, b;

	a = solve(reqs, vitasLeft - 1, include);

	//reqs - vitamin[vitasLeft]
	for (int i = 0; i < M; i++)
		reqs[i] -= vitamins[vitasLeft-1][i];

	bool include2[16];
	intilizeArray(include2);

	b = solve(reqs, vitasLeft - 1, include2) + 1;

	//fix reqs array
	for (int i = 0; i < M; i++)
		reqs[i] += vitamins[vitasLeft-1][i];

	if (a <= b)
		return a;

	else
	{
		for (int i = 0; i < N; i++)
			include[i] = include2[i];

		include[vitasLeft] = true;
		return b;
	}
}

int main()
{
	ifstream Input("holstein.in");
	ofstream Output("holstein.out");

	Input >> M;

	for (int i = 0; i < M; i++)
		Input >> requirements[i];

	Input >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			Input >> vitamins[i][j];

	bool vitaminsToGive[16];

	intilizeArray(vitaminsToGive);

	Output << solve(requirements, N, vitaminsToGive);

	for (int i = 0; i <= N; i++)
		if (vitaminsToGive[i])
			Output << " " << i;

	Output << endl;

	return 0;
}