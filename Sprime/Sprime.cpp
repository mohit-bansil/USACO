/*
ID: paradox4
PROG: sprime
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

int N;

bool isPrime(int n)
{
	if (n % 2 == 0)
		return false;

	for (int i = 3; i*i <= n; i += 2)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

bool isSuperprime(string n)
{
	for (int i = 2; i <= N; i++)
	{
		if (!isPrime(stoi(n.substr(0, i))))
			return false;
	}

	return true;
}

void recurse(int currentDigits, string number, ofstream& Output)
{
	if (currentDigits == N)
	{
		if (isSuperprime(number))
			Output << number << endl;

		return;
	}
		
	recurse(currentDigits + 1, number + '1', Output);
	recurse(currentDigits + 1, number + '3', Output);
	recurse(currentDigits + 1, number + '7', Output);
	recurse(currentDigits + 1, number + '9', Output);

}

int main()
{
	ifstream Input("sprime.in");
	ofstream Output("sprime.out");

	Input >> N;

	recurse(1, "2", Output);
	recurse(1, "3", Output);
	recurse(1, "5", Output);
	recurse(1, "7", Output);

	return 0;
}