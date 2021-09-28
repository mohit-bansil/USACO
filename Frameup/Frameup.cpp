/*
ID: paradox4
PROG: frameup
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>

using namespace std;

ifstream Input("frameup.in");
ofstream Output("frameup.out");

const int LARGE = 1147483647;

int H, W;

string frame_s[30];

char key[26];
int key_size;
int frame[30][30];
//relat[i][j] is 1 if the letter (frame) represented by i is greater than or equal to the letter represented by j
//it is -1 if it is less than
//and it is 0 if we don't know
int relat[26][26]; 

bool flag = false;

void makeIntFrame()
{
	bool loop_b;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (frame_s[i][j] == '.')
				frame[i][j] = -1;
			else
			{
				loop_b = false;

				for (int k = 0; k < key_size; k++)
				{
					if (key[k] == frame_s[i][j])
					{
						frame[i][j] = k;
						loop_b = true;
						break;
					}
				}

				if (!loop_b)
				{
					key[key_size] = frame_s[i][j];
					frame[i][j] = key_size;
					key_size++;
				}
			}
		}
	}

	return;
}

void anaylzeFrame(int a, int rela[26][26])
{
	int framel[30][30];

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (frame[i][j] == a)
				framel[i][j] = a;
			else
				framel[i][j] = -1;
		}
	}

	int u = LARGE, d = -1, l = LARGE, r = -1;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (framel[i][j] == a)
			{
				if (i < u)
					u = i;
				if (i > d)
					d = i;
				if (j < l)
					l = j;
				if (j > r)
					r = j;
			}
		}
	}

	for (int i = u; i <= d; i++)
	{
		rela[frame[i][l]][a] = 1;
		rela[frame[i][r]][a] = 1;
	}

	for (int j = l + 1; j < r; j++)
	{
		rela[frame[u][j]][a] = 1;
		rela[frame[d][j]][a] = 1;
	}

	return;
}

void symetrizeRela(int rela[26][26])
{
	for (int i = 0; i < key_size; i++)
	{
		for (int j = 0; j < key_size; j++)
		{
			if (i == j)
				rela[i][j] = 1;
			else if(rela[i][j] == 1)
				rela[j][i] = -1;
		}
	}
}

void transitiveCloseRela(int a, int rela[26][26])
{
	bool check[26];

	for (int i = 0; i < key_size; i++)
		check[i] = false;

	for (int k = 0; k < key_size; k++)
	{
		for (int i = 0; i < key_size; i++)
		{
			if (rela[a][i] == 1 && a != i)
			{
				if (!check[i]) {
				for (int j = 0; j < key_size; j++)
				{

						if (rela[i][j] == 1)
						{
							rela[a][j] = 1;
						}
					}
				}

				check[i] = true;
			}
		}
	}
}

void fillRela(int rela[26][26])
{
	for (int i = 0; i < key_size; i++)
		transitiveCloseRela(i, rela);

	symetrizeRela(rela);
}

struct tup
{
	int a, b;
};

bool isGreater(const tup x, const tup y)
{
	if (x.b > y.b)
		return true;
	else
		return false;
}

string extractOrdering(int rela[26][26])
{
	tup counter[26];

	for (int i = 0; i < key_size; i++)
	{
		counter[i].a = i;
		counter[i].b = 0;
	}

	for (int i = 0; i < key_size; i++)
	{
		for (int j = 0; j < key_size; j++)
		{
			if (rela[i][j] == -1)
				counter[i].b++;
		}
	}

	sort(counter, counter + key_size, isGreater);

	string answer = "";

	for (int i = 0; i < key_size; i++)
		answer += key[counter[i].a];

	return answer;
}

string answers[7000];
int answers_count;

void solveRelation(int rela[26][26], int i_check)
{
	fillRela(rela);

	bool isDone = true;

	for (int i = i_check; i < key_size; i++)
	{
		for (int j = i + 1; j < key_size && isDone; j++)
		{
			if (rela[i][j] == 0)
			{
				isDone = false;
				break;
			}
		}
	}

	if (isDone)
	{
		answers[answers_count] = extractOrdering(rela);
		answers_count++;
		return;
	}

	int rela_c[26][26];

	for (int i = 0; i < key_size; i++)
	{
		for (int j = 0; j < key_size; j++)
		{
			rela_c[i][j] = rela[i][j];
		}
	}

	for (int i = i_check; i < key_size; i++)
	{
		for (int j = i + 1; j < key_size; j++)
		{
			if (i == j)
				continue;

			if (rela_c[i][j] == 0)
			{
				rela_c[i][j] = 1;
				solveRelation(rela_c, i);

				rela[j][i] = 1;

				solveRelation(rela, i);

				return;
			}
		}
	}
}

int main()
{
	Input >> H >> W;

	for (int i = 0; i < H; i++)
		Input >> frame_s[i];

	makeIntFrame();

	for(int i = 0; i < key_size; i++)
		anaylzeFrame(i, relat);

	solveRelation(relat, 0);

	sort(answers, answers + answers_count);

	for (int i = 0; i < answers_count; i++)
		Output << answers[i] << endl;

	cout << answers_count << endl;

	return 0;
}
