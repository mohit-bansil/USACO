/*
ID: paradox4
PROG: ratios
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int gold[3];

int mix[4][3];

int main()
{
	ifstream Input("ratios.in");
	ofstream Output("ratios.out");

	for (int i = 0; i < 3; i++)
		Input >> gold[i];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			Input >> mix[i][j];

	for (int i = 0; i < 3; i++)
		mix[3][i] = 10000;

	int min = 40000;

	bool bad;

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			for (int k = 0; k <= 100; k++)
			{
				if (i == 0 && j == 0 && k == 0)
					continue;

				if (i + j + k >= min)
					continue;

				bad = false;

				for (int l = 0; l < 3; l++)
				{
					if (gold[l] != 0)
						continue;

					if (i*mix[0][l] != 0)
						bad = true;

					if (j*mix[1][l] != 0)
						bad = true;

					if (k*mix[2][l] != 0)
						bad = true;
				}

				if (bad)
					continue;

				if (gold[0] != 0 && (i*mix[0][0] + j*mix[1][0] + k*mix[2][0]) % gold[0] != 0)
					continue;

				if (gold[1] != 0 && (i*mix[0][1] + j*mix[1][1] + k*mix[2][1]) % gold[1] != 0)
					continue;

				if (gold[2] != 0 && (i*mix[0][2] + j*mix[1][2] + k*mix[2][2]) % gold[2] != 0)
					continue;

				if (gold[0] != 0 && gold[1] != 0)
					if ((i*mix[0][0] + j*mix[1][0] + k*mix[2][0]) / gold[0] != (i*mix[0][1] + j*mix[1][1] + k*mix[2][1]) / gold[1])
						continue;

				if (gold[0] != 0 && gold[2] != 0)
					if ((i*mix[0][0] + j*mix[1][0] + k*mix[2][0]) / gold[0] != (i*mix[0][2] + j*mix[1][2] + k*mix[2][2]) / gold[2])
						continue;

				if (gold[1] != 0 && gold[2] != 0)
					if ((i*mix[0][1] + j*mix[1][1] + k*mix[2][1]) / gold[1] != (i*mix[0][2] + j*mix[1][2] + k*mix[2][2]) / gold[2])
						continue;

				min = i + j + k;

				mix[3][0] = i;
				mix[3][1] = j;
				mix[3][2] = k;

			}
		}
	}

	int lambda = 0;

	if (gold[0] != 0)
		lambda = (mix[3][0]*mix[0][0] + mix[3][1]*mix[1][0] + mix[3][2]*mix[2][0]) / gold[0];

	if (gold[1] != 0)
		lambda = (mix[3][0] * mix[0][1] + mix[3][1] * mix[1][1] + mix[3][2] * mix[2][1]) / gold[1];

	if (gold[2] != 0)
		lambda = (mix[3][0] * mix[0][2] + mix[3][1] * mix[1][2] + mix[3][2] * mix[2][2]) / gold[2];

	if (min == 40000)
	{
		Output << "NONE" << endl;
		return 0;
	}

	Output << mix[3][0] << " " << mix[3][1] << " " << mix[3][2] << " " << lambda << endl;

	return 0;
}