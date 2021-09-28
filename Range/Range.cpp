/*
ID: paradox4
PROG: range
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::string;

int N;

string board[250];

bool check(int a, int b)
{
	if (board[a][b] == '0')
		return false;
	if (board[a + 1][b] == '0')
		return false;
	if (board[a][b+1] == '0')
		return false;
	if (board[a+1][b+1] == '0')
		return false;

	return true;
}

int main()
{
	ifstream Input("range.in");
	ofstream Output("range.out");

	Input >> N;

	for (int i = 0; i < N; i++)
		Input >> board[i];

	int count;

	for (int s = 2; s <= N; s++)
	{
		count = 0;
		
		for (int i = 0; i < N - s + 1; i++)
		{
			for (int j = 0; j < N - s + 1; j++)
			{
				if (check(i, j))
				{
					count++;
					board[i][j] = '1';
				}

				else
					board[i][j] = '0';
			}
		}

		if (count != 0)
			Output << s << " " << count << endl;

	}

	return 0;
}

