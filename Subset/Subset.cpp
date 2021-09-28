/*
ID: paradox4
PROG: subset
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int partition(int n, int k)
{
	if (n > (k * (k + 1) / 2))
		return 0;

	if (n == 1 || k == 1)
		return 1;

	if (k >= n)
		return partition(n, n - 1) + 1;
	
	return partition(n - k, k - 1) + partition(n, k - 1);
}

int main()
{
	ifstream Input("subset.in");
	ofstream Output("subset.out");

	int N;

	Input >> N;

	int triangle = N * (N + 1) / 2;

	if (triangle % 2 == 1)
	{
		Output << 0 << endl;
		return 0;
	}

	int p[400][400];

	p[1][1] = 1;

	for (int k = 2; k < 400; k++)
		p[k][1] = 0;

	for (int k = 2; k < 400; k++)
	{
		for (int n = 1; n < 400; n++)
		{
			if (n > (k * (k + 1) / 2))
				p[n][k] = 0;

			else if (n == 1)
				p[n][k] = 1;

			else if (k >= n)
				p[n][k] = p[n][n - 1] + 1;

			else
				p[n][k] = p[n - k][k - 1] + p[n][k - 1];
		}
	}

	Output << p[triangle / 2][N - 1] << endl;
	
	return 0;
}