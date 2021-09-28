/*
ID: paradox4
PROG: castle
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

const short MAX_M = 50;
const short MAX_N = 50;

short M, N;

short walls[MAX_M][MAX_N];
short components[MAX_M][MAX_N];
short sizeOfComponents[2501];
//bool nearby[51][51];

void fillComponent(int componentNumber)
{
	int num_visited = 1;
	int a;

	while (num_visited != 0)
	{
		num_visited = 0;

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (components[i][j] == -1)
				{
					num_visited++;
					components[i][j] = componentNumber;

					a = walls[i][j];

					if (a < 8)
					{
						if (components[i + 1][j] == 0)
							components[i + 1][j] = -1;
					}
					else
						a -= 8;

					if (a < 4)
					{ 
						if (components[i][j + 1] == 0)
							components[i][j + 1] = -1;
					}
					else
						a -= 4;

					if (a < 2)
					{
						if (components[i - 1][j] == 0)
							components[i - 1][j] = -1;
					}
					else
						a -= 2;

					if (a == 0 && components[i][j - 1] == 0)
						components[i][j - 1] = -1;
				}
			}
		}
	}
}

int findComponents() //returns number of components
{
	int num_components = 0;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (components[i][j] == 0)
			{
				num_components++;

				components[i][j] = -1;

				fillComponent(num_components);
			}
		}
	}

	return num_components;
}

int findLargestRoomSize()
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			sizeOfComponents[components[i][j]]++;

	int max = 0;

	for (int i = 1; i < 51; i++)
	{
		if (sizeOfComponents[i] > max)
			max = sizeOfComponents[i];
	}

	return max;
}

int main()
{
	ifstream Input("castle.in");
	ofstream Output("castle.out");

	Input >> N >> M;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			Input >> walls[i][j];

	int num_components = findComponents();

	Output << num_components << endl;
	Output << findLargestRoomSize() << endl;

	int maxRoomSize = 0;

	short wallX, wallY;
	char wallDirc;
	
	for (int j = 0; j < N; j++)
	{
		for (int i = M - 1; i >= 0; i--)
		{

			/*
			nearby[components[i][j]][components[i + 1][j]] = true;
			nearby[components[i][j]][components[i][j + 1]] = true;
			nearby[components[i + 1][j]][components[i][j]] = true;
			nearby[components[i][j + 1]][components[i][j]] = true;
			*/

			if (i != 0 && components[i][j] != components[i - 1][j])
			{
				if ((sizeOfComponents[components[i][j]] + sizeOfComponents[components[i - 1][j]]) > maxRoomSize)
				{
					maxRoomSize = sizeOfComponents[components[i][j]] + sizeOfComponents[components[i - 1][j]];

					wallX = i;
					wallY = j;
					wallDirc = 'N';
				}
			}

			if (j != N - 1 && components[i][j] != components[i][j + 1])
			{
				if ((sizeOfComponents[components[i][j]] + sizeOfComponents[components[i][j + 1]]) > maxRoomSize)
				{
					maxRoomSize = sizeOfComponents[components[i][j]] + sizeOfComponents[components[i][j + 1]];

					wallX = i;
					wallY = j;
					wallDirc = 'E';
				}
			}
		}
	}
	/*
	for (int i = 1; i <= num_components; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (nearby[i][j])
			{
				if ((sizeOfComponents[i] + sizeOfComponents[j]) >= maxRoomSize)
				{
					maxRoomSize = sizeOfComponents[i] + sizeOfComponents[j];
				}
			}
		}
	}
	*/

	Output << maxRoomSize << endl;
	Output << wallX + 1 << ' ' << wallY + 1 << ' ' << wallDirc << endl;

	return 0;
}