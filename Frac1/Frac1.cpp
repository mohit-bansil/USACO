/*
ID: paradox4
PROG: frac1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int N;

struct fraction
{
	int num;
	int den;
};

bool order(fraction a, fraction b)
{
	if ((double)a.num / a.den < (double)b.num / b.den)
		return true;
	else
		return false;
}

bool relativelyPrime(int a, int b)
{
	while (true)
	{
		if (a == 1 || b == 1)
			return true;
		if (a == 0 || b == 0)
			return false;

		if (a > b)
			a = a % b;
		else
			b = b % a;

	}
}

int main()
{
	ifstream Input("frac1.in");
	ofstream Output("frac1.out");

	Input >> N;

	fraction fractions[10000];

	fractions[0].num = 0;
	fractions[0].den = 1;

	int counter = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (relativelyPrime(i, j))
			{
				fractions[counter].num = j;
				fractions[counter].den = i;
				counter++;
			}
		}
	}

	sort(fractions, fractions + counter, order);

	for (int i = 0; i < counter; i++)
		Output << fractions[i].num << "/" << fractions[i].den << endl;

	return 0;
}