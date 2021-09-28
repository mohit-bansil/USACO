/*
ID: paradox4
PROG: nuggets
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

const int SIZE = 300;
const int RUN = 15000000;

int N;

int hold[13];

bool pack[SIZE];

void intilize()
{
	for (int i = 0; i < SIZE; i++)
		pack[i] = false;
}

int answer;

int gcd(int a, int b)
{
	while (true)
	{
		a = abs(a);
		b = abs(b);

		if (a == 0 || b == 0)
		{
			cout << "An error has occured. Error Code: 1." << endl;
			return -1;
		}

		if (a == b)
			return a;

		if (a > b)
			a -= b;
		else
			b -= a;
	}
}

int main()
{
	ifstream Input("nuggets.in");
	ofstream Output("nuggets.out");

	Input >> N;
	
	for (int i = 0; i < N; i++)
		Input >> hold[i];

	int gcda = hold[0];

	for (int i = 1; i < N; i++)
		gcda = gcd(gcda, hold[i]);

	if (gcda != 1)
	{
		Output << 0 << endl;
		return 0;
	}

	pack[0] = true;

	for (int i = 0; i < RUN; i++)
	{
		if (pack[i % SIZE])
		{
			for (int j = 0; j < N; j++)
				pack[(i + hold[j]) % SIZE] = true;
		}

		else
			answer = i;

		pack[(i + 260) % SIZE] = false;
	}

	Output << answer << endl;

	return 0;
}