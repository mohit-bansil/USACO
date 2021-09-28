/*
ID: paradox4
PROG: rockers
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int N, T, M;

int songs[20];
int hold[20];

int f[21][21];

int m(int a, int b)
{
	for (int i = a; i < b; i++)
		hold[i] = songs[i];

	sort(hold + a, hold + b);

	int thing = 0;

	int i;

	for (i = a; i < b && thing <= T; i++)
	{
		thing += hold[i];
	}

	if (thing <= T)
		return b - a;

	else
		return i - a - 1;

	return 0;
}

int main()
{
	ifstream Input("rockers.in");
	ofstream Output("rockers.out");
	
	Input >> N >> T >> M;

	for (int i = 0; i < N; i++)
		Input >> songs[i];

	int max;

	for (int y = 1; y <= M; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			max = 0;

			for (int i = 0; i <= x; i++)
			{
				if (max < f[x - i][y - 1] + m(x - i, x))
					max = f[x - i][y - 1] + m(x - i, x);
			}

			f[x][y] = max;
		}
	}

	Output << f[N][M] << endl;

	return 0;
}