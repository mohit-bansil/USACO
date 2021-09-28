/*
ID: paradox4
PROG: prefix
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string word;
string prims[210];

int length;
int N;
int lengths[210];

bool reachable[200011];

bool check(int prim, int location)
{
	if (location + lengths[prim] > length)
		return false;

	for (int i = 0; i < lengths[prim]; i++)
	{
		if (word[i + location] != prims[prim][i])
			return false;
	}

	return true;
}

int main()
{
	ifstream Input("prefix.in");
	ofstream Output("prefix.out");

	for (int i = 0; prims[i - 1].compare("."); i++)
	{
		Input >> prims[i];
		lengths[i] = prims[i].length();
		N++;
	}

	N--;

	string temp_str;

	for (temp_str; Input >> temp_str;)
		word += temp_str;
	
	length = word.length();

	reachable[0] = true;

	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j <= length; j++)
		{
			for (int l = 0; l < N; l++)
			{
				if (check(l, j))
				{
					if(reachable[j])
						reachable[j + lengths[l]] = true;
				}
			}
		}
	}

	for (int i = length; i >= 0; i--)
	{
		if (reachable[i])
		{
			Output << i << endl;
			break;
		}
	}

	return 0;
}