/*
ID: paradox4
PROG: theme
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int N;

int theme[5000];
int diff[5000];

bool check_diff(int len, int end)
{
	int stop = end - len;

	bool flag;

	for (int i = 0; i + len <= stop; i++)
	{
		flag = true;

		for (int j = 0; j < len; j++)
		{
			if (diff[i + j] != diff[stop + j + 1])
			{
				flag = false;
				break;
			}
		}

		if (flag)
			return true;
	}

	return false;
}

int main()
{
	ifstream Input("theme.in");
	ofstream Output("theme.out");
	
	Input >> N;

	if (N < 10)
	{
		Output << 0 << endl;
		return 0;
	}

	Input >> theme[0];

	for (int i = 1; i < N; i++)
	{
		Input >> theme[i];
		diff[i - 1] = theme[i] - theme[i - 1];
	}

	int best = 0;

	for (int i = 1; i < N - 1; i++)
	{
		if (check_diff(best, i))
			best++;
	}

	if (best < 5)
		Output << 0 << endl;

	else
		Output << best << endl;

	return 0;
}