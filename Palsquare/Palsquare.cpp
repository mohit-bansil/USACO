/*
ID: paradox4
PROG: palsquare
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
	ifstream Input("palsquare.in");
	ofstream Output("palsquare.out");

	int base;
	Input >> base;

	for (int i = 1; i <= 300; i++)
	{
		if (isPalindrome(baseChanger(i*i, base)))
			Output << baseChanger(i, base) << " " << baseChanger(i*i, base) << endl;
	}

	return 0;
}