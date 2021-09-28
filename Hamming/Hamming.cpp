/*
ID: paradox4
PROG: hamming
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<bitset>

using namespace std;

int N, B, D;

int hammingDistance(int a, int b)
{
	bitset<8> c(a);
	bitset<8> d(b);

	int distance = 0;

	for (int i = 0; i < B; i++)
	{
		if (c[i] != d[i])
			distance++;
	}

	return distance;
}

int main()
{
	ifstream Input("hamming.in");
	ofstream Output("hamming.out");

	Input >> N >> B >> D;

	int codewords[64];

	codewords[0] = 0;

	int currentNoOfCodes = 1;
	int k = 1;
	bool pass = true;
	
	while (currentNoOfCodes < N)
	{
		for (int i = 0; i < currentNoOfCodes; i++)
		{
			if (hammingDistance(k, codewords[i]) < D)
			{
				pass = false;
				break;
			}
		}
		
		if (pass)
		{
			codewords[currentNoOfCodes] = k;
			currentNoOfCodes++;
		}
		
		pass = true;
		k++;
	}

	int l = 0;
	while (l < N)
	{
		for (l; l % 10 < 9; l++)
		{
			if (l == N - 1)
				break;

			Output << codewords[l] << " ";
		}

		Output << codewords[l] << endl;
		l++;
	}
	
	return 0;
}