/*
ID: paradox4
PROG: shuttle
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<int> shut[16];

void do_even(int a)
{
	int i;

	for (i = 0; shut[a-1][i] != -1; i++)
		shut[a].push_back(shut[a - 1][i] + 1);

	for (int j = 2*a + 1; j > 0; j -= 2)
		shut[a].push_back(j);

	shut[a].push_back(-1);

	for (int j = 2; j <= 2*a; j += 2)
		shut[a].push_back(j);

	i++;

	for(i; i < shut[a - 1].size(); i++)
		shut[a].push_back(shut[a - 1][i] + 1);

	return;
}

void do_odd(int a)
{
	int i;

	for (i = 0; shut[a - 1][i] != -1; i++)
		shut[a].push_back(shut[a - 1][i] + 1);

	for (int j = 1; j <= 2*a + 1; j += 2)
		shut[a].push_back(j);

	shut[a].push_back(-1);

	for (int j = 2 * a; j > 0; j -= 2)
		shut[a].push_back(j);

	i++;

	for (i; i < shut[a - 1].size(); i++)
		shut[a].push_back(shut[a - 1][i] + 1);

	return;
}

void advance(int a)
{
	if (a % 2 == 0)
		do_even(a);
	else
		do_odd(a);

	return;
}

int main()
{
	ifstream Input("shuttle.in");
	ofstream Output("shuttle.out");

	int N;

	Input >> N;

	int star[] = { 1, 3, -1, 2 };

	shut[1].assign(star, star + 4);

	for (int i = 2; i < 16; i++)
		advance(i);

	for (int i = 0; i < shut[N].size(); i++)
	{
		if (shut[N][i] == -1)
			shut[N].erase(shut[N].begin() + i);
	}

	for (int i = 0; i < shut[N].size() - 1; i++)
	{
		if (i % 20 == 19 && i != 0)
			Output << shut[N][i] << endl;

		else
			Output << shut[N][i] << " ";
	}
	
	Output << shut[N][shut[N].size() - 1] << endl;

	return 0;
}