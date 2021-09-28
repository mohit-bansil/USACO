/*
ID: paradox4
PROG: milk
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

void sortArray(int cost[], int amount[], int N) //N is the farmers
{
	int temp1, temp2;

	for (int i = 0; i < N; i++)
	{
		for (int k = N; k > i; k--)
		{
			if (cost[k] > cost[k - 1])
			{
				temp1 = cost[k - 1];
				cost[k - 1] = cost[k];
				cost[k] = temp1;

				temp2 = amount[k - 1];
				amount[k - 1] = amount[k];
				amount[k] = temp2;
			}
		}
	}
}

int main()
{
	ifstream Input("milk.in");
	ofstream Output("milk.out");

	int unitsOfMilk, farmers;

	Input >> unitsOfMilk >> farmers;

	int cost[5001], amount[5001];

	for (int i = 0; i < farmers; i++)
		Input >> cost[i] >> amount[i];

	sortArray(cost, amount, farmers);

	int money = 0;

	for (int i = farmers - 1; unitsOfMilk > 0; i--)
	{
		if (amount[i] < unitsOfMilk)
		{
			unitsOfMilk -= amount[i];
			money += cost[i] * amount[i];
		}

		else
		{
			money += cost[i] * unitsOfMilk;
			unitsOfMilk = 0;
		}
	}

	Output << money << endl;

	return 0;
}