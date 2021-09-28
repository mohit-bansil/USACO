/*
ID: paradox4
PROG: fact4
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int N;

int check[5000][2];

int main()
{
	ifstream Input;
	ofstream Output;

	Input.open("fact4.in");
	Output.open("fact4.out");

	Input >> N;

	int answer = 1;

	int twos = 0;

	int temp;

	for (int i = 2; i <= N; i++)
	{
		temp = i;

		while (temp % 2 == 0)
		{
			temp /= 2;
			twos++;
		}

		while (temp % 5 == 0)
		{
			temp /= 5;
			twos--;
		}

		answer *= temp;
		answer %= 10;

		check[i][0] = answer;
		check[i][1] = twos;
	}

	twos %= 4;

	if (twos == 0 && N != 1)
		twos = 4;

	answer *= pow(2, twos);

	answer %= 10;

	Output << answer << endl;
	
	return 0;
}