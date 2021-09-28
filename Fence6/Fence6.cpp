/*
ID: paradox4
PROG: fence6
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int N;

struct edg
{
	int front_no;

	int back_no;

	bool back[101];

	int back_list[101];

	bool front[101];

	int front_list[101];

	int length;
};

edg edges[101];

int answer = 9999999;

void recurse(int length, int depth, int walk[], bool fromFront)
{
	if (depth > N + 1)
		return;

	if (length >= answer)
		return;

	if (walk[0] == walk[depth - 1] && depth != 1)
	{
		if (length < answer && fromFront)
			answer = length;

		return;
	}
	
	if (!fromFront)
	{
		for (int j = 1; j <= edges[walk[depth - 1]].front_no; j++)
		{
			walk[depth] = edges[walk[depth - 1]].front_list[j];

			if(edges[walk[depth]].front[walk[depth - 1]])
				recurse(length + edges[walk[depth - 1]].length, depth + 1, walk, true);
			else
				recurse(length + edges[walk[depth - 1]].length, depth + 1, walk, false );
		}

		return;
	}

	else
	{
		for (int j = 1; j <= edges[walk[depth - 1]].back_no; j++)
		{
			walk[depth] = edges[walk[depth - 1]].back_list[j];

			if (edges[walk[depth]].front[walk[depth - 1]])
				recurse(length + edges[walk[depth - 1]].length, depth + 1, walk, true);
			else
				recurse(length + edges[walk[depth - 1]].length, depth + 1, walk, false);
		}
	}
}

int main()
{
	ifstream Input("fence6.in");
	ofstream Output("fence6.out");
	
	Input >> N;

	int s;

	for (int i = 1; i <= N; i++)
	{
		Input >> s;
		Input >> edges[s].length >> edges[s].back_no >> edges[s].front_no;

		for (int j = 1; j <= edges[s].back_no; j++)
		{
			Input >> edges[s].back_list[j];
			edges[s].back[edges[s].back_list[j]] = true;
		}

		for (int j = 1; j <= edges[s].front_no; j++)
		{
			Input >> edges[s].front_list[j];
			edges[s].front[edges[s].front_list[j]] = true;
		}
	}

	int walk_base[200];

	for (int i = 1; i <= N; i++)
	{
		walk_base[0] = i;

		recurse(0, 1, walk_base, true);
	}

	Output << answer << endl;

	return 0;
}



/*
bool check(int a, int walk[])
{
if (a < answer)
{
answer = a;
return true;
}

else
return false;
}
*/