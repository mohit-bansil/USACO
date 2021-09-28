/*
ID: paradox4
PROG: camelot
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<math.h>

using std:: ifstream;
using std:: ofstream;
using std:: cout;
using std:: endl;
using std:: max;
using std:: abs;

int LARGE = 999;

int R, C, N;

int charToInt(char a)
{
	return ((int)(a - 'A'));
}

//Note that i,j,k,l,m,n are reserved for indexing variables

int main()
{
	//cout << "Program started" << endl;

	ifstream Input("camelot.in");
	ofstream Output("camelot.out");

	int distaa[31][31][31][31];

	int king[3];

	int knight[781][3];



	Input >> C >> R;

	char a;
	int b;

	Input >> a >> b;

	king[0] = charToInt(a);
	king[1] = b - 1;

	for (N = 0; !Input.eof(); N++)
	{
		Input >> a >> b;

		knight[N][0] = charToInt(a);
		knight[N][1] = b - 1;
	}
	N--;



	if (N == 0)
	{
		Output << 0 << endl;
		return 0;
	}
		
	if (R == 1 || C == 1)
	{
		Output << max(abs(knight[0][0] - king[0]), abs(knight[0][1] - king[1])) << endl;
		return 0;
	}



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

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			distaa[i][j][i][j] = 0;
		}
	}




	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			for (int k = 0; k < R; k++)
			{
				for (int l = 0; l < C; l++)
				{
					if (distaa[i][j][k][l] > distaa[k][l][i][j])
						distaa[i][j][k][l] = distaa[k][l][i][j];
				}
			}
		}
	}



	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			for (int m = 0; m < 21; m++)
			{
				for (int k = 0; k < R; k++)
				{
					for (int l = 0; l < C; l++)
					{
						if (distaa[i][j][k][l] != m)
							continue;

						if (k < R - 1 && l < C - 2)
							if(distaa[i][j][k + 1][l + 2] > m + 1)
								distaa[i][j][k + 1][l + 2] = m + 1;

						if (k < R - 2 && l < C - 1)
							if (distaa[i][j][k + 2][l + 1] > m + 1)
								distaa[i][j][k + 2][l + 1] = m + 1;

						if (k >= 1 && l < C - 2)
							if (distaa[i][j][k - 1][l + 2] > m + 1)
								distaa[i][j][k - 1][l + 2] = m + 1;

						if (k >= 2 && l < C - 1)
							if (distaa[i][j][k - 2][l + 1] > m + 1)
								distaa[i][j][k - 2][l + 1] = m + 1;

						if (k < R - 1 && l >= 2)
							if (distaa[i][j][k + 1][l - 2] > m + 1)
								distaa[i][j][k + 1][l - 2] = m + 1;

						if (k < R - 2 && l >= 1)
							if (distaa[i][j][k + 2][l - 1] > m + 1)
								distaa[i][j][k + 2][l - 1] = m + 1;

						if (k >= 1 && l >= 2)
							if (distaa[i][j][k - 1][l - 2] > m + 1)
								distaa[i][j][k - 1][l - 2] = m + 1;

						if (k >= 2 && l >= 1)
							if (distaa[i][j][k - 2][l - 1] > m + 1)
								distaa[i][j][k - 2][l - 1] = m + 1;
					}
				}
			}
		}
	}



	int min = 9999999999;
	int sum, temp;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (i == 12 && j == 12)
				sum = 0;

			sum = 0;

			for (int m = 0; m < N; m++)
			{
				sum += distaa[i][j][knight[m][0]][knight[m][1]];
			}
			
			if (sum >= min)
				continue;

			if (min > max(abs(i - king[0]), abs(j - king[1])) + sum)
				min = max(abs(i - king[0]), abs(j - king[1])) + sum;

			for (int k = 0; k < R; k++)
			{
				if (sum + abs(king[0] - k) >= min)
					continue;

				for (int l = 0; l < C; l++)
				{
					if (i == 1 && j == 3 && k == 4 && l == 3)
						cout << sum << " " << temp << " " << min << endl;

					if (sum + max(abs(king[0] - k), abs(king[1] - l)) >= min)
						continue;
					
					for (int m = 0; m < N; m++)
					{
						temp = sum;

						temp -= distaa[i][j][knight[m][0]][knight[m][1]];
						
						temp += distaa[k][l][knight[m][0]][knight[m][1]];
						temp += distaa[k][l][i][j];

						temp += max(abs(k - king[0]), abs(l - king[1]));

						if (min > temp)
							min = temp;
						
					}
				}
			}
		}
	}

	/*
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			sum = 0;

			for (int m = 0; m < N; m++)
			{
				sum += distaa[i][j][knight[m][0]][knight[m][1]];
			}

			sum += max(abs(i - king[0]), abs(j - king[1]));

			if (min == sum);
				//min = sum - 1;
		}
	}
	*/


	Output << min << endl;

	return 0;
}