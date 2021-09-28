/*
ID: paradox4
PROG: barn1
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

void sortArrayIncreasing(int arrayThing[], int N) //N is the number of things
{
	int temp1;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N - 1; k++)
		{
			if (arrayThing[k] > arrayThing[k + 1])
			{
				temp1 = arrayThing[k + 1];
				arrayThing[k + 1] = arrayThing[k];
				arrayThing[k] = temp1;
			}
		}
	}
}

void sortArrayDecreasing(int arrayThing[], int N) //N is the number of things
{
	int temp1;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N - 1; k++)
		{
			if (arrayThing[k] < arrayThing[k + 1])
			{
				temp1 = arrayThing[k + 1];
				arrayThing[k + 1] = arrayThing[k];
				arrayThing[k] = temp1;
			}
		}
	}
}

int main()
{
	ifstream Input("barn1.in");
	ofstream Output("barn1.out");
	
	int M, S, C;

	Input >> M >> S >> C;

	int cows[200], spaces[200];

	for (int i = 0; i < C; i++)
		Input >> cows[i];

	sortArrayIncreasing(cows, C);

	for (int i = 0; i < C - 1; i++)
		spaces[i] = cows[i + 1] - cows[i] - 1;
	
	sortArrayDecreasing(spaces, C - 1);

	int stallsSaved = 0;

	for (int i = 0; M > 1 && i < C - 1; M--, i++)
		stallsSaved += spaces[i];
	
	Output << cows[C - 1] - cows[0] - stallsSaved + 1 << endl;

	return 0;
}