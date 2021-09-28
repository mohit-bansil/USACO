/*
ID: paradox4
PROG: game1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::max;

int N;

int board[100];

int f[105][105];

int main()
{
	ifstream Input("game1.in");
	ofstream Output("game1.out");

	Input >> N;
	
	for (int i = 0; i < N; i++)
	{
		Input >> board[i];
		f[i][i] = board[i];
	}

	int b, sum;

	for (int d = 1; d < N; d++)
	{
		for (int a = 0; a < N - d; a++)
		{
			b = d + a;
			sum = 0;

			for (int i = a; i <= b; i++)
				sum += board[i];
			
			f[a][b] = max(sum - f[a + 1][b], sum - f[a][b - 1]);
		}
	}

	sum = 0;

	for (int i = 0; i < N; i++)
		sum += board[i];

	Output << f[0][N - 1] << " " << sum - f[0][N - 1] << endl;

	return 0;
}

