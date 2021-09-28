/*
ID: paradox4
PROG: sort3
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int N;
int numbers[1000];
int counts[4];
int places[4][4]; //places[i][j] means the number of j's in i's territory.

int swap(int i, int j)
{
	int smaller = places[i][j];

	if (places[j][i] < places[i][j])
		smaller = places[j][i];

	places[i][j] -= smaller;
	places[j][i] -= smaller;

	return smaller;
}

int main()
{
	ifstream Input("sort3.in");
	ofstream Output("sort3.out");

	Input >> N;

	for (int i = 0; i < N; i++)
		Input >> numbers[i];

	for (int i = 0; i < N; i++)
		counts[numbers[i]]++;

	int j = 0;
	int sum = 0;
	for (int i = 1; i <= 3; i++)
	{
		sum += counts[i];

		for (j; j < sum; j++)
			places[i][numbers[j]]++;
	}
	
	int perfectSwaps = 0;

	perfectSwaps += swap(1, 2);
	perfectSwaps += swap(1, 3);
	perfectSwaps += swap(2, 3);

	Output << perfectSwaps + 2 * (places[1][3] + places[3][1]) << endl;

	return 0;
}