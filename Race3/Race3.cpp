/*
ID: paradox4
PROG: race3
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int N;

bool adja[50][50];
bool adja_temp[51][51];

void clean_temp()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			adja_temp[i][j] = adja[i][j];
		}
	}
}

void intil(bool a[])
{
	for (int i = 0; i < 50; i++)
		a[i] = false;
}

bool test1(int n, bool adj[50][50])
{
	bool reach[50];

	intil(reach);

	reach[0] = true;

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			if (!reach[i] || i == n)
				continue;

			for (int j = 0; j < N; j++)
			{
				if (adj[i][j])
					reach[j] = true;
			}
		}
	}

	if (reach[N - 1])
		return false;
	else
		return true;
}

bool test2(int n, bool adj[50][50])
{
	bool reach[50];

	intil(reach);

	reach[0] = true;

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			if (!reach[i] || i == n)
				continue;

			for (int j = 0; j < N; j++)
			{
				if (adj[i][j])
					reach[j] = true;
			}
		}
	}

	if (reach[N - 1])
		return false;

	for (int i = 0; i < N; i++)
	{
		if (i == n)
			continue;

		for (int j = 0; j < N; j++)
		{
			if (j == n)
				continue;

			if (adj[i][j])
			{
				if (reach[i] != reach[j])
				{
					return false;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (adj[n][i] && reach[i] && i != n)
			return false;
	}


	return true;
}

int main()
{
	ifstream Input("race3.in");
	ofstream Output("race3.out");
	
	int a, b;

	while (true)
	{
		while (true)
		{
			Input >> b;

			if (b < 0)
				break;

			adja[N][b] = true;
		}

		if (b == -1)
			break;

		N++;
	}

	vector<int> un1;
	vector<int> un2;
	vector<int> un3;

	for (int i = 1; i < N - 1; i++)
	{
		if (test1(i, adja))
			un1.push_back(i);
	}

	for (auto i: un1)
	{
		if (test2(i, adja))
			un2.push_back(i);
	}

	Output << un1.size();

	for (auto i : un1)
		Output << ' ' << i;

	Output << endl;

	Output << un2.size();

	for (auto i : un2)
		Output << ' ' << i;

	Output << endl;

	return 0;
}

/*

bool test2(int n, bool adj[50][50])
{
if (adj[n][n])
return false;

bool reach[50];

intil(reach);

reach[0] = true;

for (int k = 0; k < N; k++)
{
for (int i = 0; i < N; i++)
{
if (!reach[i])
continue;

if (i != n)
{
for (int j = 0; j < N; j++)
{
if (adj[i][j] || adj[j][i])
reach[j] = true;
}
}

else
{
for (int j = 0; j < N; j++)
{
if (adj[i][j] || adj[j][i])
reach[j] = true;
}
}
}
}

if (reach[N - 1])
return false;
else
return true;
}
*/