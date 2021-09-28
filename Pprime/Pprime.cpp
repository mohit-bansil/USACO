/*
ID: paradox4
PROG: pprime
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

int A, B;

bool isPrime(int n)
{
	if (n % 2 == 0)
		return false;

	for (int i = 3; i < sqrt(n) + 1; i += 2)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

void palindromeOne(ofstream& Output)
{
	if (A > 10)
		return;

	int palindrome;

	for (int i = 1; i < 10; i += 2)
	{
		palindrome = i;

		if (palindrome >= A && palindrome <= B)
			if (isPrime(palindrome))
				Output << palindrome << endl;

	}
}

void palindromeThree(ofstream& Output)
{
	if (A > 1000 || B < 100)
		return;

	int palindrome;

	for (int i = 1; i < 10; i += 2)
	{
		for (int j = 0; j < 10; j++)
		{
			palindrome = 101*i + 10*j;

			if (palindrome >= A && palindrome <= B)
				if (isPrime(palindrome))
					Output << palindrome << endl;
		}
	}
}

void palindromeFive(ofstream& Output)
{
	if (A > 100000 || B < 10000)
		return;

	int palindrome;

	for (int i = 1; i < 10; i += 2)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				palindrome = 10001 * i + 1010 * j + 100*k;

				if (palindrome >= A && palindrome <= B)
					if (isPrime(palindrome))
						Output << palindrome << endl;
			}
		}
	}
}

void palindromeSeven(ofstream& Output)
{
	if (A > 10000000 || B < 1000000)
		return;

	int palindrome;

	for (int i = 1; i < 10; i += 2)
	{
		if (i == 5)
			continue;

		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				for (int l = 0; l < 10; l++)
				{
					palindrome = 1000001 * i + 100010 * j + 10100 * k + 1000 * l;

					if (palindrome >= A && palindrome <= B)
						if (isPrime(palindrome))
							Output << palindrome << endl;
				}
			}
		}
	}
}

int main()
{
	ifstream Input("pprime.in");
	ofstream Output("pprime.out");

	Input >> A >> B;

	palindromeOne(Output);

	if (A <= 11 && B >= 11)
		Output << 11 << endl;

	palindromeThree(Output);
	palindromeFive(Output);
	palindromeSeven(Output);

	return 0;
}


/*
int primes[2514560];
int noOfPrimes = 0;

void palindrome(ofstream& Output)
{
int n;
int number;

for (int digits = 1; digits < 10; digits += 2)
{
n = digits / 2;

for (int i = pow(10, n - 1); i < pow(10, n); i++)
{
for (int j = 0; j < 10; j++)
{
number = (pow(10, n + 1) + 1) * i + pow(10, n) * j;
if (isPrime(number))
Output << number << endl;
}
}
}
}

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

string numberToString(int number)
{

string answer = "";

int digit;

while (number > 0)
{
answer = digitToChar(number % 10) + answer;
number /= 10;
}

return answer;
}

bool binarySearch(int x)
{
int low = 0, mid, high = noOfPrimes;

while (high >= low)
{
mid = (low + high) / 2;

if (primes[mid] == x)
return true;
else if (primes[mid] > x)
high = mid - 1;
else
low = mid + 1;
}

return false;
}

void findPrimes()
{
primes[0] = 2;
noOfPrimes++;

bool isPrime;

for (int i = 3; i <= B; i += 2)
{
isPrime = true;

for (int j = 0; primes[j] <= sqrt(i); j++)
{
if (i % primes[j] == 0)
{
isPrime = false;
break;
}
}

if (isPrime)
{
primes[noOfPrimes] = i;
noOfPrimes++;
}
}
}

void solve(ofstream& Output)
{
int i;

for (i = 0; primes[i] < A; i++);

for (i; i < noOfPrimes; i++)
{
if (isPalindrome(numberToString(primes[i])))
Output << primes[i] << endl;
}
}
*/