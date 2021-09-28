/*
ID: paradox4
PROG: inflate
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int M, N;

int prob[10000][2];

int points[10005][2];

int recurse(int a, int b)
{
	if (a <= 0 || b <= 0)
		return 0;

	return max(recurse(a - prob[b][0], b) + prob[b][1], recurse(a, b - 1));
}

int main()
{
	ifstream Input("inflate.in");
	ofstream Output("inflate.out");

	Input >> M >> N;

	for (int i = 0; i < N; i++)
	{
		Input >> prob[i][0] >> prob[i][1];
	}

	
	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i - prob[j][1] < 0)
				points[i][1] = points[i][0];

			else
				points[i][1] = max(points[i - prob[j][1]][1] + prob[j][0], points[i][0]);

			points[i][0] = points[i][1];
		}
	}
	
	Output << points[M][1] << endl;

	//Output << recurse(M,N) << endl;

	return 0;
}