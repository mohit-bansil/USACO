/*
ID: paradox4
PROG: ditch
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<assert.h>

using namespace std;

const int LARGE = 1147483647;

int N, M;

int cap[205][205];

void inti(int thingy[], int size, int val)
{
	for (int i = 0; i <= 203; i++)
		thingy[i] = val;

	return;
}

void inti(bool thingy[], int size, int val)
{
	for (int i = 0; i <= 203; i++)
		thingy[i] = val;

	return;
}

int main()
{
	ifstream Input("ditch.in");
	ofstream Output("ditch.out");

	Input >> N >> M;

	int a, b, c;

	for (int i = 1; i <= N; i++)
	{
		Input >> a >> b >> c;
				
		cap[a][b] += c;
	}

	int flow[205];
	int prev[205];
	bool visit[205];
	
	int totalflow = 0;
	int maxflow, maxloc;

	int j;

	while (true)
	{
		inti(flow, M, 0);
		inti(prev, M, -1);
		inti(visit, M, false);

		flow[1] = LARGE;

		while (true)
		{
			maxflow = 0;
			maxloc = -1;

			for (int i = 1; i <= M; i++)
			{
				if (flow[i] > maxflow && !visit[i])
				{
					maxflow = flow[i];
					maxloc = i;
				}
			}

			if (maxflow == 0)
				break;

			if (maxloc == M)
				break;

			for (int i = 1; i <= M; i++)
			{
				if (flow[i] < min(maxflow, cap[maxloc][i]))
				{
					flow[i] = min(maxflow, cap[maxloc][i]);
					prev[i] = maxloc;
				}
			}

			visit[maxloc] = true;			
		}

		if (maxloc == -1)
			break;

		totalflow += flow[M];

		j = M;
		while (true)
		{
			if (prev[j] == -1)
				break;

			cap[prev[j]][j] -= flow[M];
			cap[j][prev[j]] += flow[M];

			j = prev[j];
		}

	}

	Output << totalflow << endl;

	return 0;
}