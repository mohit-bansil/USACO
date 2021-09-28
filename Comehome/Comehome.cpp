/*
ID: paradox4
PROG: comehome
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

const int ALOT = 21474836;

int adj[52][52], dist[52][52] ;

int N;

int parse(char in)
{
	if (in <= 91)
		return (int) (in - 'A');
	else
		return (int)(in - 'a' + 26);
}

char unparse(int in)
{
	if (in <= 25)
		return in + 'A';
	else
		return (in - 26) + 'a';
}

void intilize(int array_thingy[52][52], int intili)
{
	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
			array_thingy[i][j] = intili;
}

int main()
{
	ifstream Input("comehome.in");
	ofstream Output("comehome.out");

	intilize(adj, ALOT);

	Input >> N;

	char a, b;
	int dis;

	for (int i = 0; i < N; i++)
	{
		Input >> a >> b >> dis;
		if (dis < adj[parse(a)][parse(b)])
		{
			adj[parse(a)][parse(b)] = dis;
			adj[parse(b)][parse(a)] = dis;
		}
	}

	for (int i = 0; i < 52; i++)
		adj[i][i] = 0;

	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
			dist[i][j] = adj[i][j];

	for (int k = 0; k < 52; k++)
	{
		for (int i = 0; i < 52; i++)
		{
			for (int j = 0; j < 52; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int min_dis = ALOT;
	int min_index = 0;

	for (int i = 0; i < 25; i++)
	{
		if (min_dis > dist[i][25])
		{
			min_dis = dist[i][25];
			min_index = i;
		}
	}

	Output << unparse(min_index) << " " << min_dis << endl;

	return 0;
}