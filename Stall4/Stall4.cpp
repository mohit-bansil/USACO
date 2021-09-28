/*
ID: paradox4
PROG: stall4
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

const int LARGE = 9999999;

int N, M;

int cap[500][500];

void inti(int thingy[], int size, int val)
{
	for (int i = 0; i < 500; i++)
		thingy[i] = val;

	return;
}

void inti(bool thingy[], int size, int val)
{
	for (int i = 0; i < 500; i++)
		thingy[i] = val;

	return;
}

int main()
{
	ifstream Input("stall4.in");
	ofstream Output("stall4.out");

	Input >> N >> M;

	int s, a;

	for (int i = 1; i <= N; i++)
	{
		Input >> s;

		for (int j = 1; j <= s; j++)
		{
			Input >> a;

			cap[i][a + N] = 1;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cap[0][i] = 1;
	}

	for (int j = 1; j <= M; j++)
	{
		cap[j + N][450] = 1;
	}

	M = 460;

	int flow[500];
	int prev[500];
	bool visit[500];
	
	int totalflow = 0;
	int maxflow, maxloc;

	int j;

	while (true)
	{
		inti(flow, 460, 0);
		inti(prev, 460, -1);
		inti(visit, 460, false);

		flow[0] = LARGE;

		while (true)
		{
			maxflow = 0;
			maxloc = -1;

			for (int i = 0; i <= M; i++)
			{
				if (flow[i] > maxflow && !visit[i])
				{
					maxflow = flow[i];
					maxloc = i;
				}
			}

			if (maxflow == 0)
				break;

			if (maxloc == 450)
				break;

			for (int i = 0; i <= M; i++)
			{
				if (flow[i] < min(maxflow, cap[maxloc][i]))
				{
					flow[i] = min(maxflow, cap[maxloc][i]);
					prev[i] = maxloc;
				}
			}

			visit[maxloc] = true;			
		}

		if (maxflow == 0)
			break;

		totalflow += flow[450];

		j = 450;
		while (true)
		{
			if (prev[j] == -1)
				break;

			cap[prev[j]][j] -= flow[450];
			cap[j][prev[j]] += flow[450];

			j = prev[j];
		}

	}

	Output << totalflow << endl;

	return 0;
}