/*
ID: paradox4
PROG: shopping
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

struct offer
{
	int n;

	int k[1005];

	int price;

	int redu;

	bool valid;
};

int s, b;

offer offers[99];

int savings[105][10000];

int items[3][5]; //items[0] is the codes, item[1] is the amount and items[2] is the prices.

int target;

int subtract(int a, int offer_no)
{
	offer_no--;

	if (!offers[offer_no].valid)
		return -1;

	int unrank[5];

	for (int i = 0; i < 5; i++)
	{
		unrank[i] = a % 6;
		a /= 6;
	}

	for (int i = 0; i < 5; i++)
	{
		unrank[i] -= offers[offer_no].k[items[0][i]];

		if (unrank[i] < 0)
			return -1;
	}

	int rank = 0;

	for (int i = 0; i < 5; i++)
	{
		rank += unrank[4 - i];
		rank *= 6;
	}

	return (rank / 6);
}

int main()
{
	ifstream Input("shopping.in");
	ofstream Output("shopping.out");

	Input >> s;

	int a;

	for (int i = 0; i < s; i++)
	{
		Input >> offers[i].n;
		
		for (int j = 0; j < offers[i].n; j++)
		{
			Input >> a;
			Input >> offers[i].k[a];
		}

		Input >> offers[i].price;
	}

	Input >> b;

	//Input products
	for (int i = 0; i < b; i++)
	{
		Input >> items[0][i] >> items[1][i] >> items[2][i];
	}

	for (int i = 1; i <= b; i++)
	{
		target += items[1][b - i];
		target *= 6;
	}

	target /= 6;



	//Make sure offers are valid
	bool check;

	for (int i = 0; i < s; i++)
	{
		offers[i].valid = true;

		for (int j = 0; j < 1000; j++)
		{
			if (offers[i].k[j] != 0)
			{
				check = false;

				for (int k = 0; k < b; k++)
				{
					if (items[0][k] == j)
					{
						check = true;
						break;
					}
				}

				if (!check)
				{
					offers[i].valid = false;
					break;
				}
			}
		}
	}

	//Set offers redu
	for (int i = 0; i < s; i++)
	{
		a = 0; //a is the value of this offer

		for (int j = 0; j < 1000; j++)
		{
			if (offers[i].k[j] != 0)
			{
				for (int k = 0; k < b; k++)
				{
					if (items[0][k] == j)
					{
						a += items[2][k]* offers[i].k[j];
					}
				}
				
			}
		}

		offers[i].redu = a - offers[i].price;
	}

	for (int i = 1; i <= s; i++)
	{
		for (int j = 1; j <= 7776; j++)
		{
			a = subtract(j, i);

			if (a == -1)
				savings[i][j] = savings[i - 1][j];

			else
				savings[i][j] = max(savings[i-1][j], savings[i][subtract(j,i)] + offers[i - 1].redu);
		}
	}

	a = 0;

	for (int i = 0; i < b; i++)
		a += items[1][i] * items[2][i];

	Output << a - savings[s][target] << endl;

	return 0;
}
 
/*
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			for (int k = 0; k < R; k++)
			{
				for (int l = 0; l < C; l++)
				{
					distaa[i][j][k][l] = LARGE;
				}
			}
		}
	}
*/