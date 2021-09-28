/*
ID: paradox4
PROG: kimbits
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

unsigned long long N, L, I;

unsigned long long choose(int n, int k)
{
	if (k > n)
		return 0;
	if (k == n || k == 0)
		return 1;

	unsigned long long answer = n;

	for (int i = 1; i < k; i++)
	{
		answer *= n - i;
		answer /= i;
	}

	answer /= k;

	return answer;
}

//how many ways to put at most n pidgeons into k holes
unsigned long long atMost(int n, int k)
{
	unsigned long long answer = 1;

	for (int i = 1; i <= n; i++)
		answer += choose(k, i);

	return answer;
}

int main()
{
	ifstream Input;
	ofstream Output;

	Input.open("kimbits.in");
	Output.open("kimbits.out");

	Input >> N >> L >> I;
	
	string answer = string(N, '0');
	
	for (int i = 0; i < N; i++)
	{
		if (atMost(L, N - i - 1) < I)
		{
			answer[i] = '1';
			I -= atMost(L, N - i - 1);
			L--;
		}
	}

	Output << answer << endl;

	return 0;
}