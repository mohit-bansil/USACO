/*
ID: paradox4
PROG: crypt1
LANG: C++11
*/

#include<iostream>
#include<fstream>
//#include<string>
//#include<sstream>

using namespace std;

int digits[9];

bool isGood3(int number, int N)
{
	int digit;

	digit = number / 100;
	number -= digit * 100;

	for (int k = 0; k < N; k++)
		{
			if (digit == digits[k])
				break;
			if (k == N - 1)
				return false;
		}
	
	digit = number / 10;
	number -= digit * 10;

	for (int k = 0; k < N; k++)
	{
		if (digit == digits[k])
			break;
		if (k == N - 1)
			return false;
	}

	for (int k = 0; k < N; k++)
	{
		if (number == digits[k])
			break;
		if (k == N - 1)
			return false;
	}

	return true;
}

bool isGood4(int number, int N)
{
	int digit;

	digit = number / 1000;
	number -= digit * 1000;

	for (int k = 0; k < N; k++)
	{
		if (digit == digits[k])
			break;
		if (k == N - 1)
			return false;
	}

	digit = number / 100;
	number -= digit * 100;

	for (int k = 0; k < N; k++)
	{
		if (digit == digits[k])
			break;
		if (k == N - 1)
			return false;
	}

	digit = number / 10;
	number -= digit * 10;

	for (int k = 0; k < N; k++)
	{
		if (digit == digits[k])
			break;
		if (k == N - 1)
			return false;
	}

	for (int k = 0; k < N; k++)
	{
		if (number == digits[k])
			break;
		if (k == N - 1)
			return false;
	}

	return true;
}

/*int charToInt(char a)
{
	return a - '0';
}*/

bool isGoodNumbers(int a, int b, int c, int N)
{
	if (a*b >= 1000 || a*c >= 1000 || a*(10*b+c) >= 10000)
		return false;

	bool bool1;

	bool1 = isGood3(a*b, N);
	if (!bool1)
		return false;
	bool1 = isGood3(a*c, N);
	if (!bool1)
		return false;
	bool1 = isGood4(a*(10 * b + c), N);
	if (!bool1)
		return false;

	return true;
}

int main()
{
	ifstream Input("crypt1.in");
	ofstream Output("crypt1.out");
	
	int N;

	Input >> N;

	for (int i = 0; i < N; i++)
		Input >> digits[i];

	int a;

	int answer = 0;

	for (int a1 = 0; a1 < N; a1++)
	{
		for (int a2 = 0; a2 < N; a2++)
		{
			for (int a3 = 0; a3 < N; a3++)
			{
				for (int a4 = 0; a4 < N; a4++)
				{
					for (int a5 = 0; a5 < N; a5++)
					{
						a = 100 * digits[a1] + 10 * digits[a2] + digits[a3];
						if (isGoodNumbers(a, digits[a4], digits[a5], N))
							answer++;
					}
				}
			}
		}
	}

	Output << answer << endl;

	return 0;
}