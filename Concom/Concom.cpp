/*
ID: paradox4
PROG: concom
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int triples;
int companies[101][101];

void intilize(bool thing[])
{
	for (int i = 0; i <= 100; i++)
	{
		thing[i] = false;
	}
}

int main()
{
	ifstream Input("concom.in");
	ofstream Output("concom.out");
	
	Input >> triples;

	int a, b;

	for (int i = 0; i < triples; i++)
	{
		Input >> a >> b;
		Input >> companies[a][b];
	}

	bool owned[101];

	for (int i = 1; i <= 100; i++)
	{
		intilize(owned);

		for (int j = 1; j <= 100; j++)
		{

			for (int k = 1; k <= 100; k++)
			{
				if (companies[i][k] > 50 && !owned[k])
				{
					owned[k] = true;

					for (int l = 1; l <= 100; l++)
					{
						if(companies[i][l] < 150)
							companies[i][l] += companies[k][l];
					}

					break;
				}
			}
		}

		for (int j = 1; j <= 100; j++)
		{
			if (owned[j])
				if (j != i)
					Output << i << " " << j << endl;
		}

	}


	return 0;
}