/*
ID: paradox4
PROG: dualpal
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

bool isPalindrome(string number)
{
	int size = number.size();

	for (int i = 0; i < (size / 2); i++)
	{
		if (number[i] != number[size - i - 1])
			return false;
	}

	return true;
}

char digitToChar(int digit)
{
	if (digit < 10)
		return '0' + digit;
	else
		return 'A' + digit - 10;
}

string baseChanger(int number, int base)
{
	int power;
	for (power = 0; pow(base, power) <= number; power++);
	
	power--;

	string answer = "";

	int digit;

	for (int i = power; i >= 0; i--)
	{
		digit = number / (pow(base, i));
		
		answer += digitToChar(digit);

		number -= digit * pow(base, i);
	}

	return answer;
}

int main()
{
	ifstream Input("dualpal.in");
	ofstream Output("dualpal.out");

	int N, S;
	Input >> N >> S;

	int outputCount = 0;
	int palindromeCount;

	for (int i = S + 1; outputCount < N; i++)
	{
		palindromeCount = 0;

		for (int k = 2; k <= 10; k++)
		{
			if (isPalindrome(baseChanger(i, k)))
				palindromeCount++;

			if (palindromeCount == 2)
			{
				Output << i << endl;
				outputCount++;
				break;
			}
		}
	}

	return 0;
}