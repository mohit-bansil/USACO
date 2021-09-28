/*
ID: paradox4
PROG: maze1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct walls
{
	bool n = false;
	bool s = false;
	bool e = false;
	bool w = false;
};

const int ALOT = 21474836;

int W, H;

char maze_raw[202][202];

walls maze[102][102];

int dist1[102][102], dist2[102][102];

bool lock[102][102];

int exit1[2], exit2[2];

void intilize(int array_thingy[40][102], int intili)
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			array_thingy[i][j] = intili;
}

int main()
{
	ifstream Input("maze1.in");
	ofstream Output("maze1.out");

	Input >> W >> H;

	char junk[250];

	Input.getline(junk, 100);

	for (int i = 0; i < 2 * H + 1; i++)
	{
		Input.getline(junk, 100);

		for (int j = 0; j < 2 * W + 1; j++)
		{
			maze_raw[i][j] = junk[j];
		}
	}

	for (int i = 1; i < 2 * H + 1; i += 2)
	{
		for (int j = 1; j < 2 * W + 1; j += 2)
		{
			if (maze_raw[i - 1][j] == ' ')
				maze[i / 2][j / 2].n = true;
			if (maze_raw[i][j - 1] == ' ')
				maze[i / 2][j / 2].w = true;
			if (maze_raw[i + 1][j] == ' ')
				maze[i / 2][j / 2].s = true;
			if (maze_raw[i][j + 1] == ' ')
				maze[i / 2][j / 2].e = true;
		}
	}

	bool first_exit = false;

	for (int i = 0; i < H; i++)
	{
		if (maze[i][0].w)
		{
			maze[i][0].w = false;

			if (!first_exit)
			{
				exit1[0] = i;
				exit1[1] = 0;
				
				first_exit = true;
			}

			else
			{
				exit2[0] = i;
				exit2[1] = 0;
			}
		}

		if (maze[i][W - 1].e)
		{
			maze[i][W - 1].e = false;

			if (!first_exit)
			{
				exit1[0] = i;
				exit1[1] = W - 1;

				first_exit = true;
			}

			else
			{
				exit2[0] = i;
				exit2[1] = W - 1;
			}
		}
	}

	for (int j = 0; j < W; j++)
	{
		if (maze[0][j].n)
		{
			maze[0][j].n = false;

			if (!first_exit)
			{
				exit1[0] = 0;
				exit1[1] = j;

				first_exit = true;
			}

			else
			{
				exit2[0] = 0;
				exit2[1] = j;
			}
		}

		if (maze[H - 1][j].s) 
		{
			maze[H - 1][j].s = false;

			if (!first_exit)
			{
				exit1[0] = H - 1;
				exit1[1] = j;

				first_exit = true;
			}

			else
			{
				exit2[0] = H - 1;
				exit2[1] = j;
			}
		}
	}

	int a, b;
	int x, y;
	int min_dist;

	a = exit1[0];
	b = exit1[1];

	intilize(dist1, ALOT);

	dist1[a][b] = 0;
	lock[a][b] = true;

	y = a;
	x = b;

	for (int k = 1; k < 4000; k++)
	{

		if (maze[y][x].n && dist1[y - 1][x] > dist1[y][x])
			dist1[y - 1][x] = dist1[y][x] + 1;
		if (maze[y][x].w && dist1[y][x - 1] > dist1[y][x])
			dist1[y][x - 1] = dist1[y][x] + 1;
		if (maze[y][x].s && dist1[y + 1][x] > dist1[y][x])
			dist1[y + 1][x] = dist1[y][x] + 1;
		if (maze[y][x].e && dist1[y][x + 1] > dist1[y][x])
			dist1[y][x + 1] = dist1[y][x] + 1;

		min_dist = ALOT;

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (dist1[i][j] < min_dist && !lock[i][j])
				{
						x = j;
						y = i;
						min_dist = dist1[i][j];
				}
			}
		}

		lock[y][x] = true;
	}

	a = exit2[0];
	b = exit2[1];

	intilize(dist2, ALOT);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			lock[i][j] = false;
		}
	}

	dist2[a][b] = 0;
	lock[a][b] = true;

	y = a;
	x = b;

	for (int k = 1; k < 4000; k++)
	{

		if (maze[y][x].n && dist2[y - 1][x] > dist2[y][x])
			dist2[y - 1][x] = dist2[y][x] + 1;
		if (maze[y][x].w && dist2[y][x - 1] > dist2[y][x])
			dist2[y][x - 1] = dist2[y][x] + 1;
		if (maze[y][x].s && dist2[y + 1][x] > dist2[y][x])
			dist2[y + 1][x] = dist2[y][x] + 1;
		if (maze[y][x].e && dist2[y][x + 1] > dist2[y][x])
			dist2[y][x + 1] = dist2[y][x] + 1;

		min_dist = ALOT;

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (dist2[i][j] < min_dist && !lock[i][j])
				{
					x = j;
					y = i;
					min_dist = dist2[i][j];
				}
			}
		}

		lock[y][x] = true;
	}

	int max_dist = 0;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (dist1[i][j] > dist2[i][j])
				dist1[i][j] = dist2[i][j];

			if (max_dist < dist1[i][j])
				max_dist = dist1[i][j];
		}
	}



	Output << max_dist + 1 << endl;

	return 0;
}