/*
ID: paradox4
PROG: ttwo
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

char grid[10][10]; 

int x_pos[2], y_pos[2], dire[2]; //0 is north, 1 is east, 2 is south, 3 is west

int minutes;

bool push(int id)
{
	switch (dire[id])
	{
	case 0:
		if (y_pos[id] == 9 || grid[x_pos[id]][y_pos[id] + 1] == '*')
			return false;
		else
		{
			y_pos[id]++;
			return true;
		}
		break;
	case 1:
		if (x_pos[id] == 9 || grid[x_pos[id] + 1][y_pos[id]] == '*')
			return false;
		else
		{
			x_pos[id]++;
			return true;
		}
		break;
	case 2:
		if (y_pos[id] == 0 || grid[x_pos[id]][y_pos[id] - 1] == '*')
			return false;
		else
		{
			y_pos[id]--;
			return true;
		}
		break;
	case 3:
		if (x_pos[id] == 0 || grid[x_pos[id] - 1][y_pos[id]] == '*')
			return false;
		else
		{
			x_pos[id]--;
			return true;
		}
		break;
	}


}

void move()
{
	if (!push(0))
	{
		dire[0]++;
		dire[0] %= 4;
	}

	if (!push(1))
	{
		dire[1]++;
		dire[1] %= 4;
	}

	return;
}

int main()
{
	ifstream Input("ttwo.in");
	ofstream Output("ttwo.out");

	for (int j = 9; j >= 0; j--)
	{
		for (int i = 0; i < 10; i++)
		{
			Input >> grid[i][j];

			if (grid[i][j] == 'F')
			{
				x_pos[0] = i;
				y_pos[0] = j;
				grid[i][j] = '.';
			}

			else if (grid[i][j] == 'C')
			{
				x_pos[1] = i;
				y_pos[1] = j;
				grid[i][j] = '.';
			}
		}
	}

	for (int i = 0; x_pos[0] != x_pos[1] || y_pos[0] != y_pos[1]; minutes++)
	{
		move();
		i++;

		if (i > 100000)
		{
			minutes = 0;
			break;
		}
	}

	Output << minutes << endl;

	return 0;
}