/*
ID: paradox4
PROG: lamps
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int N, C;

bool lamps[8];

bool allowed[101];
bool notAllowed[101];

void intilizeLamps(bool currentLamps[], int a)
{
	for (int i = 1; i <= N; i++)
		currentLamps[i] = true;

	if (a >= 4)
	{
		a -= 4;

		for (int i = 1; i <= N; i += 2)
			currentLamps[i] = false;
	}

	if (a >= 2)
	{
		a -= 2;

		for (int i = 2; i <= N; i += 2)
			currentLamps[i] = false;
	}

	if (a == 1)
	{
		for (int i = 1; i <= N; i += 3)
			currentLamps[i] = !currentLamps[i];
	}
}

int main()
{
	ifstream Input("lamps.in");
	ofstream Output("lamps.out");

	Input >> N >> C;

	int a;

	Input >> a;

	while (a != -1)
	{
		allowed[a] = true;
		Input >> a;
	}

	Input >> a;

	while (a != -1)
	{
		notAllowed[a] = true;
		Input >> a;
	}

	switch (C)
	{
	case 0:
		lamps[0] = true;
		break;
	case 1:
		lamps[6] = true;
		lamps[4] = true;
		lamps[2] = true;
		lamps[1] = true;
		break;
	case 2:
		for (int i = 0; i < 8; i++)
			lamps[i] = true;
		lamps[1] = false;
		break;
	default:
		for (int i = 0; i < 8; i++)
			lamps[i] = true;
		break;
	}
	
	int lampCount = 0;

	bool currentLamps[8][101];
	bool lampGood;

	for (int i = 0; i < 8; i++)
	{
		if (!lamps[i])
			continue;

		intilizeLamps(currentLamps[i], i);

		lampCount++;

		for (int j = 1; j <= N; j++)
		{
			if (allowed[j] && !currentLamps[i][j])
			{
				lamps[i] = false;
				lampCount--;
				break;
			}

			if (notAllowed[j] && currentLamps[i][j])
			{
				lamps[i] = false;
				lampCount--;
				break;
			}
		}
	}

	if (lampCount == 0)
	{
		Output << "IMPOSSIBLE" << endl;
		return 0;
	}

	int orderer[8] = { 6, 3, 4, 1, 7, 2, 5, 0 };

	int i;

	for (int j = 0; j < 8; j++)
	{
		i = orderer[j];

		if (lamps[i])
		{
			for (int j = 1; j <= N; j++)
				Output << currentLamps[i][j];

			Output << endl;
		}
	}

	return 0;
}
