/*
ID: paradox4
PROG: starry
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<assert.h>

using namespace std;

struct tup
{
	int x, y;
};

bool star[103][103];
int clus[103][103];
bool equala[501][501];

int csize[500];
char cassign[500];

int W, H;
int clusn;

void flood(int mark, int x, int y)
{
	clus[x][y] = mark;

	for (int j = -1; j <= 1; j++)
	{
		for (int i = -1; i <= 1; i++)
		{
			if (star[x + i][y + j] && clus[x + i][y + j] != mark)
			{
				assert(clus[x + i][y + j] == -1);
				flood(mark, x + i, y + j);
			}
		}
	}


}

void print_map(ofstream& Out)
{
	for (int j = 1; j <= H; j++)
	{
		for (int i = 1; i <= W; i++)
		{
			if (clus[i][j] == -1)
				Out << " ,";
			else
				Out << clus[i][j] << ",";
		}

		Out << endl;
	}
}

void print_sol(ofstream& Out)
{
	for (int j = 1; j <= H; j++)
	{

		for (int i = 1; i <= W; i++)
		{
			if (clus[i][j] == -1)
				Out << "0";
			else
				Out << cassign[clus[i][j]];
		}

		Out << endl;
	}
}

//Assumes that c1 and c2 have been verified to by the same size
bool tran_test(const int c1[100][100], const int c2[100][100], const int ma1, const int ma2)
{
	tup m1, m2;

	bool flag = false;

	for (int i = 0; i < 100; i++)
	{
		if (flag)
			break;

		for (int j = 0; j < 100; j++)
		{
			if (c1[i][j] == ma1)
			{
				m1.x = i;
				m1.y = j;

				flag = true;

				break;
			}
		}
	}

	flag = false;

	for (int i = 0; i < 100; i++)
	{
		if (flag)
			break;

		for (int j = 0; j < 100; j++)
		{
			if (c2[i][j] == ma2)
			{
				m2.x = i;
				m2.y = j;

				flag = true;

				break;
			}
		}
	}


	tup diff;
	diff.x = m1.x - m2.x;
	diff.y = m1.y - m2.y;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (c2[i][j] == ma2 &&( (j + diff.y < 0) || (j + diff.y >= 100) || c1[i+ diff.x][j + diff.y] != ma1))
				return false;
		}
	}

	return true;
}

void reflecter(const int c1[100][100], int c2[100][100])
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			c2[i][j] = c1[j][i];
		}
	}
}

void rotater(const int c1[100][100], int c2[100][100])
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			c2[i][j] = c1[j][99-i];
		}
	}
}

bool equiv_test(const int ma1, const int ma2)
{
	assert(ma1 != ma2);

	if (csize[ma1] != csize[ma2])
		return false;

	int c1[100][100];
	int c2[100][100];
	int hold[100][100];

	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (clus[i][j] == ma1)
				c1[i - 1][j - 1] = ma1;
			else if (clus[i][j] == ma2)
				c2[i - 1][j - 1] = ma2;
			else
			{
				c1[i - 1][j - 1] = -1;
				c2[i - 1][j - 1] = -1;
			}
		}
	}
	
	if (tran_test(c1, c2, ma1, ma2))
		return true;

	rotater(c1, hold);

	if (tran_test(hold, c2, ma1, ma2))
		return true;

	rotater(hold, c1);

	if (tran_test(c1, c2, ma1, ma2))
		return true;

	rotater(c1, hold);

	if (tran_test(hold, c2, ma1, ma2))
		return true;

	reflecter(hold, c1);

	if (tran_test(c1, c2, ma1, ma2))
		return true;

	rotater(c1, hold);

	if (tran_test(hold, c2, ma1, ma2))
		return true;

	rotater(hold, c1);

	if (tran_test(c1, c2, ma1, ma2))
		return true;

	rotater(c1, hold);

	if (tran_test(hold, c2, ma1, ma2))
		return true;

	return false;
}

void transitiveCloseRela(int a, bool rela[501][501])
{
	for (int k = 0; k < clusn; k++)
	{
		for (int i = 0; i < clusn; i++)
		{
			if (rela[a][i] && a != i)
			{
					for (int j = 0; j < clusn; j++)
					{
						if (rela[i][j])
							rela[a][j] = true;
				}
			}
		}
	}
}

void determine_equals()
{
	int check[500];

	for (int i = 0; i < clusn; i++)
		check[i] = -1;

	for (int i = 0; i < clusn; i++)
	{
		if (check[i] != -1)
			continue;

		for (int j = i+1; j < clusn; j++)
		{
			if (equiv_test(i, j))
			{
				equala[i][j] = true;
				check[j] = i;
			}
			else
				equala[i][j] = false;
		}
	}

	for (int i = 0; i < clusn; i++)
	{
		if (check[i] != -1)
		{
			for (int j = i + 1; j < clusn; j++)
			{
				equala[i][j] = equala[check[i]][j];
			}
		}
	}

	for (int i = 0; i < clusn; i++)
	{
		for (int j = 0; j < i; j++)
		{
			equala[i][j] = equala[j][i];
		}
	}

	for (int i = 0; i < clusn; i++)
		equala[i][i] = true;
}

void assign_chars()
{
	char current = 'a';

	for (int i = 0; i < clusn; i++)
	{
		if (cassign[i] == 0)
		{
			for (int j = i; j < clusn; j++)
			{
				if (equala[i][j])
					cassign[j] = current;
			}

			current++;
		}
	}
}

int main()
{
	ifstream Input("starry.in");
	ofstream Output("starry.out");

	Input >> W >> H;

	char a;

	for (int j = 1; j <= H; j++)
	{
		for (int i = 1; i <= W; i++)
		{
			Input >> a;
			if (a == '1')
				star[i][j] = true;
			else
				star[i][j] = false;
		}
	}

	for (int i = 0; i < 103; i++)
	{
		for (int j = 0; j < 103; j++)
		{
			clus[i][j] = -1;
		}
	}
	
	for (int j = 1; j <= H; j++)
	{
		for (int i = 1; i <= W; i++)
		{
			if (star[i][j] && clus[i][j] == -1)
			{
				flood(clusn, i, j);
				clusn++;
			}
		}
	}

	assert(clusn <= 500);

	for (int i = 1; i <= W; i++)
	{
		for (int j = 1; j <= H; j++)
		{
			if(clus[i][j] != -1)
				csize[clus[i][j]]++;
		}
	}

	determine_equals();

	assign_chars();

	print_sol(Output);

	return 0;
}



/*
void transitiveCloseRela(int a, bool rela[501][501])
{
bool check[501];

for (int i = 0; i < clusn; i++)
check[i] = false;

for (int k = 0; k < clusn; k++)
{
for (int i = 0; i < clusn; i++)
{
if (rela[a][i] && a != i)
{
if (!check[i]) {
for (int j = 0; j < clusn; j++)
{

if (rela[i][j])
{
rela[a][j] = true;
}
}
}

check[i] = true;
}
}
}
}
*/