/*
ID: paradox4
PROG: milk2
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

void arrayTester(bool array[])
{
	ofstream Output("test.out");

	for (int i = 0; i < 1000000; i++)
		if (array[i] == 1)
			Output << i << endl;
}

int main()
{
	ifstream Input("milk2.in");
	ofstream Output("milk2.out");

	int N;
	Input >> N;

	bool cows[1000000] = { 0 };

	int start, end, Start = 1000000, End = 0;

	for (int i = 0; i < N; i++)
	{
		Input >> start >> end;

		if (start < Start)
			Start = start;
		if (end > End)
			End = end;

		for (int k = start; k < end; k++)
			cows[k] = 1;
	}
	
	int longestMilk = 0;
	int longestNoMilk = 0;

	//arrayTester(cows);

	int currentSpot = Start  - 1;
	int currentChainSize;
	bool currentChain;

	while (currentSpot < End)
	{
		currentChainSize = 0;

		currentChain = cows[currentSpot + 1];
		
		do{
			currentSpot++;

			if (currentSpot >= End)
				break;

			currentChainSize++;
		} while (cows[currentSpot + 1] == currentChain);

		if (currentChain == false)
		{
			if (currentChainSize > longestNoMilk)
				longestNoMilk = currentChainSize;
		}
		else
		{
			if (currentChainSize > longestMilk)
				longestMilk = currentChainSize;
		}
	}

	Output << longestMilk << " " << longestNoMilk << endl;

	return 0;
}